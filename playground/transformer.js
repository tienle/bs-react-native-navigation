const path = require('path')
const babel = require('babel-core')

const moduleResolverPlugin = require('babel-plugin-module-resolver').default
const reactNativePreset = require('babel-preset-react-native')

const transform = ({ src, filename }) => {
  const config = {
    filename,
    sourceFileName: filename,
    babelrc: false,
    presets: [
      reactNativePreset,
    ],
    plugins: [
      [moduleResolverPlugin, {
        alias: {
          'react-native': path.resolve(__dirname, 'node_modules', 'react-native'),
          'react-native-navigation': path.resolve(__dirname, 'node_modules', 'react-native-navigation'),
        },
      }],
    ],
  }
  const { ast, code, map } = babel.transform(src, config)

  return {
    ast,
    code,
    map,
    filename,
  }
}

module.exports = {
  transform,
}
