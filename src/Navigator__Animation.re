type common =
  | Fade
  | SlideHorizontal;

let commonToJs =
  fun
  | Fade => "fade"
  | SlideHorizontal => "slide-horizontal";
