open BsReactNativeNavigation;

open Internal;

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
  Navigation.registerComponent(
    ~screenId=screenId(`Modal),
    ~generator=() => Screens.Modal.default,
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
