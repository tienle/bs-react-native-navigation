open BsReactNativeNavigation;

[@bs.deriving jsConverter]
type screenId = [ | `Drawer | `Welcome | `Modal];

let screenId = name => screenIdToJs(name) |> Navigation.asScreenId;
