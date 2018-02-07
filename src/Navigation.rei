type screenId;

type deepLink;

/* TODO: */
type navigatorStyle;

/* TODO: */
type navigatorButtons;

type passProps = Js.t({.});

external asScreenId : string => screenId = "%identity";

external asDeepLink : string => deepLink = "%identity";

module Animation: {
  type root =
    | Fade
    | None
    | SlideDown;
  type showModal =
    | None
    | SlideUp;
  type dismissModal =
    | None
    | SlideDown;
  type drawer =
    | Door
    | Parallax
    | Slide
    | SlideAndScale
    | AirBnb
    | Facebook
    | Luvocracy
    | Wunderlist;
};

module Screen: {
  type t;
  let make:
    (
      ~screen: screenId,
      ~title: string=?,
      ~navigatorStyle: navigatorStyle=?,
      ~navigatorButtons: navigatorButtons=?,
      unit
    ) =>
    t;
};

module Drawer: {
  type t;
  /* TODO: style */
  type style;
  type config;
  type type_ =
    | MMDrawer
    | TheSideBar;
  let make:
    (
      ~screen: screenId,
      ~disableOpenGesture: Js.boolean=?,
      ~fixedWidth: float=?,
      ~passProps: passProps=?,
      unit
    ) =>
    t;
  let config:
    (
      ~left: t=?,
      ~right: t=?,
      ~style: style=?,
      ~_type: type_=?,
      ~animationType: Animation.drawer=?,
      ~disableOpenGesture: bool=?,
      unit
    ) =>
    config;
};

/* TODO: style */
module LightBox: {type style;};

let registerComponent:
  (
    ~screenId: screenId,
    ~generator: unit => ReasonReact.reactClass,
    ~store: 'a=?,
    ~provider: ReasonReact.reactClass=?,
    unit
  ) =>
  unit;

let registerScreen: (screenId, unit => ReasonReact.reactClass) => unit;

let startSingleScreenApp:
  (
    ~screen: Screen.t,
    ~drawer: Drawer.config=?,
    ~animationType: Animation.root=?,
    ~passProps: passProps=?,
    unit
  ) =>
  unit;

let showModal:
  (
    ~screen: screenId,
    ~title: string=?,
    ~animationType: Animation.showModal=?,
    ~passProps: passProps=?,
    ~navigatorStyle: navigatorStyle=?,
    ~navigatorButtons: navigatorButtons=?,
    unit
  ) =>
  unit;

let dismissModal: (~animationType: Animation.dismissModal=?, unit) => unit;

let dismissAllModals: (~animationType: Animation.dismissModal=?, unit) => unit;

let dismissLightBox: unit => unit;

let showLightBox:
  (
    ~screen: screenId,
    ~passProps: passProps=?,
    ~style: LightBox.style=?,
    unit
  ) =>
  unit;

let handleDeepLink: (~link: deepLink, ~payload: Js.t({.})=?, unit) => unit;

let getCurrentlyVisibleScreenId: unit => Js.Promise.t({. "screenId": string});
