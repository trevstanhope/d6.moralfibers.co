<?php

class DrupalOAuthToken extends OAuthToken {
  public $type = '';
  public $provider_token = TRUE;
  public $uid = 0;
  public $created = 0;
  public $changed = 0;
  public $consumer_key = '';
  public $services = array();
  public $authorized = 0;
  public $expires = 0;
  
  public function __construct($key, $secret, $params=array()) {
    parent::__construct($key, $secret);
    foreach($params as $key => $value) {
      if (isset($this->$key)) {
        $this->$key = $value;
      }
    }
  }

  /**
   * Writes the token to the database
   *
   * @param bool $update 
   *  Optional. Set to TRUE if the token exists and should be updated. Defaults to FALSE.
   * @return void
   */
  public function write($update=FALSE) {
    $primary = $update ? array('token_key') : array();

    if (!$update) {
      $this->created = time();
    }
    $this->changed = time();

    $values = get_object_vars($this);
    $values['token_key'] = $this->key;
    $values['services'] = json_encode($values['services']);

    // Stop the created time from being modified
    if ($update) {
      unset($values['created']);
    }

    drupal_write_record('oauth_common_token', $values, $primary);
  }

  /**
   * Deletes the token from the database
   *
   * @return void
   */
  public function delete() {
    self::deleteToken($this->key);
  }

  /**
   * Deletes the token with the key from the database
   *
   * @return void
   */
  public static function deleteToken($key) {
    db_query("DELETE FROM {oauth_common_token} WHERE token_key='%s'", array(
      'key' => $key,
    ));
  }

  /**
   * Gets the token with the specified key
   *
   * @param string $key
   *  The key of the token to get
   * @return DrupalOAuthToken
   *  The loaded token object or FALSE if load failed
   */
  public static function load($key) {
    return self::fromResult(db_query("SELECT * FROM {oauth_common_token} WHERE token_key='%s'", array(
      ':key' => $key,
    )));
  }

  /**
   * Constructs a token from a db-result resource
   *
   * @param resource $res
   *  A database result resource
   * @return DrupalOAuthToken
   *  The constructed token object or NULL if no rows could be read or construction failed
   */
  public static function fromResult($res) {
    if ($data = db_fetch_array($res)) {
      $data['services'] = json_decode($data['services']);
      return new DrupalOAuthToken($data['token_key'], $data['secret'], $data);
    }
    return NULL;
  }
}