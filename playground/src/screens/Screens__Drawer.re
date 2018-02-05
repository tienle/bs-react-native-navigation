open ReasonReact;

open BsReactNative;

let styles =
  StyleSheet.create(
    Style.(
      {
        "container":
          style([
            flex(1.),
            backgroundColor("#5A35F9"),
            alignItems(Center),
            justifyContent(Center)
          ]),
        "text": style([color("#fff")])
      }
    )
  );

let component = statelessComponent("Drawer");

let make = (~navigator, _children) => {
  ...component,
  render: _self =>
    <View style=styles##container>
      <Text style=styles##text> (stringToElement("Drawer!")) </Text>
    </View>
};

let default =
  wrapReasonForJs(~component, props =>
    make(~navigator=props##navigator, [||])
  );
