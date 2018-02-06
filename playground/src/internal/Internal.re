open BsReactNativeNavigation;

[@bs.deriving jsConverter]
type screenId = [ | `Drawer | `Welcome | `Modal | `LightBox];

let screenId = name => screenIdToJs(name) |> Navigation.asScreenId;
