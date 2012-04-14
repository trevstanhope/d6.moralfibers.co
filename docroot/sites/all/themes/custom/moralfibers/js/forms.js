if (Drupal.jsEnabled) {
    $(document).ready(function() {
       $('input[type=text]').focus(function() {
         $(this).select();              
    });
  });
}