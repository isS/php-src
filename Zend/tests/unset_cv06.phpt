--TEST--
unset() CV 6 (indirect unset() of global variable in session_unset())
--SKIPIF--
<?php include('../../ext/session/tests/skipif.inc'); ?>
--INI--
register_globals=1
--FILE--
<?php
$x = "1\n";
session_start();
echo $x;
session_register('x');
$_SESSION['x'] = "2\n";
echo $x;
session_unset();
echo $x;
echo "ok\n";
?>
--EXPECTF--
1
2

Notice: Undefined variable: x in %sunset_cv06.php on line %d
ok
