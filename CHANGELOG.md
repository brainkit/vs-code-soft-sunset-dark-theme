# Changelog

All notable changes to this project will be documented in this file.

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
