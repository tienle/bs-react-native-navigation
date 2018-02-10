type pushConfig;

type popConfig;

type t = {
  .
  "push": pushConfig => unit,
  "pop": popConfig => unit
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

let push = (~navigator, ~screen, ~title=?, ()) =>
  navigator##push(makePushConfig(~screen, ~title?, ()));

let commonPopConfig = (~animationType, ~animated) =>
  makePopConfig(
    ~animationType=?
      Js.Option.map([@bs] (t => Animation.popToJs(t)), animationType),
    ~animated=?
      Js.Option.map([@bs] (t => Js.Boolean.to_js_boolean(t)), animated),
    ()
  );

let pop = (~navigator, ~animated=?, ~animationType=?, ()) =>
  navigator##pop(commonPopConfig(~animated, ~animationType));

let popToRoot = (~navigator, ~animated=?, ~animationType=?, ()) =>
  navigator##popToRoot(commonPopConfig(~animated, ~animationType));
