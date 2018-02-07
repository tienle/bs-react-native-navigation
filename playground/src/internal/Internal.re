open BsReactNativeNavigation;

type screenId =
  | Drawer
  | Welcome
  | Modal
  | LightBox;

let screenIdToJs = screenId =>
  switch screenId {
  | Drawer => "screen.drawer"
  | Welcome => "screen.welcome"
  | Modal => "screen.modal"
  | LightBox => "screen.lightbox"
  };

let screenId = name => screenIdToJs(name) |> Navigation.asScreenId;
