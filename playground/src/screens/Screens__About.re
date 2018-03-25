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
            backgroundColor("#F5F5F5"),
            alignItems(Center),
            justifyContent(Center),
          ]),
        "text":
          style([
            color("#1144E6"),
            fontSize(Float(32.)),
            marginBottom(Pt(20.)),
            fontWeight(`Bold),
          ]),
      }
    ),
  );

let component = statelessComponent("Modal");

let make = (~navigator, _children) => {
  ...component,
  render: _self =>
    <View style=styles##container>
      <Text style=styles##text> (stringToElement("About")) </Text>
      <TouchableOpacity onPress=(_event => Navigator.pop(~navigator, ()))>
        <Text> (stringToElement("Go back")) </Text>
      </TouchableOpacity>
    </View>,
};

let default = Utils.nativeScreen(~component, ~make);

Utils.setNavigatorStyle(
  ~nativeScreen=default,
  ~navigatorStyle=Navigator.Style.(create([navBarHidden(true)])),
);
