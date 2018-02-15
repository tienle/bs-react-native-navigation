type pushConfig;

type popConfig;

type resetToConfig;

type showModalConfig;

type t = {
  .
  "push": pushConfig => unit,
  "pop": popConfig => unit,
  "popToRoot": popConfig => unit,
  "resetTo": resetToConfig => unit,
  "showModal": showModalConfig => unit
};

module Style = Navigator__Style;

module Animation = Navigator__Animation;

module Buttons = Navigator__Buttons;

[@bs.obj]
external makePushConfig :
  (~screen: Core.screenId, ~title: string=?, unit) => pushConfig =
  "";

[@bs.obj]
external makePopConfig :
  (~animated: Js.boolean=?, ~animationType: string=?, unit) => popConfig =
  "";

[@bs.obj]
external makeResetToConfig :
  (
    ~screen: Core.screenId,
    ~title: string=?,
    ~passProps: Js.t({.})=?,
    ~animated: Js.boolean=?,
    ~animationType: string=?,
    ~navigatorStyle: Navigator__Style.t=?,
    ~navigatorButtons: Navigator__Buttons.t=?,
    unit
  ) =>
  popConfig =
  "";

[@bs.obj]
external makeShowModalConfig :
  (
    ~screen: Core.screenId,
    ~title: string=?,
    ~passProps: Js.t({.})=?,
    ~navigatorStyle: Navigator__Style.t=?,
    ~animationType: string=?
  ) =>
  showModalConfig =
  "";

let push = (~navigator, ~screen, ~title=?, ()) =>
  navigator##push(makePushConfig(~screen, ~title?, ()));

let commonPopConfig = (~animationType, ~animated) =>
  makePopConfig(
    ~animationType=?
      Js.Option.map([@bs] (t => Animation.commonToJs(t)), animationType),
    ~animated=?
      Js.Option.map([@bs] (t => Js.Boolean.to_js_boolean(t)), animated),
    ()
  );

let pop = (~navigator, ~animated=?, ~animationType=?, ()) =>
  navigator##pop(commonPopConfig(~animated, ~animationType));

let popToRoot = (~navigator, ~animated=?, ~animationType=?, ()) =>
  navigator##popToRoot(commonPopConfig(~animated, ~animationType));

let resetTo =
    (
      ~navigator,
      ~screen,
      ~title=?,
      ~passProps=?,
      ~animated=?,
      ~animationType=?,
      ~navigatorStyle=?,
      ~navigatorButtons=?,
      ()
    ) =>
  navigator##resetTo(
    makeResetToConfig(
      ~screen,
      ~title?,
      ~animationType=?
        Js.Option.map([@bs] (t => Animation.commonToJs(t)), animationType),
      ~animated=?
        Js.Option.map([@bs] (t => Js.Boolean.to_js_boolean(t)), animated),
      ~passProps?,
      ~navigatorStyle?,
      ~navigatorButtons?,
      ()
    )
  );

let showModal =
    (
      ~navigator,
      ~screen,
      ~title=?,
      ~passProps=?,
      ~animationType=?,
      ~navigatorStyle=?
    ) =>
  navigator##showModal(
    makeShowModalConfig(
      ~screen,
      ~title?,
      ~animationType=?
        Js.Option.map([@bs] (t => Animation.commonToJs(t)), animationType),
      ~passProps?,
      ~navigatorStyle?
    )
  );
