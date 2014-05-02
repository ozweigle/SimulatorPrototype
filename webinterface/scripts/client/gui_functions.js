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
    element = document.getElementById(key).previousSibling.firstChild.firstChild;
	element.data = text;
};


function SetAllButtonFilenames() {
	
	// Wait untill upload items are loaded
	element = null;
	while (!element) {
		element = document.getElementById("upload_brain_model").previousSibling;
	}
    SetUploadButtonText("upload_brain_model", "Brain Model: ["+ ReadCookie("brain_model") +"]" );
    SetUploadButtonText("upload_robot_model", "Robot Model:  [" + ReadCookie("robot_model") +"]" );
    SetUploadButtonText("upload_env_model", "Environment Model: [" + ReadCookie("env_model") +"]" );
    SetUploadButtonText("upload_trans_func", "Transfer Function: [" + ReadCookie("trans_func") +"]" );
};

function InitUploadButtons() {
    $("#upload_brain_model").uploadFile({
		url:"upload.php",
		allowedTypes:"py",
		fileName:"myfile",
		onSuccess:function(files,data,xhr) {
			$("#statusBar").html("Brain Model upload sucessful: " + files );
			WriteCookie("brain_model", files);
            SetAllButtonFilenames();
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
		}
	});
}