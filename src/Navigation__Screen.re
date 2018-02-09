type t;

[@bs.obj]
external make :
  (
    ~screen: Core.screenId,
    ~title: string=?,
    ~navigatorStyle: Navigator.Style.t=?,
    ~navigatorButtons: Navigator.Buttons.t=?,
    unit
  ) =>
  t =
  "";
