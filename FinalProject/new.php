<?php
echo "E2302181 received your data!\n";
$remote = $_SERVER['REMOTE_ADDR'];
$uname = $_POST['max'];//$_POST['name'];
$proj = $_POST['min'];//$_POST['project'];
$efile = "mydata.txt";
$today = date("Y-m-d H:i:s");
$record = $today . ' ' . $uname . ' ' . $proj . ' ' . $remote . "\n";
if (file_exists($efile))
$fp = fopen($efile,"a");
else $fp = fopen($efile,"w");
fwrite($fp,$record);
fclose($efile);
echo "\nData stored!";
?>