--TEST--
Test array_map() function : usage variations - associative array with different values
--FILE--
<?php
/* Prototype  : array array_map  ( callback $callback  , array $arr1  [, array $...  ] )
 * Description: Applies the callback to the elements of the given arrays
 * Source code: ext/standard/array.c
 */

/*
 * Test array_map() by passing associative array with different values for $arr1 argument
 */

echo "*** Testing array_map() : associative array with diff. values for 'arr1' argument ***\n";

function callback($a)
{
  return ($a);
}
//get an unset variable
$unset_var = array(1, 2);
unset ($unset_var);

//get a resource variable
$fp = fopen(__FILE__, "r");

//get a class
class classA
{
  public function __toString(){
    return "Class A object";
  }
}

// get a heredoc string
$heredoc = <<<EOT
Hello world
EOT;

// initializing the array
$arrays = array (

       // empty array
/*1*/  array(),

       // arrays with integer values
       array('0' => 0),
       array("1" => 1),
       array("one" => 1, 'two' => 2, "three" => 3, 4 => 4),

       // arrays with float values
/*5*/  array("float" => 2.3333),
       array("f1" => 1.2, 'f2' => 3.33, 3 => 4.89999922839999, 'f4' => 33333333.3333),

       // arrays with string values
       array(111 => "\tHello", "red" => "col\tor", 2 => "\v\fworld", 3.3 =>  "pen\n"),
/*8*/  array(111 => '\tHello', "red" => 'col\tor', 2 => '\v\fworld', 3.3 =>  'pen\n'),
       array(1 => "hello", "heredoc" => $heredoc),

       // array with object, unset variable and resource variable
       array(11 => new classA(), "unset" => @$unset_var, "resource" => $fp),

       // array with mixed values
/*11*/ array(1 => 'hello', 2 => new classA(), 222 => "fruit", 
             'resource' => $fp, "int" => 133, "float" => 444.432, 
             "unset" => @$unset_var, "heredoc" => $heredoc)
);

// loop through the various elements of $arrays to test array_map()
$iterator = 1;
foreach($arrays as $arr1) {
  echo "-- Iteration $iterator --\n";
  var_dump( array_map('callback', $arr1) );
  $iterator++;
}

echo "Done";
?>
--EXPECTF--
*** Testing array_map() : associative array with diff. values for 'arr1' argument ***
-- Iteration 1 --
array(0) {
}
-- Iteration 2 --
array(1) {
  [0]=>
  int(0)
}
-- Iteration 3 --
array(1) {
  [1]=>
  int(1)
}
-- Iteration 4 --
array(4) {
  [u"one"]=>
  int(1)
  [u"two"]=>
  int(2)
  [u"three"]=>
  int(3)
  [4]=>
  int(4)
}
-- Iteration 5 --
array(1) {
  [u"float"]=>
  float(2.3333)
}
-- Iteration 6 --
array(4) {
  [u"f1"]=>
  float(1.2)
  [u"f2"]=>
  float(3.33)
  [3]=>
  float(4.8999992284)
  [u"f4"]=>
  float(33333333.3333)
}
-- Iteration 7 --
array(4) {
  [111]=>
  unicode(6) "	Hello"
  [u"red"]=>
  unicode(6) "col	or"
  [2]=>
  unicode(7) "world"
  [3]=>
  unicode(4) "pen
"
}
-- Iteration 8 --
array(4) {
  [111]=>
  unicode(7) "\tHello"
  [u"red"]=>
  unicode(7) "col\tor"
  [2]=>
  unicode(9) "\v\fworld"
  [3]=>
  unicode(5) "pen\n"
}
-- Iteration 9 --
array(2) {
  [1]=>
  unicode(5) "hello"
  [u"heredoc"]=>
  unicode(11) "Hello world"
}
-- Iteration 10 --
array(3) {
  [11]=>
  object(classA)#1 (0) {
  }
  [u"unset"]=>
  NULL
  [u"resource"]=>
  resource(%d) of type (stream)
}
-- Iteration 11 --
array(8) {
  [1]=>
  unicode(5) "hello"
  [2]=>
  object(classA)#%d (0) {
  }
  [222]=>
  unicode(5) "fruit"
  [u"resource"]=>
  resource(%d) of type (stream)
  [u"int"]=>
  int(133)
  [u"float"]=>
  float(444.432)
  [u"unset"]=>
  NULL
  [u"heredoc"]=>
  unicode(11) "Hello world"
}
Done
