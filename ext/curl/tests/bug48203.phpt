--TEST--
Bug #48203 (Crash when file pointers passed to curl are closed before calling curl_exec)
--SKIPIF--
<?php 
if (!extension_loaded("curl")) {
	exit("skip curl extension not loaded");
}
if (false === getenv('PHP_CURL_HTTP_REMOTE_SERVER'))  {
	exit("skip PHP_CURL_HTTP_REMOTE_SERVER env variable is not defined");
}
?>
--FILE--
<?php

function checkForClosedFilePointer($curl_option, $description) {
	$fp = fopen(dirname(__FILE__) . '/bug48203.tmp', 'w+');

	$ch = curl_init();

	// we also need CURLOPT_VERBOSE to be set to test CURLOPT_STDERR properly
	if (CURLOPT_STDERR == $curl_option) {
		curl_setopt($ch, CURLOPT_VERBOSE, 1);
	}

    if (CURLOPT_INFILE == $curl_option) {
        curl_setopt($ch, CURLOPT_UPLOAD, 1);
    }

	curl_setopt($ch, $curl_option, $fp);
	
	curl_setopt($ch, CURLOPT_URL, 'localhost');
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);

	fclose($fp); // <-- premature close of $fp caused a crash!

	curl_exec($ch);

	curl_close($ch);

	echo "Ok for $description\n";
}

$options_to_check = array(
	"CURLOPT_STDERR",
    "CURLOPT_WRITEHEADER",
    "CURLOPT_FILE",
    "CURLOPT_INFILE"
);

foreach($options_to_check as $option) {
	checkForClosedFilePointer(constant($option), $option);
}

?>
--CLEAN--
<?php @unlink(dirname(__FILE__) . '/bug48203.tmp'); ?>
--EXPECTF--
Warning: curl_exec(): %d is not a valid stream resource in %s on line %d

Warning: curl_exec(): CURLOPT_STDERR handle is incorrect in %s on line %d
* About to connect() %a
* Closing connection #%d
Ok for CURLOPT_STDERR

Warning: curl_exec(): %d is not a valid stream resource in %s on line %d

Warning: curl_exec(): CURLOPT_WRITEHEADER handle is incorrect in %s on line %d
Ok for CURLOPT_WRITEHEADER

Warning: curl_exec(): %d is not a valid stream resource in %s on line %d

Warning: curl_exec(): CURLOPT_FILE handle is incorrect in %s on line %d
%a
Ok for CURLOPT_FILE

Warning: curl_exec(): %d is not a valid stream resource in %s on line %d

Warning: curl_exec(): CURLOPT_INFILE handle is incorrect in %s on line %d
Ok for CURLOPT_INFILE
