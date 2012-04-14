// $Id$
/*global Drupal, jQuery, alert, $ */

/**
 * @file
 * The main JavaScript file for Ubercart Limited Time Offer.
 *
 * @ingroup uc_lto
 */

/**
 * Start and control the LTO countdown timer.
 */
Drupal.behaviors.ucLTO = function(context) {
  if (!$('body').hasClass('ucLTO-processed')) {
    Drupal.settings.ucLTO.expiration *= 1000;
  
    if (Drupal.settings.ucLTO.doCountdown) {
      $('.uc-lto-expiration').everyTime(1000, 'countdown', function(i) {
        var that = $(this),
          now = new Date(),
          delta = Drupal.settings.ucLTO.expiration - now.getTime() + (now.getTimezoneOffset() * 60000);
        if (delta <= 0) {
          that.text(Drupal.t('expired')).stopTime('countdown');
          $('.node-add-to-cart').remove();
        }
        else {
          that.text(Drupal.formatInterval(Math.floor(delta / 1000), Drupal.settings.ucLTO.timeGran));
          if (delta < 60000 && !that.hasClass('uc-lto-expiration-min')) {
            that.removeClass('uc-lto-expiration-day').removeClass('uc-lto-expiration-hour').addClass('uc-lto-expiration-min');
          }
          else if (delta < 3600000 && !that.hasClass('uc-lto-expiration-hour')) {
            that.removeClass('uc-lto-expiration-day').addClass('uc-lto-expiration-hour');
          }
          else if (delta < 86400000 && !that.hasClass('uc-lto-expiration-day')) {
            that.addClass('uc-lto-expiration-day');
          }
        }
      });
    }

  $('body').addClass('ucLTO-processed');
  }
};

Drupal.formatInterval = function(timestamp, granularity, langcode) {
  granularity = parseInt(granularity, 10) || 2;
  langcode = langcode || null;
  var units = [
    {
      'singular' : '1 year',
      'plural' : '@count years',
      'secs' : 31536000
    },
    {
      'singular' : '1 week',
      'plural' : '@count weeks',
      'secs' : 604800
    },
    {
      'singular' : '1 day',
      'plural' : '@count days',
      'secs' : 86400
    },
    {
      'singular' : '1 hour',
      'plural' : '@count hours',
      'secs' : 3600
    },
    {
      'singular' : '1 min',
      'plural' : '@count min',
      'secs' : 60
    },
    {
      'singular' : '1 sec',
      'plural' : '@count sec',
      'secs' : 1
    }
  ],
    output = '';
  $.each(units, function(i, val) {
    if (timestamp >= val.secs && granularity > 0) {
      output += (output ? ' ' : '') + Drupal.formatPlural(Math.floor(timestamp / val.secs), val.singular, val.plural, {}, langcode);
      timestamp %= val.secs;
      granularity--;
    }
    if (granularity === 0) {
      return false;
    }
  });
  return output ? output : Drupal.t('0 sec', {}, langcode);
};