type screen;

external asScreen : string => screen = "%identity";

[@bs.module "react-native-navigation"] [@bs.scope "Navigation"]
external _registerComponent :
  (
    string,
    unit => ReasonReact.reactClass,
    Js.Nullable.t(Js.t({.})),
    Js.Nullable.t(ReasonReact.reactClass)
  ) =>
  unit =
  "registerComponent";

let registerComponent = (name, screen, ~store=?, ~provider=?, ()) =>
  Js.Nullable.(
    _registerComponent(name, screen, from_opt(store), from_opt(provider))
  );
