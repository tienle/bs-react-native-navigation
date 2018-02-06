# `[@bs.module "react-native-navigation"]`

![](https://img.shields.io/badge/license-MIT%20Licence-blue.svg)

BuckleScript bindings for [`react-native-navigation`](https://wix.github.io/react-native-navigation/) (from [@Wix](https://github.com/wix)).

### Getting started

(work in progress)

### Usage example

(work in progress)

`src/index.re`

```
open BsReactNativeNavigation;

[@bs.deriving jsConverter]
type screenId = [ | `Drawer | `Welcome ];

let screenId = name => screenIdToJs(name) |> Navigation.asScreenId;

let registerScreens = () => {
  Navigation.registerComponent(
    ~screenId=screenId(`Welcome),
    ~generator=() => Screens.Welcome.default,
    ()
  );
  Navigation.registerComponent(
    ~screenId=screenId(`Drawer),
    ~generator=() => Screens.Drawer.default,
    ()
  );
};

let startApplication = () =>
  Navigation.(
    startSingleScreenApp(
      ~screen=Screen.make(~screen=screenId(`Welcome), ()),
      ~drawer=
        Drawer.(
          config(
            ~left=make(~screen=screenId(`Drawer), ()),
            ~animationType=`parallax,
            ()
          )
        ),
      ~animationType=`slideDown,
      ()
    )
  );
```

`index.js`

```
import { registerScreens, startApplication } from './lib/js/src'

registerScreens()
startApplication()
```

### Status

Check the current status [here](STATUS.md).

![](assets/playground.gif)

### Disclaimer

This is work in progress, use with caution.
