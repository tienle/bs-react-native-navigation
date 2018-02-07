external string : string => Js.Json.t = "%identity";

external float : float => Js.Json.t = "%identity";

external int : int => Js.Json.t = "%identity";

external boolean : Js.boolean => Js.Json.t = "%identity";

external object_ : Js.Dict.t(Js.Json.t) => Js.Json.t = "%identity";
