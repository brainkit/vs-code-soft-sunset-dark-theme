# Changelog

All notable changes to this project will be documented in this file.

## [0.0.33] - 2026-09-06

### Fixed
- **Broken README images on the Marketplace**: The `repository` URL in `package.json` pointed to `brainkit/liteapi` since 0.0.28, so the Marketplace resolved `examples/*.png` against the wrong repository (404). Restored `brainkit/vs-code-soft-sunset-dark-theme`

## [0.0.31] - 2026-09-05

### Changed
- **Greyer, dimmer thread lines**: Shifted `sideBarActivityBarTop.border`, `sideBarSectionHeader.border`, `widget.border`, `tree.indentGuidesStroke` and `chat.requestBorder` from `#4a4034` to `#403b35` so the Claude Code timeline line sits closer to the neutral panel edge tone

## [0.0.30] - 2026-09-05

### Changed
- **Softer thread and guide lines**: Toned down `sideBarActivityBarTop.border`, `sideBarSectionHeader.border`, `tree.indentGuidesStroke` and `chat.requestBorder` from `#6a5c4a` to `#4a4034` so the Claude Code timeline line and panel borders match the theme's existing border tone instead of standing out

## [0.0.29] - 2026-09-05

### Changed
- **Visible thread lines in Claude Code panel**: Added `sideBarActivityBarTop.border` (`#6a5c4a`), which the Claude Code chat webview uses for its message timeline line; previously undefined, so the line was invisible
- **Tree indent guides**: Brightened `tree.indentGuidesStroke` from `#302a20` to `#6a5c4a` so nested items in trees and chat tool calls read clearly
- **Chat colors**: Added `chat.*` workbench colors (request border/background, slash commands, avatar) in the warm sunset palette
- **Borders**: Added `sideBarSectionHeader.border` and `widget.border` for consistent separators

### Documentation
- README rewritten in English and simplified; changelog now lives only in CHANGELOG.md

## [0.0.28] - 2026-02-10

### Changed
- **Pale coral accent**: Introduced a desaturated coral (`#c48474`) for keywords, interfaces, classes, operators and symbol icons to better match the warm sunset background
- **Python + TypeScript parity**: Unified Python type/class scopes and TypeScript storage tokens to the new accent for consistent semantics across languages
- **Operator polish**: Harmonized `new`, logical, comparison and assignment operators (JS/TS/Python/PHP) with the updated accent so code structure reads as a single layer

### Technical Details
- Updated all semantic tokens and token color scopes referencing the previous coral shades (#c47c74 → #c07868 → #c48474) to keep palette coherent
- Synced symbol icon colors and UI highlights with the new tone for sidebar/tree parity

## [0.0.27] - 2026-02-10

### Changed
- **Color harmony improvements**: Replaced cold purple accents (#a890b0) with warm sunset tones (#c47c74) throughout the theme
- **Operator consistency**: Unified assignment operators (=) to match return keyword color for better visual coherence
- **Enhanced sunset palette**: Functions now use warmer green (#acbc84) and keywords use sunset orange (#d49484) for improved thematic consistency
- **Interface cohesion**: All UI elements now follow the warm sunset color scheme, eliminating visual dissonance

### Technical Details
- Updated over 50 token color definitions to maintain sunset theme integrity
- Improved color hierarchy for better code readability
- Maintained contrast ratios while enhancing visual warmth

## [0.0.26] - 2025-12-28

### Changed
- **Minimap rendering fix**: Updated minimap background color from `#24201a` to `#25201a` to compensate for VS Code rendering artifacts
- **Color formula discovered**: Found optimal minimap color formula (R+1, G=same, B=same) for perfect visual harmony with main editor background
- **Minimap settings**: Maintained `foregroundOpacity: #000000fc` (99%) and `renderCharacters: false` for optimal rendering

### Technical Details
- VS Code uses different rendering mechanisms for minimap (canvas with reduced scale) causing visual color differences
- The discovered formula compensates for these rendering artifacts while maintaining theme consistency
- Minimap now visually matches the main editor background despite underlying color code differences

## [0.0.25] - Previous

### Features
- Soft sunset color palette with neon tones and coastline hues
- Optimized for relaxed coding sessions
- Dark theme variant for VS Code
