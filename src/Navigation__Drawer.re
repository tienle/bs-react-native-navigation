type t;

type style;

type config;

type type_ =
  | MMDrawer
  | TheSideBar;

let type_ToJs =
  fun
  | MMDrawer => "MMDrawer"
  | TheSideBar => "TheSideBar";

[@bs.obj]
external make :
  (
    ~screen: Core.screenId,
    ~disableOpenGesture: Js.boolean=?,
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
    ~disableOpenGesture: Js.boolean=?,
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
      ()
    ) =>
  _config(
    ~left?,
    ~right?,
    ~style?,
    ~_type=?Js.Option.map([@bs] (t => type_ToJs(t)), _type),
    ~animationType=?
      Js.Option.map(
        [@bs] (t => Navigation__Animation.drawerToJs(t)),
        animationType
      ),
    ~disableOpenGesture=?
      Js.Option.map(
        [@bs] (t => Js.Boolean.to_js_boolean(t)),
        disableOpenGesture
      ),
    ()
  );
