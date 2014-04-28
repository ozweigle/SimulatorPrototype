var roscommands = roscommands || {};

String.prototype.format = function()
        {
            var content = this;
            for (var i=0; i < arguments.length; i++)   {
                var replacement = '{' + i + '}';
                content = content.replace(replacement, arguments[i]);
            }
            return content;
        };

function callRemoteDebugService(serviceName, start_data_stream, data_stream) {
    arg_string = "[" + start_data_stream + ',"' + data_stream + '"]';
    //connection.publish("2", "2", "2");
    connection.callService(serviceName, arg_string, []);
}

function callRemoteStarter(serviceName, launchfile, node, ros_package, name, run) {
    //arg_string = "[" + launchfile + "," + node + ",\"" + ros_package + "\",\"" + name + "\"," + run + "]";
    arg_string = '[{0},{1},"{2}","{3}",{4}]'.format(launchfile, node, ros_package, name, run);
    document.all.statusBar.innerText = arg_string;

    connection.callService(serviceName, arg_string, []);
}

function enableMotors(enable) {
    if (enable) {
        sendMotorStartMessage();
    } else {
        sendMotorStopMessage();
    }
}

function publishCommand(topic,msg) {
	//document.all.statusBar.innerText ="HIER";
    if (connection !== null) {
        document.all.statusBar.innerText = msg;
        connection.publish(topic, msg);
    } else {
        document.all.statusBar.innerText = "No connection to ros " + msg;
    }
}

function sendDriveMessage (driveParameters) {
    publishCommand("/cmd_vel", {linear: {x: driveParameters[0], y:driveParameters[1], z: 0}, angular: {x:0,y:0,z:driveParameters[2]}});
}

function sendMotorStartMessage () {
    publishCommand("/rfcbot/drive_on", '{"data":1}');
}

function sendMotorStopMessage () {
    publishCommand("/rfcbot/drive_on", '{"data":0}');
}

function sendKinectMoveMessage(kinectMoveParameter) {
    var msg = '{"relative_mode":1,"angle":{0}}'.format(kinectMoveParameter);
    publishCommand("/kinect_motor/target_angle", msg);
}

function sendPlan(planname) {
    var msg = '{"data":"{0}"}'.format(planname);
    publishCommand("/plan_server/planName", msg);
}

function sendStartPlan() {
    log("Start plan N/A");

}

function sendStopPlan() {
    log("Stop plan N/A");
}

function sendInit() {
    log("Init N/A");
}

function sendDriveHome() {
    log("Drive home N/A");
}

function sendStartFaroScan() {
    log("Start faro Scan N/A");
}


function sendStartFollow() {
    log("Start Follow N/A");
}


function sendStopFollow() {
    log("Stop Follow N/A");
}


function sendPoses(poses) {
    publishCommand("/plan_server/planPoints", poses);
}

function log(message) {
    document.all.statusBar.innerText = message;
    console.log(message);
}

//{data: false},
//{data: true},
//{data: 'faro_bridge'},
//{data: 'faro_bridge_node'},
//{data: false}"

