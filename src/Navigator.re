module Style = {
  type t;
  type styleElement = (string, Js.Json.t);
  external asStyle : Js.Dict.t(Js.Json.t) => t = "%identity";
  let create = list => list |> Js.Dict.fromList |> asStyle;
  let toBool = (key, value) => (
    key,
    Encode.boolean(Js.Boolean.to_js_boolean(value))
  );
  let toString = (key, value) => (key, Encode.string(value));
  let toFloat = (key, value) => (key, Encode.float(value));
  let toObject = (key, value) => (key, Encode.object_(value));
  let toInt = (key, value) => (key, Encode.int(value));
  let navBarTextColor = toString("navBarTextColor");
  let navBarTextFontSize = toFloat("navBarTextFontSize");
  let navBarTextFontFamily = toString("navBarTextFontFamily");
  let navBarBackgroundColor = toString("navBarBackgroundColor");
  /* TODO: asScreen! */
  let navBarCustomView = toString("navBarBackgroundColor");
  type navBarComponentAlignment =
    | Center
    | Fill;
  let navBarComponentAlignment = value =>
    toString(
      "navBarComponentAlignment",
      switch value {
      | Center => "center"
      | Fill => "fill"
      }
    );
  let navBarCustomViewInitialProps = toObject("navBarCustomViewInitialProps");
  let navBarButtonColor = toString("navBarButtonColor");
  let topBarElevationShadowEnabled = toBool("topBarElevationShadowEnabled");
  let navBarHidden = toBool("navBarHidden");
  let navBarHideOnScroll = toBool("navBarHideOnScroll");
  let navBarTranslucent = toBool("navBarTranslucent");
  let navBarTransparent = toBool("navBarTransparent");
  let navBarNoBorder = toBool("navBarNoBorder");
  let drawUnderNavBar = toBool("drawUnderNavBar");
  let drawUnderTabBar = toBool("drawUnderTabBar");
  let navBarBlur = toBool("navBarBlur");
  let tabBarHidden = toBool("tabBarHidden");
  let statusBarHidden = toBool("statusBarHidden");
  type statusBarTextColorScheme =
    | Dark
    | Light;
  let _statusBarTextColorScheme =
    fun
    | Dark => "dark"
    | Light => "light";
  let statusBarTextColorScheme = value =>
    toString("statusBarTextColorScheme", _statusBarTextColorScheme(value));
  let navBarSubtitleColor = toString("navBarSubtitleColor");
  let navBarSubtitleFontFamily = toString("navBarSubtitleFontFamily");
  let navBarSubtitleFontSize = toFloat("navBarSubtitleFontSize");
  let screenBackgroundColor = toString("screenBackgroundColor");
  type orientation =
    | Auto
    | Portrait
    | Landscape;
  let orientation = value =>
    toString(
      "orientation",
      switch value {
      | Auto => "auto"
      | Portrait => "portrait"
      | Landscape => "landscape"
      }
    );
  let disabledButtonColor = toString("disabledButtonColor");
  let statusBarTextColorSchemeSingleScreen = value =>
    toString(
      "statusBarTextColorSchemeSingleScreen",
      _statusBarTextColorScheme(value)
    );
  let statusBarHideWithNavBar = toBool("statusBarHideWithNavBar");
  let statusBarBlur = toBool("statusBarBlur");
  let disabledBackGesture = toBool("disabledBackGesture");
  let disabledSimultaneousGesture = toBool("disabledSimultaneousGesture");
  /* TODO: screenBackgroundImageName */
  /* TODO: rootBackgroundImageName */
  let navBarButtonFontSize = toInt("navBarButtonFontSize");
  let _fontWeight =
    fun
    | `Normal => "normal"
    | `Bold => "bold"
    | `_100 => "100"
    | `_200 => "200"
    | `_300 => "300"
    | `_400 => "400"
    | `_500 => "500"
    | `_600 => "600"
    | `_700 => "700"
    | `_800 => "800"
    | `_900 => "900";
  let navBarButtonFontWeight = value =>
    toString("navBarButtonFontWeight", _fontWeight(value));
  let navBarLeftButtonFontSize = toFloat("navBarLeftButtonFontSize");
  let navBarLeftButtonColor = toString("navBarLeftButtonColor");
  let navBarLeftButtonFontWeight = value =>
    toString("navBarLeftButtonFontWeight", _fontWeight(value));
  let navBarRightButtonFontSize = toInt("navBarRightButtonFontSize");
  let navBarRightButtonColor = toString("navBarRightButtonColor");
  let navBarRightButtonFontWeight = value =>
    toString("navBarRightButtonFontWeight", _fontWeight(value));
  let topBarShadowColor = toString("topBarShadowColor");
  let topBarShadowOpacity = toFloat("topBarShadowOpacity");
  let topBarShadowOffset = toFloat("topBarShadowOffset");
  let topBarShadowRadius = toFloat("topBarShadowRadius");
  /* TODO: preferredContentSize */
  type modalPresentationType =
    | FormSheet
    | PageSheet
    | OverFullScreen
    | OverCurrentContext
    | FullScreen;
  let modalPresentationStyle = value =>
    toString(
      "modalPresentationStyle",
      switch value {
      | FormSheet => "formSheet"
      | PageSheet => "pageSheet"
      | OverFullScreen => "overFullScreen"
      | OverCurrentContext => "overCurrentContext"
      | FullScreen => "fullScreen"
      }
    );
  let largeTitle = toBool("largeTitle");
  let navigationBarColor = toString("navigationBarColor");
  let navBarTitleTextCentered = toBool("navBarTitleTextCentered");
  let navBarButtonFontFamily = toString("navBarButtonFontFamily");
  let statusBarColor = toString("statusBarColor");
  let drawUnderStatusBar = toBool("drawUnderStatusBar");
  /* TODO: require (local image) */
  let collapsingToolBarImage = toString("collapsingToolBarImage");
  let collapsingToolBarCollapsedColor =
    toString("collapsingToolBarCollapsedColor");
  let navBarTextFontBold = toBool("navBarTextFontBold");
  let navBarHeight = toInt("navBarHeight");
  let navBarTopPadding = toInt("navBarTopPadding");
  let topTabsHeight = toInt("topTabsHeight");
  let topBarBorderColor = toString("topBarBorderColor");
  let topBarBorderWidth = toFloat("topBarBorderWidth");
};
