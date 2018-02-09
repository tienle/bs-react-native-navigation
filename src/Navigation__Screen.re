type t;

[@bs.obj]
external make :
  (
    ~screen: Core.screenId,
    ~title: string=?,
    ~navigatorStyle: Navigator__Style.t=?,
    ~navigatorButtons: Navigator__Buttons.t=?,
    unit
  ) =>
  t =
  "";
