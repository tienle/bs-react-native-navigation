open ReasonReact;

open BsReactNative;

open BsReactNativeNavigation;

let styles =
  StyleSheet.create(
    Style.(
      {
        "container":
          style([
            width(Pt(300.)),
            height(Pt(400.)),
            backgroundColor("#FF3E9D"),
            alignItems(Center),
            justifyContent(Center),
          ]),
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

let component = statelessComponent("LightBox");

let make = (~navigator, _children) => {
  ...component,
  render: _self =>
    <View style=styles##container>
      <Text style=styles##text> (stringToElement("LightBox!")) </Text>
      <TouchableOpacity onPress=(_event => Navigation.dismissLightBox())>
        <Text> (stringToElement("Dismiss LightBox")) </Text>
      </TouchableOpacity>
    </View>,
};

let default = Utils.nativeScreen(~component, ~make);
