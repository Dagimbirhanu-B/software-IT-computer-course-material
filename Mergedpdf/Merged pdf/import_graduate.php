<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link rel="stylesheet"  type="text/css" href="css/style_entry.css" />
<link rel="stylesheet" type="text/css" href="icon/css/solid.css">
<link rel="stylesheet" type="text/css" href="icon/css/fontawesome.min.css">
<link rel="stylesheet" type="text/css" href="icon/css/brands.css">
<style>
 /* Style for popup overlay */
    .overlay {
      position: fixed;
      top: 0;
      left: 0;
      width: 100%;
      height: 100%;
     background-color: rgba(0, 0, 0, 0.5);
	 //background-color:red;
      display: none;
    }

    /* Style for popup message box */
 .popup {
      position: fixed;
      top: 50%;
      left: 50%;
      transform: translate(-50%, -50%);
      background-color: #fff;
      padding: 20px;
      border-radius: 5px;
      box-shadow: 0 0 10px rgba(0, 0, 0, 0.5);
      text-align: center;
      display: none;
    }
	/* Style for close button */
    .close {
      position: absolute;
      top: 10px;
      right: 10px;
      font-size: 30px;
      font-weight: bold;
      color: red;
      cursor: pointer;
    }
</style>
</head>
<body>
<?php
//session_start();
if(isset($_SESSION['university']))
$university=$_SESSION['university'];
// Define MySQL database connection details
$servername = "localhost:3306";
$username = "root";
$password = "";
$dbname = "gcvs_db_success";

// Check if the form has been submitted
if(isset($_POST['submit'])) {

  // Get the CSV file name and temporary file location
  $csv_file = $_FILES['csv_file']['name'];
  $csv_temp = $_FILES['csv_file']['tmp_name'];

  // Check if the file is a CSV file
  $file_ext = pathinfo($csv_file, PATHINFO_EXTENSION);
  if($file_ext != "csv") {
   // echo "Error: Please upload a CSV file";
	echo "<script type=\"text/javascript\">
							alert(\"Error: Please upload a CSV file.\");
							window.location = \"main.php?tag=import_graduate\"
							  return;
						</script>";
  } else {

   

    // Connect to the MySQL database
    $conn = new mysqli($servername, $username, $password, $dbname);
$i=0;
$j=0;
 $row=0;
 $er=0;
//check if data in csv file is valid
$csv_handle2 = fopen($csv_temp, 'r');
 while (($csv_data2 = fgetcsv($csv_handle2, 1000, ",")) !== FALSE) {
		// select name from user where username is session jedhiiti university name kennif
		//$university="addis";
    	//$entry=date('Y-m-d H:i:s');
		//$sql = "INSERT INTO graduate (ID,Frist_Name,Midle_Name,Last_Name,Year_of_Graduation,Qualification,Gender,Department,University,GPA,entry_date)
      //VALUES ('" . $csv_data[0] . "', '" . $csv_data[1] . "', '" . $csv_data[2] . "', '" . $csv_data[3] . "', '" . $csv_data[4] . "' , '" . $csv_data[5] . "' , '" . $csv_data[6] . "', '" . $csv_data[7] . "', '" . $university. "', '" . $csv_data[9] . "', '" . $entry . "')";
      ++$row;
	  	  if($csv_data2[0]==""){
		  ++$er;
		 // $msp="You have left filling data in in csv file! frist name column  at row ".$row;
         // echo "<script type=\"text/javascript\">
		    //             var ms='$msp';
				//			alert(ms);
													
				//		</script>";
				//		exit;
						
				

echo'
<div class="overlay"></div>
<div class="popup" >
 <span class="close">&times;</span>

   <h1> <i class="fa fa-skull-crossbones" style="color:red;font-size:30px;"></i>  warning</h1>
      <hr> 
	 <p> you have missied filling Graduate ID column in csv file</p>';
 echo "At row ".$row;
 echo '</div>';




				
      }
	 else if($csv_data2[1]==""){
		  ++$er;
		 // $msp="You have left filling data in in csv file! frist name column  at row ".$row;
         // echo "<script type=\"text/javascript\">
		    //             var ms='$msp';
				//			alert(ms);
													
				//		</script>";
				//		exit;
						
				

echo'
<div class="overlay"></div>
<div class="popup" >
 <span class="close">&times;</span>

   <h1> <i class="fa fa-skull-crossbones" style="color:red;font-size:30px;"></i>  warning</h1>
      <hr> 
	 <p> you have missied filling Frist Name column in csv file</p>';
 echo "At row ".$row;
 echo '</div>';




				
      }
      else if($csv_data2[2]==""){
      	++$er;
		  echo'
<div class="overlay"></div>
<div class="popup" >
 <span class="close">&times;</span>

   <h1> <i class="fa fa-skull-crossbones" style="color:red;font-size:30px;"></i>  warning</h1>
      <hr> 
	 <p> you have missied filling Middle Name column in csv file</p>';
 echo "At row ".$row;
 echo '</div>';
         }
		 if($er==0){
			  // Open the CSV file for reading
       $csv_handle = fopen($csv_temp, 'r');
			 // Loop through the rows in the CSV file and insert them into the MySQL database
			 while (($csv_data = fgetcsv($csv_handle, 1000, ",")) !== FALSE) {
		// select name from user where username is session jedhiiti university name kennif
		//$university="addis";
		$gid=$csv_data[0];
		$s="select from graduate where ID='$gid'";
	$result = $conn->query($s);
// Check if the query was successful
if ($result) {
    // Get the number of rows
    $numRows = $result->num_rows;
}   if($numRows==0){
    	$entry=date('Y-m-d H:i:s');
		$sql = "INSERT INTO graduate (ID,Frist_Name,Midle_Name,Last_Name,Year_of_Graduation,Qualification,Gender,Department,University,GPA,entry_date)
      VALUES ('" . $csv_data[0] . "', '" . $csv_data[1] . "', '" . $csv_data[2] . "', '" . $csv_data[3] . "', '" . $csv_data[4] . "' , '" . $csv_data[5] . "' , '" . $csv_data[6] . "', '" . $csv_data[7] . "', '" . $university. "', '" . $csv_data[9] . "', '" . $entry . "')";
      if($conn->query($sql)){
      	++$i;
      }
      else{
      	++$j;
         }
    }//dhuma while kessa
			 }
			 else{
				 
				 // id dabalameera jedhi
			 }
	}//dhuma else if yoo Error hin jiranne
    
	
	}//dhuma while check
    
    
	
   
if($i!=0){
    // Display a success message
   echo'
<div class="overlay"></div>
<div class="popup" >
 <span class="close">&times;</span>

   <h1><i class="fa fa-solid fa-check" style="color:green;font-size:30px;"></i>  SUCCESS</h1>
      <hr> 
	'. $row.'<p> Gaduate data imported successfully from csv file</p>';
 //echo "At row ".$row;
 echo '</div>';
    
       }
  else if($i==0 && $j!=0){
       	echo "<script type=\"text/javascript\">
							alert(\"Eroor importing graduate data twice.\");
							window.location = \"main.php?tag=import_graduate\"
						</script>";
       }
	   
	  // fclose($csv_handle);
    $conn->close();

}
}

?>
<?php
//include('include/database_allgraduate.php');
$university=$_SESSION['university'];
$sql1="select ID from request where university ='$university'";
$r=mysqli_query($con,$sql1);
$id="";
while($row=mysqli_fetch_assoc($r)){
	$id=$row['ID'];
}
if(!$id==""){
$sql2="select * from response where request_id ='$id'";
$r2=mysqli_query($con,$sql2);
$rn=mysqli_num_rows($r2);
if($rn>=1){
$row=mysqli_fetch_assoc($r2);
	//$start=strtotime($row['start_date']);
	//$end=strtotime($row['end_date']);
$start=$row['start_date'];
	$end=$row['end_date'];

$today=date('Y-m-d');
if($end<$today){
	echo "<hr><h3 style='margin:30px; color:red;'>Your  Deadline was end ,so now you do not have permission to import please send request and get permission frist";
	echo "<a href='?tag=send_request'><button id='button-in' style='width:180px;'>SEND REQUEST</button></a></h3>";
}
else{
 ?>
<div id="top_style">
        <div id="top_style_text">
      <p style="margin-top:4px;padding-left:100px"><b> <i class="fa fa-plus-circle" aria-hidden="true"></i>&nbsp; Import Graduate From Csv File</b></p>
        </div><!-- end of top_style_text-->
       
</div><!-- end of top_style-->

<!-- Display the form to upload a CSV file -->


<br><br>
<div id="style_informations">
	<form method="post" enctype="multipart/form-data">
    <div>
   	  <table border="0" width="385px"  id="Reg_user"cellpadding="4" cellspacing="0">
	     
		<tr><td colspan="2"><label for="csv_file">Choose a CSV file:</label>
		</td></tr><tr><td>
		 <input type="file" id="csv_file" name="csv_file" >
		 <td><input type="submit" name="submit" value="Import" id="button-in">
		</td></tr>
			
			</table>
			</div>
			<div>
		  </table>
    </div>
 	
    </form>

</div><!-- end of style_informatios -->

<?php
}
}
else{
	echo "<hr><h3 style='margin:30px; color:red;'>Your Have not Given Deadline Yet ,so now you do not have permission to import please wait for response or again send request and get permission";
	echo "<a href='?tag=send_request'><button id='button-in' style='width:180px;'>SEND REQUEST</button></a></h3>";
}
}
else{
	echo "<hr><h3 style='margin:30px; color:red;'>You have not sent  any request for permission,so now you do not have permission to import please send request and get permission frist";
	echo "<a href='?tag=send_request'><button id='button-in' style='width:180px;'>SEND REQUEST</button></a></h3>";
}
?>




<script>

    // Show popup after 30 seconds
    setTimeout(function() {
      document.querySelector('.overlay').style.display = 'block';
      document.querySelector('.popup').style.display = 'block';
    }, 300); // 30000 milliseconds = 30 seconds
	 document.querySelector('.close').addEventListener('click', function() {
      document.querySelector('.overlay').style.display = 'none';
      document.querySelector('.popup').style.display = 'none';
	   	
    });
	
  </script>
</body>
</html>