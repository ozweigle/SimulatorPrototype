var robotconnection = robotconnection || {};

var connection = null;

var connectToRobot = function(server, port) {
    global_server_address = server;
    document.all.statusConnect.innerText = "Connecting to robot at " + server.innerText + ":" + port;
    
    document.all.statusConnect.innerText = "Trying to connect ...";
    connection = new ros.Bridge("ws://" + server + ":" + port);

    connection.onOpen = function (e) {
        document.all.statusConnect.innerText = "Connected to ROS " + server + ":" + port;
        //initListeners();
		connection.advertise('/webgui_data/brain_model_name', 'std_msgs/String');
		connection.advertise('/webgui_data/robot_model_name', 'std_msgs/String');
		connection.advertise('/webgui_data/env_model_name', 'std_msgs/String');
		connection.advertise('/webgui_data/trans_func_name', 'std_msgs/String');
		connection.advertise('/webgui_data/start_simulation', 'std_msgs/Bool');


        //connection.subscribe(map.onNewMap,         "/map_as_png");
        //connection.subscribe(map.onNewMapMetadata, "/map_metadata");
        //connection.subscribe(map.onNewPosition,    "/amcl_pose");

    };
    connection.onClose = function (e) {
        //enableMotors(false);
        document.all.statusConnect.innerText = "Connection closed";
    };
    connection.onError = function (e) {
        document.all.statusConnect.innerText = "Error!";
    };

}
