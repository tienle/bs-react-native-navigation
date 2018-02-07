# `[@bs.module "react-native-navigation"]`

![](https://img.shields.io/badge/license-MIT%20Licence-blue.svg)

BuckleScript bindings for [`react-native-navigation`](https://wix.github.io/react-native-navigation/) (from [@Wix](https://github.com/wix)).

### Getting started

(work in progress)

### Usage example

(work in progress)

`src/index.re`

```reason
open BsReactNativeNavigation;

type screenId =
  | Drawer
  | Welcome;

let screenId = screenId =>
  (
    switch screenId {
    | Drawer => "screen.drawer"
    | Welcome => "screen.welcome"
    }
  )
  |> Navigation.asScreenId;

let registerScreens = () =>
  [
    (Welcome, Screens.Welcome.default),
    (Drawer, Screens.Drawer.default),
  ]
  |> List.iter(((screen, component)) =>
       Navigation.registerComponent(
         ~screenId=screenId(screen),
         ~generator=() => component,
         ()
       )
     );

let startApplication = () =>
  Navigation.(
    startSingleScreenApp(
      ~screen=
        Screen.make(
          ~screen=screenId(Welcome),
          ~title="Playground / TestApp",
          ()
        ),
      ~drawer=
        Drawer.(
          config(
            ~left=make(~screen=screenId(Drawer), ()),
            ~animationType=Animation.Parallax,
            ()
          )
        ),
      ~animationType=Animation.SlideDown,
      ()
    )
  );
```

`index.js`

```js
import { registerScreens, startApplication } from './lib/js/src'

registerScreens()
startApplication()
```

`Welcome.re` (component)

```reason
open ReasonReact;

open BsReactNative;

open BsReactNativeNavigation;

let component = reducerComponent("Welcome");

let make = (~navigator, _children) => {
  ...component,
  render: _self =>
    /* whatever */
};

let default = Utils.nativeScreen(~component, ~make);

Utils.setNavigatorStyle(
  ~nativeScreen=default,
  ~navigatorStyle=
    Navigator.Style.(
      create([
        navBarTextColor("#fff"),
        navBarNoBorder(true),
        navBarBackgroundColor("#2575E6")
      ])
    )
);
```

### Status

Check the current status [here](STATUS.md).

![](assets/playground.gif)

### Disclaimer

This is work in progress, use with caution.
