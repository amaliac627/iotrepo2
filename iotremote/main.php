<?php
$q = $_REQUEST["q"];

if ($q !== "") {
    $dataFileObj = fopen("bot.txt", "w") or die("Unable to open file");
    fwrite($dataFileObj, $q);
    fclose($dataFileObj);
  }
?>