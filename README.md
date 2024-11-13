# Cub3D - A RayCasting Adventure

## Overview
Cub3D is a ray-casting project inspired by the legendary Wolfenstein 3D game. Built using C and miniLibX, this project allows you to experience a maze from a first-person perspective, implementing fundamental techniques of ray-casting for 3D rendering.

## Features
- Realistic 3D graphical representation of mazes using ray-casting.
- Texture support for walls, varying based on direction (North, South, East, West).
- Configurable floor and ceiling colors.
- Responsive controls to navigate the maze:
  - Arrow keys for changing direction.
  - `W`, `A`, `S`, `D` keys for moving forward, left, backward, and right.
  - `ESC` to close the game.
- Map files with `.cub` extensions for scene configuration.

## Installation and Usage
### Clone the Repository
First, clone the repository and navigate into the project directory:
```bash
git clone https://github.com/ganievv/Cub3D.git
cd Cub3D
```
### Compilation
Run the following command:
```bash
make
```
This generates the `cub3D` executable.

### Running the Game
Provide a `.cub` file as an argument:
```bash
./cub3D <path/to/scene.cub>
```

## Map Format
A valid `.cub` file example:
```
NO ./path_to_the_north_texture.png
SO ./path_to_the_south_texture.png
WE ./path_to_the_west_texture.png
EA ./path_to_the_east_texture.png
F 220,100,0
C 225,30,0
111111
100101
101001
1100N1
111111
```

- **Map Symbols:**
  - `0` - Empty space
  - `1` - Wall
  - `N/S/E/W` - Player start position and orientation

## Controls
- **Movement**: `W` (forward), `A` (left), `S` (backward), `D` (right)
- **Rotation**: Left/Right arrow keys
- **Quit**: Press `ESC` or close the window via the red cross

## Project Structure
- **src/** - Source code files
- **include/** - Header files
- **maps/** - Sample map files
- **textures/** - Custom textures used in the project
- **libft/** - Custom C library used for utility functions
- **Makefile** - Build automation script

## Examples
Check out some examples of what the project looks like with different map configurations in the `maps/` directory!

