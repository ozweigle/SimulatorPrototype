var robotconnection = robotconnection || {};

var connection = null;

var connectToRobot = function(server, port) {
    global_server_address = server;
     var statusConnect = document.getElementById('statusConnect');
    statusConnect.innerText = "Connecting to robot at " + server.innerText + ":" + port;
    
    statusConnect.innerText = "Trying to connect ...";
    connection = new ROSLIB.Ros({
                                    url : "ws://" + server + ":" + port
                                });

    connection.on('connection', function() {
                      statusConnect.innerText = "Connected to ROS " + server + ":" + port;

                      //now register the topics
                      registerTopics();

                  });
    connection.on('close', function() {
                      statusConnect.innerText = "Connection closed";
                  });
    connection.on('error', function() {
                      statusConnect.innerText = "Error!";
                  });

}

var registerTopics = function() {
    topic_brain_model = new ROSLIB.Topic({
                                       ros : connection,
                                       name : '/webgui_data/brain_model_name',
                                       messageType : 'std_msgs/String'
                                   });

    topic_robot_model = new ROSLIB.Topic({
                                       ros : connection,
                                       name : '/webgui_data/robot_model_name',
                                       messageType : 'std_msgs/String'
                                   });

    topic_env_model = new ROSLIB.Topic({
                                     ros : connection,
                                     name : '/webgui_data/env_model_name',
                                     messageType : 'std_msgs/String'
                                 });

    topic_start_sim = new ROSLIB.Topic({
                                     ros : connection,
                                     name : '/webgui_data/start_simulation',
                                     messageType : 'std_msgs/Bool'
                                 });
    console.log('Registered Topics successfully');
}

var publishOnTopic = function(topic_handler, msg_json) {
    var rosmsg = new ROSLIB.Message(msg_json);
    topic_handler.publish(rosmsg);
}
