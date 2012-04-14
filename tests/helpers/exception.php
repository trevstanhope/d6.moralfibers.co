<?php

if (!function_exists('curl_init')) {
  throw new Exception('Please make sure the php5-curl package is installed on the machine running tests.');
}

function test_error($message) {
  throw new Exception($message);
}
