var upload_functions = upload_functions || {};

function registerUploadFunctions() {
    var upload_robot_model = document.getElementById('upload_robot_model');
    upclick(
                {
                    element: upload_robot_model,
                    action: 'scripts/server/after_upload.php',
                    onstart:
                    function(filename)
                    {
                        var split_string = filename.split("\\");
                        current_filename = "ROBOT_" + split_string[split_string.length - 1];
                        document.cookie = 'currentupload=ROBOT';
                        document.cookie = 'modelname='+filename;
                        alert('Start upload ROBOT_MODEL: ' + current_filename);
                    },
                    oncomplete:
                    function(response_data)
                    {
                        publishOnTopic(robot_model, {data: current_filename});
                        alert('File has been successfully uploaded');
                    }
                });

    var upload_brain_model = document.getElementById('upload_brain_model');
    upclick(
                {
                    element: upload_brain_model,
                    action: 'scripts/server/after_upload.php',
                    onstart:
                    function(filename)
                    {
                        var split_string = filename.split("\\");
                        current_filename = "BRAIN_" + split_string[split_string.length - 1];
                        document.cookie = 'currentupload=BRAIN';
                        document.cookie = 'modelname='+filename;
                        alert('Start uploading BRAIN_MODEL: ' + current_filename);
                    },
                    oncomplete:
                    function(response_data)
                    {
                        publishOnTopic(brain_model, {data: current_filename});
                        alert('File has been successfully uploaded');
                    }
                });

    var upload_env_model = document.getElementById('upload_env_model');
    upclick(
                {
                    element: upload_env_model,
                    action: 'scripts/server/after_upload.php',
                    onstart:
                    function(filename)
                    {
                        var split_string = filename.split("\\");
                        current_filename = "ENV_" + split_string[split_string.length - 1];
                        document.cookie = 'currentupload=ENV';
                        document.cookie = 'modelname='+filename;
                        alert('Start uploading ENV_MODEL: '+ current_filename);
                    },
                    oncomplete:
                    function(response_data)
                    {
                        publishOnTopic(env_model, {data: current_filename});
                        alert('File has been successfully uploaded');
                    }
                });

    var upload_trans_func = document.getElementById('upload_trans_func');
    upclick(
                {
                    element: upload_trans_func,
                    action: 'scripts/server/after_upload.php',
                    onstart:
                    function(filename)
                    {
                        var split_string = filename.split("\\");
                        current_filename = "TF_" + split_string[split_string.length - 1];
                        document.cookie = 'currentupload=TF';
                        document.cookie = 'modelname='+filename;
                        alert('Start uploading TRANS_FUNC: '+ current_filename);
                    },
                    oncomplete:
                    function(response_data)
                    {
                        setTransferFunctionService(current_filename, transferFunctionCallback);
                    }
                });
};
