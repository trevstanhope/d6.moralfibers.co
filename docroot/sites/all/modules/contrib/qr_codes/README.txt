$Id:

Description
===========
This modules allows for the creation of two dimensional (2D) QR barcodes.

  "QR codes are a popular type of two-dimensional barcode. They are also known as hardlinks or physical world hyperlinks. QR Codes store up to 4,296 alphanumeric characters of arbitrary text. This text can be anything, for example URL, contact information, a telephone number, even a poem! QR codes can be read by an optical device with the appropriate software. Such devices range from dedicated QR code readers to mobile phones."

Learn more at http://code.google.com/apis/chart/docs/gallery/qr_codes.html.

The module exposes an API for creating your own barcodes, a theme function for returning the images, and a block for displaying configurable node data as a qr code. QR code images are cached locally for faster performance and further manipulation. The module plays well with Imagecache and Token, which are recommended but not required.

You should enable the module and at least one engine module that provides QR encoding.