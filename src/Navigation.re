type screenId;

type deepLink;

type singleScreenAppConfig;

type showModalConfig;

type showLightBoxConfig;

type dismissModalConfig;

type handleDeepLinkConfig;

type navigatorButtons;

type passProps = Js.t({.});

external asScreenId : string => screenId = "%identity";

external asDeepLink : string => deepLink = "%identity";

module Animation = {
  type root =
    | Fade
    | None
    | SlideDown;
  let rootToJs = (animation: root) =>
    switch animation {
    | Fade => "fade"
    | None => "none"
    | SlideDown => "slide-down"
    };
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
};

module Screen = {
  type t;
  [@bs.obj]
  external make :
    (
      ~screen: screenId,
      ~title: string=?,
      ~navigatorStyle: Navigator.Style.t=?,
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
      ~screen: screenId,
      ~disableOpenGesture: Js.boolean=?,
      ~fixedWidth: float=?,
      ~passProps: passProps=?,
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

module LightBox = {
  type style;
};

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external registerComponent : (screenId, unit => Utils.nativeScreen) => unit =
  "";

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external registerScreen : (screenId, unit => Utils.nativeScreen) => unit = "";

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
    ~navigatorStyle: Navigator.Style.t=?,
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

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external dismissLightBox : unit => unit = "";

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external _showLightBox : showLightBoxConfig => unit = "showLightBox";

[@bs.obj]
external makeShowLightBoxConfig :
  (
    ~screen: screenId,
    ~passProps: passProps=?,
    ~style: LightBox.style=?,
    unit
  ) =>
  showLightBoxConfig =
  "";

let showLightBox = (~screen, ~passProps=?, ~style=?, ()) =>
  _showLightBox(makeShowLightBoxConfig(~screen, ~passProps?, ~style?, ()));

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external _handleDeepLink : handleDeepLinkConfig => unit = "handleDeepLink";

[@bs.obj]
external makeHandleDeepLinkConfig :
  (~link: deepLink, ~payload: Js.t({.})=?, unit) => handleDeepLinkConfig =
  "";

let handleDeepLink = (~link, ~payload=?, ()) =>
  _handleDeepLink(makeHandleDeepLinkConfig(~link, ~payload?, ()));

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
/* it's native screen ID */
external getCurrentlyVisibleScreenId :
  unit => Js.Promise.t({. "screenId": string}) =
  "";
