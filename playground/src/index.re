open BsReactNativeNavigation;

open Internal;

let registerScreens = () => {
  Navigation.registerComponent(
    ~screenId=screenId(Welcome),
    ~generator=() => Screens.Welcome.default,
    ()
  );
  Navigation.registerComponent(
    ~screenId=screenId(Drawer),
    ~generator=() => Screens.Drawer.default,
    ()
  );
  Navigation.registerComponent(
    ~screenId=screenId(Modal),
    ~generator=() => Screens.Modal.default,
    ()
  );
  Navigation.registerComponent(
    ~screenId=screenId(LightBox),
    ~generator=() => Screens.LightBox.default,
    ()
  );
};

let startApplication = () =>
  Navigation.(
    startSingleScreenApp(
      ~screen=Screen.make(~screen=screenId(Welcome), ()),
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
