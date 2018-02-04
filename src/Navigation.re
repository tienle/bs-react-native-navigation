type screenId;

type screen;

type drawer;

type singleScreenAppConfig;

type navigatorStyle;

type navigatorButtons;

external asScreen : Js.Dict.t('a) => screen = "%identity";

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
  (~screen: screen, ~drawer: drawer=?, unit) => singleScreenAppConfig =
  "";

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external _startSingleScreenApp : singleScreenAppConfig => unit =
  "startSingleScreenApp";

let startSingleScreenApp = (~screen, ~drawer=?, ()) =>
  _startSingleScreenApp(makeSingleScreenAppConfig(~screen, ~drawer?, ()));
