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
