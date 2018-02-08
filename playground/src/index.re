open BsReactNativeNavigation;

open Internal;

let registerScreens = () =>
  [
    (Welcome, Screens.Welcome.default),
    (Drawer, Screens.Drawer.default),
    (Modal, Screens.Modal.default),
    (LightBox, Screens.LightBox.default)
  ]
  |> List.iter(((screen, component)) =>
       Navigation.registerComponent(screenId(screen), () => component)
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
