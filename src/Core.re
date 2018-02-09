type screenId;

type deepLink;

type nativeScreen;

external asNativeScreen : ReasonReact.reactClass => nativeScreen = "%identity";

external asDeepLink : string => deepLink = "%identity";

external asScreenId : string => screenId = "%identity";
