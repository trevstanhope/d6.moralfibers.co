
This module implements secure password hashes using backported code from
Drupal 7, which is the outcome of http://drupal.org/node/29706.

This module requires PHP 5.2.4 as a minimum version (the same as Drupal 7).

IMPORTANT - this module cannot be disabled except via SQL or upgrading to
Drupal 7. Disabling will mean all users will have to login via password-reset
links.

The default Drupal 6 and before password hashes are insecure. MD5 has 
long been known to be crackable, and we should not be storing passwords
using this.

There has been a long discussion about this. See http://drupal.org/node/29706
and http://drupal.org/node/1201444 for in-depth discussions. Do not post
issues about anything already discussed there.
