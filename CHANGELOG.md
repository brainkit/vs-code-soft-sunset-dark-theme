# Changelog

All notable changes to this project will be documented in this file.

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
