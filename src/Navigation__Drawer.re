type t;

type style;

type config;

type type_ =
  | MMDrawer
  | TheSideBar;

type side = [ | `Left | `Right];

type state = [ | `Open | `Closed];

let type_ToJs =
  fun
  | MMDrawer => "MMDrawer"
  | TheSideBar => "TheSideBar";

let sideToJs =
  fun
  | `Left => "left"
  | `Right => "Right";

let stateToJs =
  fun
  | `Open => "open"
  | `Closed => "closed";

[@bs.obj]
external make :
  (
    ~screen: Core.screenId,
    ~disableOpenGesture: bool=?,
    ~fixedWidth: float=?,
    ~passProps: Js.t({.})=?,
    unit
  ) =>
  t =
  "";

[@bs.obj]
external _config :
  (
    ~left: t=?,
    ~right: t=?,
    ~style: style=?,
    ~_type: string=?,
    ~animationType: string=?,
    ~disableOpenGesture: bool=?,
    unit
  ) =>
  config =
  "";

let config =
    (
      ~left=?,
      ~right=?,
      ~style=?,
      ~_type=?,
      ~animationType=?,
      ~disableOpenGesture=?,
      (),
    ) =>
  _config(
    ~left?,
    ~right?,
    ~style?,
    ~_type=?Js.Option.map((. t) => type_ToJs(t), _type),
    ~animationType=?
      Js.Option.map(
        (. t) => Navigation__Animation.drawerToJs(t),
        animationType,
      ),
    ~disableOpenGesture=?
      Js.Option.map(
        (. t) => Js.Boolean.to_js_boolean(t),
        disableOpenGesture,
      ),
    (),
  );
