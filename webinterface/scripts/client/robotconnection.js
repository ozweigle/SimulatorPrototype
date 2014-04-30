var robotconnection = robotconnection || {};

var connection = null;

var connectToRobot = function(server, port) {
    global_server_address = server;
    document.all.statusConnect.innerText = "Connecting to robot at " + server.innerText + ":" + port;
    
    document.all.statusConnect.innerText = "Trying to connect ...";
    connection = new ROSLIB.Ros({
                                    url : "ws://" + server + ":" + port
                                });

    connection.on('connection', function() {
                      document.all.statusConnect.innerText = "Connected to ROS " + server + ":" + port;

                      //now register the topics
                      registerTopics();

                  });
    connection.on('close', function() {
                      document.all.statusConnect.innerText = "Connection closed";
                  });
    connection.on('error', function() {
                      document.all.statusConnect.innerText = "Error!";
                  });

}

var registerTopics = function() {
    brain_model = new ROSLIB.Topic({
                                       ros : connection,
                                       name : '/webgui_data/brain_model_name',
                                       messageType : 'std_msgs/String'
                                   });

    robot_model = new ROSLIB.Topic({
                                       ros : connection,
                                       name : '/webgui_data/robot_model_name',
                                       messageType : 'std_msgs/String'
                                   });

    env_model = new ROSLIB.Topic({
                                     ros : connection,
                                     name : '/webgui_data/env_model_name',
                                     messageType : 'std_msgs/String'
                                 });

    start_sim = new ROSLIB.Topic({
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
