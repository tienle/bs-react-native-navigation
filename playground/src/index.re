open BsReactNativeNavigation;

[@bs.deriving jsConverter]
type screenId = [ | `Drawer | `Welcome];

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
        drawer(
          ~left=Drawer.make(~screen=screenId(`Drawer), ()),
          ~_type=`TheSideBar,
          ~animationType=`luvocracy,
          ()
        ),
      ~animationType=`slideDown,
      ()
    )
  );
