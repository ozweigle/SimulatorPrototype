<?php
$tmp_file_name = $_FILES['Filedata']['tmp_name'];
$upload_path = '/var/www/SimulatorPrototype/uploads/';
if(isset($_COOKIE['currentupload']) && isset($_COOKIE['modelname'])){ 
	$model_name = $_COOKIE['modelname'];
	$split_name=explode("\\", $model_name);
	if (count($split_name) > 0) {
		$filename = $split_name[count($split_name) - 1];
  		$dest_file_name = $upload_path.$_COOKIE['currentupload'].'_'.$filename;
  		move_uploaded_file($tmp_file_name, $dest_file_name);
	}
}
?>