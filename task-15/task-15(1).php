<?php
$connect=mysqli_connect('127.0.0.1','root','','test');
if(mysqli_connect_errno()){
die("can't connect") .mysqli_connect_error();}
?>

<!DOCTYPE html>
<html>
<head></head>
<body>
<?php

echo print_r($_POST);

if(isset($_POST["F"])){
	$query = "INSERT INTO `table` (`forward`, `right`, `left`, `reverse`, `stop`) VALUES ('f', NULL, NULL, NULL, NULL)";
	$result =mysqli_query($connect,$query);
}
elseif(isset($_POST["R"])){
	$query = "INSERT INTO `table` (`forward`, `right`, `left`, `reverse`, `stop`) VALUES (NULL,'r', NULL, NULL, NULL)";
	$result =mysqli_query($connect,$query);
}
elseif(isset($_POST["L"])){
	$query = "INSERT INTO `table` (`forward`, `right`, `left`, `reverse`, `stop`) VALUES (NULL, NULL,'l', NULL, NULL)";
	$result =mysqli_query($connect,$query);
}
elseif(isset($_POST["S"])){
	$query = "INSERT INTO `table` (`forward`, `right`, `left`, `reverse`, `stop`) VALUES (NULL, NULL, NULL, NULL,'s')";
	$result =mysqli_query($connect,$query);
}
elseif(isset($_POST["RV"])){
	$query = "INSERT INTO `table` (`forward`, `right`, `left`, `reverse`, `stop`) VALUES (NULL, NULL, NULL,'rv', NULL)";
	$result =mysqli_query($connect,$query);
}
	if($result){
	echo"successfully, insert into database";}
	else{
	echo "error, not insert" .mysqli_error($connect);
mysqli_close($connect);
}
?>

</body>
</html>







