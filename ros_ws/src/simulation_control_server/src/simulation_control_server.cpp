#include <ros/ros.h>
#include <cstdlib>
#include <std_msgs/String.h>
#include <simulation_control_server/SimulationControl.h>


class SimulationControlServer
{
public:
    SimulationControlServer(ros::NodeHandle* node_ptr);

    static void nodeControl(const simulation_control_server::SimulationControlConstPtr& control_msg);
    static void simulationStart(const std_msgs::BoolConstPtr& start_msg);
    static void setRobotModel(const std_msgs::StringConstPtr& robot_model_msg);
    static void setBrainModel(const std_msgs::StringConstPtr& brain_model_msg);
    static void setEnvModel(const std_msgs::StringConstPtr& env_model_msg);


private:
    static ros::NodeHandle* node_ptr_;
    static std::string upload_path;
};

ros::NodeHandle* SimulationControlServer::node_ptr_ = NULL;
std::string SimulationControlServer::upload_path = "/home/ozweigle1/HBP/SimulatorWebPrototype/uploads/";

SimulationControlServer::SimulationControlServer(ros::NodeHandle* node_ptr)
{
    node_ptr_ = node_ptr;

    ROS_INFO("SimulationControlServer successfully started");
}

void SimulationControlServer::nodeControl(const simulation_control_server::SimulationControlConstPtr& control_msg) {
    std::string param_name_run = "/" + control_msg->name.data + "_run";
    std::string param_name_shutdown = "/" + control_msg->name.data + "_shutdown";
    node_ptr_->setParam(param_name_run, (bool)control_msg->run.data);
    node_ptr_->setParam(param_name_shutdown, (bool)control_msg->shut_down.data);

    ROS_INFO("The node %s will be set to state %d", control_msg->name.data.c_str(), control_msg->run.data);
    if (control_msg->shut_down.data)
        ROS_INFO("The node %s will be set shut down", control_msg->name.data.c_str());

}

void SimulationControlServer::simulationStart(const std_msgs::BoolConstPtr& start_msg) {
    ROS_INFO("Trying to start stage...");
    std::string kill_command_stage = "killall -9 stageros";
    system(kill_command_stage.c_str());
    std::string kill_command_mapping = "killall -9 slam_gmapping";
    system(kill_command_mapping.c_str());

    std::string env_model, brain_model;
    if (node_ptr_->getParam("/simulator_config/env_model", env_model) && node_ptr_->getParam("/simulator_config/brain_model", brain_model)) {
        std::string start_command = "rosrun stage_ros stageros " + env_model + " &";
        system(start_command.c_str());
        sleep(3);
        std::string start_command_mapping = "rosrun gmapping slam_gmapping scan:=base_scan &";
        //system(start_command_mapping.c_str());
        std::string start_brain_simulation = "python " + brain_model;
        system (start_brain_simulation.c_str());
    }

}

void SimulationControlServer::setRobotModel(const std_msgs::StringConstPtr& robot_model_msg) {
    std::string robot_model_file = upload_path + robot_model_msg->data;
    node_ptr_->setParam("/simulator_config/robot_model", robot_model_file);
}

void SimulationControlServer::setBrainModel(const std_msgs::StringConstPtr& brain_model_msg) {
    std::string brain_model_file = upload_path + brain_model_msg->data;
    node_ptr_->setParam("/simulator_config/brain_model", brain_model_file);
}

void SimulationControlServer::setEnvModel(const std_msgs::StringConstPtr& env_model_msg) {
    std::string env_model_file = upload_path + env_model_msg->data;
    node_ptr_->setParam("/simulator_config/env_model", env_model_file);
}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "node_control_server");
    ros::NodeHandle nh;
    ros::NodeHandle* node_ptr = &nh;

    ros::Subscriber nodeControlCmdSub_ =
            nh.subscribe<simulation_control_server::SimulationControl>("NodeControlServer/nodeControl", 1,
                                                           SimulationControlServer::nodeControl);

    ros::Subscriber startSimulatorCmdSub_ =
            nh.subscribe<std_msgs::Bool>("webgui_data/start_simulation", 1,
                                                           SimulationControlServer::simulationStart);

    ros::Subscriber getRobotModelCmdSub_ =
            nh.subscribe<std_msgs::String>("/webgui_data/robot_model_name", 1,
                                                           SimulationControlServer::setRobotModel);

    ros::Subscriber getBrainModelCmdSub_ =
            nh.subscribe<std_msgs::String>("/webgui_data/brain_model_name", 1,
                                                           SimulationControlServer::setBrainModel);

    ros::Subscriber getEnvModelCmdSub_ =
            nh.subscribe<std_msgs::String>("/webgui_data/env_model_name", 1,
                                                           SimulationControlServer::setEnvModel);



    //ros::ServiceServer service_plan = nh.advertiseService("NodeControlServer/nodeControl", NodeControlServer::executeCommand);

    SimulationControlServer SimulationControlServer(node_ptr);

    ros::spin();
}


