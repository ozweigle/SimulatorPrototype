var gui_functions = gui_functions || {};

function transferFunctionCallback(result) {
    var error_string = result.error_string;
    var success = result.success;
    console.log(success);
    if (success) {
        alert('Upload and model check successful');
    }
    else {
        alert('Upload and model check failed. Reason: \n' + error_string);
    }
};

function SetUploadButtonText(key, text) {
	// Wait untill upload items are loaded
	element = null;
	element = document.getElementById(key+"_file");
	element.firstChild.data = text;
};


function SetAllButtonFilenames() {
    SetUploadButtonText("Brain Model", ReadCookie("brain_model") );
    SetUploadButtonText("Robot Model", ReadCookie("robot_model") );
    SetUploadButtonText("Environment Model", ReadCookie("env_model") );
    SetUploadButtonText("Transfer Function", ReadCookie("trans_func")  );
};

function InitUploadButtons() {
    $("#upload_brain_model").uploadFile({
		url:"upload.php",
		allowedTypes:"py",
		fileName:"myfile",
		currentFile:ReadCookie("brain_model"),
		onSuccess:function(files,data,xhr) {
			$("#statusBar").html("Brain Model upload sucessful: " + files );
			WriteCookie("brain_model", files);
            SetAllButtonFilenames();
			try {
				publishOnTopic(topic_brain_model, {data: brain_file});
			} catch (err) {};
		}
	});

	$("#upload_robot_model").uploadFile({
		url:"upload.php",
		allowedTypes:"urdf,env",
		fileName:"myfile",
		onSuccess:function(files,data,xhr) {
			$("#statusBar").html("Robot Model upload sucessful: " + files );
			WriteCookie("robot_model", files);
            SetAllButtonFilenames();
			try {
				publishOnTopic(topic_robot_model, {data: robot_file});
			} catch (err) {};
		}
	});
		
	$("#upload_env_model").uploadFile({
		url:"upload.php",
		allowedTypes:"world,dae",
		fileName:"myfile",
			onSuccess:function(files,data,xhr) {
			$("#statusBar").html("Environment Model upload sucessful: " + files );
			WriteCookie("env_model", files);
            SetAllButtonFilenames();
			try {
				publishOnTopic(topic_env_model, {data: env_file});
			} catch (err) {}
		}
	});
		
	$("#upload_trans_func").uploadFile({
		url:"upload.php",
		allowedTypes:"py",
		fileName:"myfile",
		onSuccess:function(files,data,xhr) {
			$("#statusBar").html("Transfer Function upload sucessful: " + files );
			WriteCookie("trans_func", files);
            SetAllButtonFilenames();
			try {
				setTransferFunctionService(trans_file, transferFunctionCallback);
			} catch (err) {}
		}
	});
}