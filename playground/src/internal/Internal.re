open BsReactNativeNavigation;

type screenId =
  | Drawer
  | Welcome
  | Modal
  | LightBox
  | About;

let screenId = screenId =>
  (
    switch (screenId) {
    | Drawer => "screen.drawer"
    | Welcome => "screen.welcome"
    | Modal => "screen.modal"
    | LightBox => "screen.lightbox"
    | About => "screen.about"
    }
  )
  |> Core.asScreenId;
