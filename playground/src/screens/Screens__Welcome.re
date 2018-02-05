open ReasonReact;

open BsReactNative;

open BsReactNativeNavigation;

open Internal;

let styles =
  StyleSheet.create(
    Style.(
      {
        "container":
          style([
            flex(1.),
            backgroundColor("#2579FB"),
            alignItems(Center),
            justifyContent(Center)
          ]),
        "text": style([color("#fff")])
      }
    )
  );

let component = statelessComponent("Welcome");

let make = (~navigator, _children) => {
  ...component,
  render: _self =>
    <View style=styles##container>
      <Text style=styles##text> (stringToElement("Welcome!")) </Text>
      <TouchableOpacity
        onPress=(_event => Navigation.showModal(~screen=screenId(`Modal), ()))>
        <Text> (stringToElement("Open Modal")) </Text>
      </TouchableOpacity>
    </View>
};

let default =
  wrapReasonForJs(~component, props =>
    make(~navigator=props##navigator, [||])
  );

[%bs.raw {|
  $$default.navigatorStyle = {
    navBarHidden: true
  }
|}];
