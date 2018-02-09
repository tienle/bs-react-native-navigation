type pop =
  | Fade
  | SlideHorizontal;

let popToJs =
  fun
  | Fade => "fade"
  | SlideHorizontal => "slide-horizontal";
