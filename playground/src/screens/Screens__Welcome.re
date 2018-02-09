open ReasonReact;

open BsReactNative;

open BsReactNativeNavigation;

open Internal;

type action =
  | UpdateScreenId(string);

type state = {id: string};

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
        "text":
          style([
            color("#fff"),
            fontSize(Float(32.)),
            marginBottom(Pt(20.)),
            fontWeight(`Bold)
          ])
      }
    )
  );

let component = reducerComponent("Welcome");

let getCurrentlyVisibleScreenId = (_event, self) =>
  Navigation.getCurrentlyVisibleScreenId()
  |> Js.Promise.then_(screen => {
       self.send(UpdateScreenId(screen##screenId));
       Js.Promise.resolve();
     })
  |> ignore;

let make = (~navigator, _children) => {
  ...component,
  initialState: () => {id: ""},
  reducer: (action, _state) =>
    switch action {
    | UpdateScreenId(id) => Update({id: id})
    },
  render: self =>
    <View style=styles##container>
      <Text style=styles##text> (stringToElement("Hello!")) </Text>
      <TouchableOpacity
        onPress=(_event => Navigation.showModal(~screen=screenId(Modal), ()))>
        <Text> (stringToElement("Open Modal")) </Text>
      </TouchableOpacity>
      <TouchableOpacity
        onPress=(
          _event => Navigator.push(~navigator, ~screen=screenId(About), ())
        )>
        <Text> (stringToElement("Open About")) </Text>
      </TouchableOpacity>
      <TouchableOpacity
        onPress=(
          _event => Navigation.showLightBox(~screen=screenId(LightBox), ())
        )>
        <Text> (stringToElement("Open LightBox")) </Text>
      </TouchableOpacity>
      <TouchableOpacity onPress=(self.handle(getCurrentlyVisibleScreenId))>
        <Text> (stringToElement("Get currently visible `screenId`")) </Text>
      </TouchableOpacity>
      <Text> (stringToElement(self.state.id)) </Text>
    </View>
};

let default = Utils.nativeScreen(~component, ~make);

Utils.setNavigatorStyle(
  ~nativeScreen=default,
  ~navigatorStyle=
    Navigator.Style.(
      create([
        navBarTextColor("#fff"),
        navBarNoBorder(true),
        navBarBackgroundColor("#2575E6")
      ])
    )
);
