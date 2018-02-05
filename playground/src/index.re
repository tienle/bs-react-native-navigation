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
        drawer(
          ~left=Drawer.make(~screen=screenId(`Drawer), ()),
          ~animationType=`slideAndScale,
          ()
        ),
      ~animationType=`slideDown,
      ()
    )
  );
