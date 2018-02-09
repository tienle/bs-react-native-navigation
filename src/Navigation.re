type singleScreenAppConfig;

type showModalConfig;

type showLightBoxConfig;

type dismissModalConfig;

type handleDeepLinkConfig;

module Animation = Navigation__Animation;

module Screen = Navigation__Screen;

module Drawer = Navigation__Drawer;

module LightBox = Navigation__LightBox;

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external registerComponent : (Core.screenId, unit => Core.nativeScreen) => unit =
  "";

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external registerScreen : (Core.screenId, unit => Core.nativeScreen) => unit =
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
    ~passProps: Js.t({.})=?,
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
    ~screen: Core.screenId,
    ~title: string=?,
    ~animationType: string=?,
    ~passProps: Js.t({.})=?,
    ~navigatorStyle: Navigator__Style.t=?,
    ~navigatorButtons: Navigator__Buttons.t=?,
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
    ~screen: Core.screenId,
    ~passProps: Js.t({.})=?,
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
  (~link: Core.deepLink, ~payload: Js.t({.})=?, unit) => handleDeepLinkConfig =
  "";

let handleDeepLink = (~link, ~payload=?, ()) =>
  _handleDeepLink(makeHandleDeepLinkConfig(~link, ~payload?, ()));

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
/* it's native screen ID */
external getCurrentlyVisibleScreenId :
  unit => Js.Promise.t({. "screenId": string}) =
  "";
