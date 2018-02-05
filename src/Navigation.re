type screenId;

type screen;

type drawer;

type singleScreenAppConfig;

type navigatorStyle;

type navigatorButtons;

external asScreenId : string => screenId = "%identity";

external asScreen : Js.Dict.t('a) => screen = "%identity";

module Animation = {
  type root =
    | None
    | SlideDown
    | Fade;
  type showModal =
    | None
    | SlideUp;
  type dismissModal =
    | None
    | SlideDown;
  let root = (animation: root) =>
    switch animation {
    | None => "none"
    | SlideDown => "slide-down"
    | Fade => "fade"
    };
  let showModal = (animation: showModal) =>
    switch animation {
    | None => "none"
    | SlideUp => "slide-up"
    };
  let dismissModal = (animation: dismissModal) =>
    switch animation {
    | None => "none"
    | SlideDown => "slide-down"
    };
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
external screen :
  (
    ~screen: screenId,
    ~title: string=?,
    ~navigatorStyle: navigatorStyle=?,
    ~navigatorButtons: navigatorButtons=?,
    unit
  ) =>
  screen =
  "";

[@bs.obj]
external makeSingleScreenAppConfig :
  (
    ~screen: screen,
    ~drawer: drawer=?,
    ~animationType: Js.Nullable.t(string),
    unit
  ) =>
  singleScreenAppConfig =
  "";

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external _startSingleScreenApp : singleScreenAppConfig => unit =
  "startSingleScreenApp";

let startSingleScreenApp = (~screen, ~drawer=?, ~animationType=?, ()) =>
  _startSingleScreenApp(
    makeSingleScreenAppConfig(
      ~screen,
      ~drawer?,
      ~animationType=
        Js.Nullable.from_opt(Utils.option_map(Animation.root, animationType)),
      ()
    )
  );
