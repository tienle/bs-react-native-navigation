type screenId;

type singleScreenAppConfig;

type drawer;

type navigatorStyle;

type navigatorButtons;

external asScreenId : string => screenId = "%identity";

module Animation = {
  [@bs.deriving jsConverter]
  type root = [ | `none | [@bs.as "slide-down"] `slideDown | `fade];
  [@bs.deriving jsConverter]
  type showModal = [ | `none | [@bs.as "slide-up"] `slideUp];
  [@bs.deriving jsConverter]
  type dismissModal = [ | `none | [@bs.as "slide-down"] `slideDown];
  [@bs.deriving jsConverter]
  type drawer = [
    | `door
    | `parallax
    | `slide
    | [@bs.as "slide-and-scale"] `slideAndScale
    | `airbnb
    | `facebook
    | `luvocracy
    | [@bs.as "wunder-list"] `wunderList
  ];
};

module Screen = {
  type t;
  [@bs.obj]
  external make :
    (
      ~screen: screenId,
      ~title: string=?,
      ~navigatorStyle: navigatorStyle=?,
      ~navigatorButtons: navigatorButtons=?,
      unit
    ) =>
    t =
    "";
};

module Drawer = {
  type t;
  type style;
  [@bs.deriving jsConverter]
  type type_ = [ | `MMDrawer | `TheSideBar];
  [@bs.obj]
  external make :
    (
      ~screen: screenId,
      ~disableOpenGesture: Js.boolean=?,
      ~fixedWidth: float=?,
      ~passProps: Js.t({.})=?,
      unit
    ) =>
    t =
    "";
};

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external _registerComponent :
  (
    screenId,
    unit => ReasonReact.reactClass,
    /* TODO */
    Js.Nullable.t('a),
    Js.Nullable.t(ReasonReact.reactClass)
  ) =>
  unit =
  "registerComponent";

let registerComponent = (~screenId, ~generator, ~store=?, ~provider=?, ()) =>
  Js.Nullable.(
    _registerComponent(
      screenId,
      generator,
      from_opt(store),
      from_opt(provider)
    )
  );

[@bs.obj]
external makeSingleScreenAppConfig :
  (
    ~screen: Screen.t,
    ~drawer: drawer=?,
    ~animationType: string=?,
    ~passProps: Js.t({.})=?,
    unit
  ) =>
  singleScreenAppConfig =
  "";

[@bs.obj]
external _drawer :
  (
    ~left: Drawer.t=?,
    ~right: Drawer.t=?,
    ~style: Drawer.style=?,
    ~_type: string=?,
    ~animationType: string=?,
    ~disableOpenGesture: Js.boolean=?,
    unit
  ) =>
  drawer =
  "";

let drawer =
    (
      ~left=?,
      ~right=?,
      ~style=?,
      ~_type=?,
      ~animationType=?,
      ~disableOpenGesture=?,
      ()
    ) =>
  _drawer(
    ~left?,
    ~right?,
    ~style?,
    ~_type=?Js.Option.map([@bs] (t => Drawer.type_ToJs(t)), _type),
    ~animationType=?
      Js.Option.map([@bs] (t => Animation.drawerToJs(t)), animationType),
    ~disableOpenGesture=?
      Js.Option.map(
        [@bs] (t => Js.Boolean.to_js_boolean(t)),
        disableOpenGesture
      ),
    ()
  );

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external _startSingleScreenApp : singleScreenAppConfig => unit =
  "startSingleScreenApp";

let startSingleScreenApp =
    (~screen, ~drawer=?, ~animationType=?, ~passProps=?, ()) =>
  _startSingleScreenApp(
    makeSingleScreenAppConfig(
      ~screen,
      ~drawer?,
      ~animationType=?
        Js.Option.map([@bs] (t => Animation.rootToJs(t)), animationType),
      ~passProps?,
      ()
    )
  );
