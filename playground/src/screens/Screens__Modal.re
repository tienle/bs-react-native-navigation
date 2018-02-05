open ReasonReact;

open BsReactNative;

open BsReactNativeNavigation;

let styles =
  StyleSheet.create(
    Style.(
      {
        "container":
          style([
            flex(1.),
            backgroundColor("#46D26B"),
            alignItems(Center),
            justifyContent(Center)
          ]),
        "text": style([color("#fff")])
      }
    )
  );

let component = statelessComponent("Modal");

let make = (~navigator, _children) => {
  ...component,
  render: _self =>
    <View style=styles##container>
      <Text style=styles##text> (stringToElement("Modal!")) </Text>
      <TouchableOpacity
        onPress=(_event => Navigation.dismissModal(~animationType=`none, ()))>
        <Text> (stringToElement("Dismiss Modal")) </Text>
      </TouchableOpacity>
    </View>
};

let default =
  wrapReasonForJs(~component, props =>
    make(~navigator=props##navigator, [||])
  );

[%bs.raw
  {|
    $$default.navigatorStyle = {
      navBarHidden: true
    }
  |}
];
