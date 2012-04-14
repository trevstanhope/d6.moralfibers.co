#!/usr/bin/php
<?php

/**
 * Drupal hash script - to generate a hash from a plaintext password
 *
 * Check for your PHP interpreter - on Windows you'll probably have to
 * replace line 1 with
 *   #!c:/program files/php/php.exe
 *
 * @param password1 [password2 [password3 ...]]
 *  Plain-text passwords in quotes (or with spaces backslash escaped).
 */

if (version_compare(PHP_VERSION, "5.2.0", "<")) {
  $version  = PHP_VERSION;
  echo <<<EOF

ERROR: This script requires at least PHP version 5.2.0. You invoked it with
       PHP version {$version}.
\n
EOF;
  exit;
}

$script = basename(array_shift($_SERVER['argv']));

if (in_array('--help', $_SERVER['argv']) || empty($_SERVER['argv'])) {
  echo <<<EOF

Generate Drupal 7 password hashes from the shell.

Usage:        {$script} "<plan-text password>"
Example:      {$script} "mynewpassword"

All arguments are long options.

  --help      Print this page.

  "<password1>" ["<password2>" ["<password3>" ...]]

              One or more plan-text passwords enclosed by double quotes. The
              output hash may be manually entered into the {users}.pass field to
              change a password via SQL to a known value.

EOF;
  exit;
}

/**
 * Fake variable_get() since we are not bootstrapping Drupal.
 */
function variable_get($name, $default = NULL) {
  return $default;
}

require_once dirname(__FILE__) . '/password.inc';

foreach ($_SERVER['argv'] as $password) {
  print("\npassword: $password \t\thash: ". user_hash_password($password) ."\n");
}
print("\n");

