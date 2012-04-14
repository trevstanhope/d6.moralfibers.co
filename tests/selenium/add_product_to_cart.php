<?php

require_once 'PHPUnit/Autoload.php';
require_once '/usr/share/php/PHPUnit/Extensions/SeleniumTestCase/SauceOnDemandTestCase.php';

class AddToCart extends PHPUnit_Extensions_SeleniumTestCase_SauceOnDemandTestCase
{
  protected function setUp()
  {
    $this->setBrowser("{\"username\": \"skottler\",\"access-key\":\"d362ef46-7a5a-495f-8aee-c5507cecec9e\",\"browser\": \"firefox\",\"browser-version\":\"6\",\"job-name\":\"Untitled\",\"max-duration\":1800,\"record-video\":true,\"user-extensions-url\":\"\",\"os\":\"Windows 2008\"}");
    $this->setBrowserUrl("http://www.moralfibers.co/");
  }

  public function testMyTestCase()
  {
    $this->open("/");
    $this->waitForPageToLoad("60000");
    $this->click("link=Men's");
    $this->waitForPageToLoad("60000");
    $this->click("xpath=//table[@class='views-view-grid']/tbody/tr[1]/td[1]/div[1]/span/a/img");
    $this->waitForPageToLoad("60000");
    $this->select("id=edit-attributes-2", "Large");
    $this->click("id=edit-submit");
    $this->waitForPageToLoad("60000");
  }
}
?>
