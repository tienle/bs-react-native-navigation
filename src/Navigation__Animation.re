type root =
  | Fade
  | None
  | SlideDown;

let rootToJs =
  fun
  | Fade => "fade"
  | None => "none"
  | SlideDown => "slide-down";

type showModal =
  | None
  | SlideUp;

let showModalToJs =
  fun
  | None => "none"
  | SlideUp => "slide-up";

type dismissModal =
  | None
  | SlideDown;

let dismissModalToJs =
  fun
  | None => "none"
  | SlideDown => "slide-down";

type drawer =
  | Door
  | Parallax
  | Slide
  | SlideAndScale
  | AirBnb
  | Facebook
  | Luvocracy
  | Wunderlist;

let drawerToJs =
  fun
  | Door => "door"
  | Parallax => "parallax"
  | Slide => "slide"
  | SlideAndScale => "slide-and-scale"
  | AirBnb => "airbnb"
  | Facebook => "facebook"
  | Luvocracy => "luvocracy"
  | Wunderlist => "wunder-list";
