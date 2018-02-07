type nativeScreen;

external asNativeScreen : ReasonReact.reactClass => nativeScreen = "%identity";

let nativeScreen = (~component, ~make) =>
  ReasonReact.wrapReasonForJs(~component, props =>
    make(~navigator=props##navigator, [||])
  )
  |> asNativeScreen;

let setNavigatorStyle =
    (~nativeScreen: nativeScreen, ~navigatorStyle: Navigator.Style.t) => Obj.magic(
                                                                    nativeScreen
                                                                    )##navigatorStyle#=navigatorStyle;
