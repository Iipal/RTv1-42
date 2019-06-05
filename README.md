# RTv1-42
## Ray Tracing Engine on C using SDL2. (project from [UNIT Factory](https://unit.ua/en/))
###### made by tmaluh __(\_ipal)__

![screenshot](https://github.com/Iipal/RTv1-42/blob/master/screenshot_all.png)

### Addiitonal pre-installation:
#### __SDL2__

__Ubuntu:__

```bash
$> sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
```

__Fedora:__

```bash
$> sudo dnf install SDL2-devel SDL2-image-devel SDL2_ttf-devel
```

__MacOS:__

```bash
$> brew install SDL2 SDL2_image SDL2_ttf
```

### Additional info:
This project inlcudes also a few my other projects. It's libraries [libft](https://github.com/Iipal/lft) and [libftsdl](https://github.com/Iipal/libftsdl).

## Compiling

Use [make](https://en.wikipedia.org/wiki/Makefile) for compiling all files.

When you have already installed SDL2 library you can use this simple rules:
- **make**: Compile all.
- **make clean**: Delete all RTv1, libft and libftsdl temporary files.
- **make del**: Delete temporary RTv1 files only.
- **make fclean**: Expands `make clean` to delete also executable RTv1, libraries libft and libftsdl.
- **make re**: It's rules - **make fclean** & **make** in one.
- **make pre**: It's rules - **make del** & **make** in one.
- **make debug**: Re-compile RTv1 without optimization flags but with `-g3` for debug.
- **make norme**: Check all libft, libftsdl and RTv1 `*.c` and `*.h` files for norme errors. (Works only on MacOS in school42)
###### If you change code use: `make del & make` or equal rule - `make pre` for re-compile only RTv1 executable without re-compile libft and libftsdl.
###### If you wants to re-compile libft and libftsdl for debug use: `make -C libft debug` and `make -C libftsdl debug`.

## Usage:

```bash
$> ./RTv1 [flags-params] scenes/<scene_name>.rtv1
```
### Flags:

| Flag              | Description                                                               | Shortcut | Valid values   | Default value | Value type | Dependency on `-dbg` mode |
| ----------------- | ------------------------------------------------------------------------- | -------- | -------------- | ------------- | ---------- | ------------------------- |
| --help            | Print short flags description. After print RTv1 will automatically close. | -h       | none           | none          | none       | no                        |
| --debug           | Enable keybinds switcher mode.                                            | -dbg     | none           | none          | none       |                           |
| --viewportScale   | How many times will be increased viewport.                                | -vps     | 1-10           | 1             | Integer    | no                        |
| --shadowBright    | How dark the shadows should be. (Less - brighter)                         | -sb      | 1-10           | 100           | Integer    | no                        |
| --fpsTextColor    | Render info text color.                                                   | -ftc     | All HEX values | 0x7FFF00      | HEX        | yes                       |
| --fpsFefreshTimer | How often will refresh fps counter. (in ms)                               | -frt     | 0-500          | 25            | Integer    | yes                       |
| --noCalcLight     | Disable calc all light origins.                                           | -ncl     | none           | none          | none       | no                        |
| --textured        | Enable textured rendering.                                                | -t       | none           | none          | none       | no                        |
| --printUsage      | Print usage for -dbg mode.                                                | -pu      | none           | none          | none       | yes                       |
#### Example:
```bash
$> ./RTv1 -vps 1 -sb 5 -ftc 0x5dba5f -dbg scenes/sphere.rtv1
```
###### Note: always put scene file in arguments line, because flags will parse only after successful read scene file.

# [[__`About scene file params`__](#about-scene-file-params)]:

| Param name | Description                                              | Position | Direction\Rotate    | Color | Radius\Angle | Specular\Intensity |
| ---------- | -------------------------------------------------------- | -------- | ------------------- | ----- | ------------ | ------------------ |
| Camera     | Scene camera. Only 1 camera can be in scene.             | X,Y,Z    | X,Y,Z (Z not used.) | none  | none         | none               |
| Light      | Scene light origin. Max 5 light origins can be in scene. | X,Y,Z    | X,Y,Z (not used.)   | none  | none         | 100                |
| Sphere     | Sphere object.                                           | X,Y,Z    | X,Y,Z (not used.)   | HEX.  | 1            | 10000              |
| Cone       | Cone object.                                             | X,Y,Z    | X,Y,Z               | HEX.  | 1            | 10000              |
| Cylinder   | Cylinder object.                                         | X,Y,Z    | X,Y,Z               | HEX.  | 1            | 10000              |
| Plane      | Cylinder object.                                         | X,Y,Z    | X,Y,Z               | HEX.  | none         | 10000              |
| eShadow.   | Enable shadows calc and render in scene.                 | none     | none                | noen  | none         | none               |

#### Example:
```bash
Camera: 0,0,0 0,0,0
Light: 0,3,1 0,0,0 100
Sphere: 0,-1,10 0,0,0 0xaaaaaa 1 30
Cone: -2,5,25 -1,-3,0 0xbaaf32 1 5000
Plane: 0,-5,0 0,1,0 0xfa1bff 500
Cylinder: 2,-2,5 -2,4,-3 0xbaaf32 1 1000
eShadow.
```


## Keybinds:

### General keybinds what works in all keybind modes:
| Description                   | Keybinding     |
| ----------------------------- | -------------- |
| Toggle on\off rendering info. | <kbd>Z</kbd>   |
| Exit.                         | <kbd>Esc</kbd> |

###### All binds below works only with `-dbg` flag.
## [[__`Keybinds mode switcher binds`__](#keybinds-mode-switcher-binds)]:
| Name                                                                                  | Description                                                                                                                                                                                                                                                                                                                                        | Keybinding        |
| ------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------- |
| Switcher keybind mode to control all light origins or objects.                        | After first press is active [__`Lights Control Mode`__](#lights-control-mode) keybinds, after second press - [__`Objects Control Mode`__](#objects-control-mode). Keybinds after third press retruns to [__`Default Camera Control Mode`__](#default-camera-control-mode). All keybinds valid for all light origins or objects dependecny on mode. | <kbd>X</kbd>      |
| Increase speed value for changing movements[default] or intensity\specular[optional]. |                                                                                                                                                                                                                                                                                                                                                    | <kbd>LShift</kbd> |
| Decrease speed value for changing movements[default] or intensity\specular[optional]. |                                                                                                                                                                                                                                                                                                                                                    | <kbd>LCtrl</kbd>  |
| Toggle on\off calculating and rendering shadows.                                      |                                                                                                                                                                                                                                                                                                                                                    | <kbd>H</kbd>      |
| Toggle on\off rendering textures.                                                     |                                                                                                                                                                                                                                                                                                                                                    | <kbd>Y</kbd>      |
| Toggle on\off calculating light origins                                               |                                                                                                                                                                                                                                                                                                                                                    | <kbd>N</kbd>      |

### [[__`Default Camera Control Mode`__](#default-camera-control-mode)]:
| Description                       | Keybinding   |
| --------------------------------- | ------------ |
| Move camera up.                   | <kbd>W</kbd> |
| Move camera left.                 | <kbd>A</kbd> |
| Move camera down.                 | <kbd>S</kbd> |
| Move camera right.                | <kbd>D</kbd> |
| Move camera backward.             | <kbd>Q</kbd> |
| Move camera forward.              | <kbd>E</kbd> |
| Increase camera rotate by X-axis. | <kbd>R</kbd> |
| Increase camera rotate by Y-axis. | <kbd>F</kbd> |
| Increase camera rotate by Z-axis. | <kbd>V</kbd> |
| Decrease camera rotate by X-axis. | <kbd>T</kbd> |
| Decrease camera rotate by Y-axis. | <kbd>G</kbd> |
| Decrease camera rotate by Z-axis. | <kbd>B</kbd> |
### [[__`Lights Control Mode`__](#lights-control-mode)]:
| Description                          | Keybinding   |
| ------------------------------------ | ------------ |
| Move lights up.                      | <kbd>W</kbd> |
| Move lights left.                    | <kbd>A</kbd> |
| Move lights down.                    | <kbd>S</kbd> |
| Move lights right.                   | <kbd>D</kbd> |
| Move lights forward.  [default]      | <kbd>E</kbd> |
| Move lights backward. [default]      | <kbd>Q</kbd> |
| Switch to control lights intensity.  | <kbd>C</kbd> |
| Decrease lights inensity. [optional] | <kbd>Q</kbd> |
| Increase lights inensity. [optional] | <kbd>E</kbd> |
## [[__`Objects Control Mode`__](#objects-control-mode)]:
| Description                           | Keybinding   |
| ------------------------------------- | ------------ |
| Move objects up.                      | <kbd>W</kbd> |
| Move objects left.                    | <kbd>A</kbd> |
| Move objects down.                    | <kbd>S</kbd> |
| Move objects right.                   | <kbd>D</kbd> |
| Move objects forward.  [default]      | <kbd>E</kbd> |
| Move objects backward. [default]      | <kbd>Q</kbd> |
| Switch to control objects specular.   | <kbd>C</kbd> |
| Decrease objects specular. [optional] | <kbd>Q</kbd> |
| Increase objects specular. [optional] | <kbd>E</kbd> |
| Increase objects rotate by X-axis.    | <kbd>R</kbd> |
| Increase objects rotate by Y-axis.    | <kbd>F</kbd> |
| Increase objects rotate by Z-axis.    | <kbd>V</kbd> |
| Decrease objects rotate by X-axis.    | <kbd>T</kbd> |
| Decrease objects rotate by Y-axis.    | <kbd>G</kbd> |
| Decrease objects rotate by Z-axis.    | <kbd>B</kbd> |