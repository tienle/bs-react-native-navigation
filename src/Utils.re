let nativeScreen = (~component, ~make) =>
  ReasonReact.wrapReasonForJs(~component, props =>
    make(~navigator=props##navigator, [||])
  )
  |> Core.asNativeScreen;

let setNavigatorStyle =
    (~nativeScreen: Core.nativeScreen, ~navigatorStyle: Navigator.Style.t) => Obj.magic(
                                                                    nativeScreen
                                                                    )##navigatorStyle#=navigatorStyle;
