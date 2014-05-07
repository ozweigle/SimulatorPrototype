#include <ros/ros.h>
#include <cstdlib>
#include <std_msgs/String.h>
#include <simulation_control_server/SimulationControl.h>
#include <simulation_control_server/StartSimulation.h>
#include <simulation_control_server/SetTransferFunction.h>
#include <gazebo_msgs/SpawnModel.h>

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>


class SimulationControlServer
{
public:
    SimulationControlServer(ros::NodeHandle* node_ptr);

    static void nodeControl(const simulation_control_server::SimulationControlConstPtr& control_msg);
    static void simulationStart(const std_msgs::BoolConstPtr& start_msg);
    static void setRobotModel(const std_msgs::StringConstPtr& robot_model_msg);
    static void setBrainModel(const std_msgs::StringConstPtr& brain_model_msg);
    static void setEnvModel(const std_msgs::StringConstPtr& env_model_msg);
    static bool setTransFunc(simulation_control_server::SetTransferFunction::Request &req,
                             simulation_control_server::SetTransferFunction::Response &res);
    static bool spawnRobotFile();


private:
    static ros::NodeHandle* node_ptr_;
    static std::string upload_path;

    static std::string executeCommand(std::string cmd);
    static bool fileExists(const std::string& name);
    static bool readFileToString(std::string& contents, const std::string& name);
};

ros::NodeHandle* SimulationControlServer::node_ptr_ = NULL;
std::string SimulationControlServer::upload_path = "/var/www/SimulatorPrototype/uploads/";

SimulationControlServer::SimulationControlServer(ros::NodeHandle* node_ptr)
{
    node_ptr_ = node_ptr;

    if (!node_ptr_->getParam("/simulation_control_server/web_config/upload_path", upload_path)) {
        ROS_ERROR("No properly defined upload path for models. Please check this issue...");
    }

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

    std::string env_model, brain_model, trans_func;
    if (node_ptr_->getParam("/simulator_config/env_model", env_model) && node_ptr_->getParam("/simulator_config/brain_model", brain_model) &&
            node_ptr_->getParam("/simulator_config/trans_func", trans_func) ) {
        //std::string start_command = "rosrun stage_ros stageros " + env_model + " &";
        //system(start_command.c_str());
        spawnRobotFile();
        sleep(3);
        std::string start_transfer_function = "python " + trans_func + " &";
        system(start_transfer_function.c_str());
        //std::string start_command_mapping = "rosrun gmapping slam_gmapping scan:=base_scan &";
        //system(start_command_mapping.c_str());
        std::string start_brain_simulation = "python " + brain_model;
        system(start_brain_simulation.c_str());
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

bool SimulationControlServer::setTransFunc(simulation_control_server::SetTransferFunction::Request &req,
                                           simulation_control_server::SetTransferFunction::Response &res) {
    std::string trans_func_file = upload_path + req.transfer_function_name;
    //check if uploaded file really exists
    if (fileExists(trans_func_file)) {
        //now run a syntax test using cython
        std::string test_command = "cython --embed " + trans_func_file + " -o /tmp/test.c";
        std::string cython_return = executeCommand(test_command);
        if (cython_return == "") {
            res.success = true;
            node_ptr_->setParam("/simulator_config/trans_func", trans_func_file);
            ROS_ERROR("Success");
        }
        else {
            std::string error_string = "The following error was encountered in the TransferFunction file: \n " + cython_return;
            res.success = false;
            res.error_string = error_string;
            ROS_ERROR(error_string.c_str());
        }
    }
    else {
        res.success = false;
        res.error_string = "File upload failed";
    }

    return true;
}

bool SimulationControlServer::spawnRobotFile() {
    std::string robot_model_file;
    if (node_ptr_->getParam("/simulator_config/robot_model", robot_model_file)) {
        if (fileExists(robot_model_file)) {
            std::string robot_model;
            if (readFileToString(robot_model, robot_model_file)) {
                std::cout << "RobotModel:" << robot_model << std::endl;
                ros::ServiceClient client = node_ptr_->serviceClient<gazebo_msgs::SpawnModel>("/gazebo/spawn_sdf_model");
                gazebo_msgs::SpawnModel spawn_srv;
                spawn_srv.request.model_name = "husky";
                spawn_srv.request.model_xml = robot_model;
                if (client.call(spawn_srv)) {
                    return spawn_srv.response.success;
                }
            }
        }

    }
}

std::string SimulationControlServer::executeCommand(std::string cmd) {
    std::string data;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream) {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
        pclose(stream);
    }
    return data;
}

bool SimulationControlServer::fileExists(const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

bool SimulationControlServer::readFileToString(std::string& contents, const std::string& name) {
    std::ifstream in(name.c_str());
    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string temp_contents(buffer.str());
    contents = temp_contents;
    return true;
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

    //ros::ServiceServer startSimulatorSrv = nh.advertiseService("/simulation_control_server/startSimulation", SimulationControlServer)

    ros::Subscriber getRobotModelCmdSub_ =
            nh.subscribe<std_msgs::String>("/webgui_data/robot_model_name", 1,
                                                           SimulationControlServer::setRobotModel);

    ros::Subscriber getBrainModelCmdSub_ =
            nh.subscribe<std_msgs::String>("/webgui_data/brain_model_name", 1,
                                                           SimulationControlServer::setBrainModel);

    ros::Subscriber getEnvModelCmdSub_ =
            nh.subscribe<std_msgs::String>("/webgui_data/env_model_name", 1,
                                                           SimulationControlServer::setEnvModel);

    //ros::Subscriber getTransFuncCmdSub_ =
    //            nh.subscribe<std_msgs::String>("/webgui_data/trans_func_name", 1,
    //                                                           SimulationControlServer::setTransFunc);

    ros::ServiceServer setTransferFunctionSrv = nh.advertiseService("/simulation_control_server/set_transfer_function", SimulationControlServer::setTransFunc);




    //ros::ServiceServer service_plan = nh.advertiseService("NodeControlServer/nodeControl", NodeControlServer::executeCommand);

    SimulationControlServer SimulationControlServer(node_ptr);

    ros::spin();
}


