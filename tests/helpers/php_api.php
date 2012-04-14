<?php
include dirname(__FILE__) . '/exception.php';

/**
 * @param string $url
 *  The URL which should be requested via cUrl.
 * @param string $page
 *  The name of the page. This is used in the output message based on success.
 *
 * @return string
 *  If the exit status is a 200, return the name of the script. If not, throw
 *  and exception which will cause a Jenkins failure.
 *
 */
function check_api_url($url, $page) {
  $check_url = $url;
  $ch = curl_init();
  curl_setopt($ch, CURLOPT_URL, $check_url);
  curl_setopt($ch, CURLOPT_HEADER, true);
  curl_setopt($ch, CURLOPT_NOBODY, true);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
  curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
  curl_setopt($ch, CURLOPT_MAXREDIRS, 10);
  $data = curl_exec($ch);
  $http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);

  if ($http_code == 200) {
    echo "The " . $page . " script has been returned succesfully\n";
  } else {
    test_error('The API does not appear to be working');
  }
}
