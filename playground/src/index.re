open BsReactNativeNavigation;

type screenId =
  | Welcome;

let screenId = name =>
  (
    switch name {
    | Welcome => "screen.welcome"
    }
  )
  |> Navigation.asScreenId;

let registerScreens = () => {
  Navigation.registerComponent(
    ~screenId=screenId(Welcome),
    ~generator=() => Screens.Welcome.default,
    ()
  );
  ();
};

let startApplication = () =>
  Navigation.(
    startSingleScreenApp(
      ~screen=screen(~screen=screenId(Welcome), ()),
      ~animationType=Animation.Fade,
      ()
    )
  );
