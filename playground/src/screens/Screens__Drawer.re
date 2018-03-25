open ReasonReact;

open BsReactNative;

open BsReactNativeNavigation;

let styles =
  StyleSheet.create(
    Style.(
      {
        "container": style([flex(1.), backgroundColor("#5A35F9")]),
        "inner":
          style([flex(1.), alignItems(Center), justifyContent(Center)]),
        "text":
          style([
            color("#fff"),
            fontSize(Float(32.)),
            marginBottom(Pt(20.)),
            fontWeight(`Bold),
          ]),
      }
    ),
  );

let component = statelessComponent("Drawer");

let make = (~navigator, _children) => {
  ...component,
  render: _self =>
    <View style=styles##container>
      <View style=styles##inner>
        <Text style=styles##text> (stringToElement("Drawer!")) </Text>
      </View>
    </View>,
};

let default = Utils.nativeScreen(~component, ~make);
