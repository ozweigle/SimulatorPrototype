<?php
//If directory doesnot exists create it.

$output_dir = "uploads/";

if(!is_writable($output_dir))
{
	header("HTTP/1.1 500 Server error: The directory  '" . $output_dir . "'  must be writable to the group www-data. Use: '$ sudo chown www-data uploads'");
	header('Content-Type: application/json; charset=UTF-8');
	die(json_encode(array('message' => 'ERROR', 'code' => 100)));
}
	
if(isset($_FILES["myfile"]))
{
	$ret = array();

	$error =$_FILES["myfile"]["error"];
	{
    	if(!is_array($_FILES["myfile"]['name'])) //single file
    	{
       	 	$fileName = $_FILES["myfile"]["name"];
       	 	move_uploaded_file($_FILES["myfile"]["tmp_name"],$output_dir. $_FILES["myfile"]["name"]);
       	 	// echo "<br> Error: ".$_FILES["myfile"]["error"];
       	 	 
	       	 	 $ret[$fileName]= $output_dir.$fileName;
    	}
    	else
    	{
    	    	$fileCount = count($_FILES["myfile"]['name']);
    		  for($i=0; $i < $fileCount; $i++)
    		  {
    		  	$fileName = $_FILES["myfile"]["name"][$i];
	       	 	 $ret[$fileName]= $output_dir.$fileName;
    		    move_uploaded_file($_FILES["myfile"]["tmp_name"][$i],$output_dir.$fileName );
    		  }
    	
    	}
    }
    echo json_encode($ret);
 
}

?>