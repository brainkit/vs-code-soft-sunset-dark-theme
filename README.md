# Soft Sunset Dark Theme

A warm sunset-inspired theme with harmonized color palette, optimized for relaxed coding sessions.

![Soft Sunset Dark Theme](https://img.shields.io/badge/VS%20Code-Soft%20Sunset%20Dark-purple?style=for-the-badge&logo=visual-studio-code)

## 🌅 Features

- **Harmonized Color Palette**: Warm sunset-inspired tones with consistent visual hierarchy
- **Eye-Friendly**: Designed for extended coding sessions with reduced eye strain
- **Enhanced Visual Coherence**: Unified color scheme eliminates visual dissonance
- **VS Code Compatible**: Fully compatible with VS Code 1.80.0 and later

## 📸 Preview

### JavaScript Syntax Highlighting

![JavaScript Demo](examples/javascript-demo.png)

### Interface Preview

![Interface Demo](examples/interface-demo.png)

## 📦 Installation

### From VS Code Marketplace

1. Open VS Code
2. Press `Ctrl+Shift+X` to open the Extensions panel
3. Search for "Soft Sunset Dark"
4. Click **Install**

[📥 Install from VS Code Marketplace](https://marketplace.visualstudio.com/items?itemName=brainkit.soft-sunset-dark)

### Manual Installation

1. Download the latest `.vsix` file from [Releases](https://github.com/brainkit/vs-code-soft-sunset-dark-theme/tree/main/releases)
2. In VS Code, press `Ctrl+Shift+P` and type "Extensions: Install from VSIX"
3. Select the downloaded `.vsix` file

## 🎨 Usage

1. After installation, press `Ctrl+Shift+P`
2. Type "Preferences: Color Theme" and press Enter
3. Select **Soft Sunset Dark** from the list

## 🔧 Сборка VSIX

1. Установите зависимости:

   ```bash
   npm install
   ```

2. Установите `vsce` (если ещё не установлен):

   ```bash
   npm install -g @vscode/vsce
   ```

   или запускайте через `npx` без глобальной установки.
3. Соберите пакет:

   ```bash
   npx vsce package
   ```

   В корне появится файл вида `soft-sunset-dark-x.y.z.vsix`.
4. Установите VSIX в VS Code: `Ctrl+Shift+P` → `Extensions: Install from VSIX...` → выберите полученный файл.

## ⚙️ Requirements

- VS Code version: `^1.80.0`
- Extension kind: `UI`

## 📄 License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## 👤 Author

**brainkit** - [Telegram](https://t.me/brainkit)

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 Changelog

### Version 0.0.27 (Current)

- **Color harmony improvements**: Replaced cold purple accents with warm sunset tones throughout the theme
- **Operator consistency**: Unified assignment operators (=) to match return keyword color for better visual coherence
- **Enhanced sunset palette**: Functions now use warmer green and keywords use sunset orange for improved thematic consistency
- **Interface cohesion**: All UI elements now follow the warm sunset color scheme

### Version 0.0.26

- **Minimap rendering fix**: Updated minimap background color to compensate for VS Code rendering artifacts
- **Color formula discovered**: Found optimal minimap color formula for perfect visual harmony
- **Minimap settings**: Maintained foreground opacity and disabled character rendering for optimal display

### Version 0.0.24

- **Variable color refinement**: Unified variables to warm sandy `#c8c0a8` for better harmony
- **Type hierarchy**: Classes/interfaces now brighter `#bca878`, primitive types darker `#a89868`
- **Boolean/null constants**: Aligned with primitive types for visual consistency
- **Import consistency**: Fixed mixed colors in Python/TypeScript imports

### Version 0.0.22

- **OLED-friendly contrast**: Brightened code tokens (keywords, operators, params, constants) without shifting hues for sharper legibility.
- **UI clarity**: Slightly lifted system text/icon brightness for cleaner separation against the dark canvas.
- **Harmony preserved**: Kept the sunset palette intact while improving readability.

### Version 0.0.17

- **Improved readability**: Enhanced comment contrast for comfortable reading
- **Better hierarchy**: Optimized variable and function colors for clearer code structure
- **Relaxed coding focus**: Fine-tuned colors to maintain the calm, sunset-inspired atmosphere
- **Consistency**: Unified improvements across both standard and OLED versions

### Version 0.0.5

- Updated theme colors for better contrast
- Improved syntax highlighting
- Enhanced editor workspace colors
- Better support for additional languages

### Version 0.0.4

- Initial release
- Soft sunset color palette
- Full VS Code integration
- Ready for marketplace publishing

### Version 0.0.1

- Initial development

---

Made with ❤️ for comfortable coding sessions
