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

let startApplication = () => {
  let initialScreen = Navigation.screen(~screen=screenId(Welcome), ());
  Navigation.startSingleScreenApp(~screen=initialScreen, ());
};
