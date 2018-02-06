type screenId;

type singleScreenAppConfig;

type showModalConfig;

type dismissModalConfig;

type navigatorStyle;

type navigatorButtons;

type passProps = Js.t({.});

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
  type config;
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
        Js.Option.map([@bs] (t => Animation.drawerToJs(t)), animationType),
      ~disableOpenGesture=?
        Js.Option.map(
          [@bs] (t => Js.Boolean.to_js_boolean(t)),
          disableOpenGesture
        ),
      ()
    );
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

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external registerScreen : (screenId, unit => ReasonReact.reactClass) => unit =
  "";

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external _startSingleScreenApp : singleScreenAppConfig => unit =
  "startSingleScreenApp";

[@bs.obj]
external makeSingleScreenAppConfig :
  (
    ~screen: Screen.t,
    ~drawer: Drawer.config=?,
    ~animationType: string=?,
    ~passProps: passProps=?,
    unit
  ) =>
  singleScreenAppConfig =
  "";

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

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external _showModal : showModalConfig => unit = "showModal";

[@bs.obj]
external makeShowModalConfig :
  (
    ~screen: screenId,
    ~title: string=?,
    ~animationType: string=?,
    ~passProps: passProps=?,
    ~navigatorStyle: navigatorStyle=?,
    ~navigatorButtons: navigatorButtons=?,
    unit
  ) =>
  showModalConfig =
  "";

let showModal =
    (
      ~screen,
      ~title=?,
      ~animationType=?,
      ~passProps=?,
      ~navigatorStyle=?,
      ~navigatorButtons=?,
      ()
    ) =>
  _showModal(
    makeShowModalConfig(
      ~screen,
      ~title?,
      ~animationType=?
        Js.Option.map([@bs] (t => Animation.showModalToJs(t)), animationType),
      ~passProps?,
      ~navigatorStyle?,
      ~navigatorButtons?,
      ()
    )
  );

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external _dismissModal : dismissModalConfig => unit = "dismissModal";

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external _dismissAllModals : dismissModalConfig => unit = "dismissAllModals";

[@bs.obj]
external makeDismissModalConfig :
  (~animationType: string=?, unit) => dismissModalConfig =
  "";

let commonDismissModalConfig = animationType =>
  makeDismissModalConfig(
    ~animationType=?
      Js.Option.map([@bs] (t => Animation.dismissModalToJs(t)), animationType),
    ()
  );

let dismissModal = (~animationType=?, ()) =>
  _dismissModal(commonDismissModalConfig(animationType));

let dismissAllModals = (~animationType=?, ()) =>
  _dismissAllModals(commonDismissModalConfig(animationType));
