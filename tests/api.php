<?php
include dirname(__FILE__) . '/helpers/php_api.php';

// Check the qr.php script.
check_api_url('http://moralfibers.co/iphone/qr.php?qr=287&update=1&active=Active', 'QR update');

// Check the new_qr.php script.
check_api_url('http://moralfibers.co/iphone/new_qr.php?qr=1345959&author=emilysowe', 'QR creation');

?>
