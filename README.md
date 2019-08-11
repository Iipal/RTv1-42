# RTv1-42
## Ray Tracing Engine on C using SDL2. (project from school42([UNIT Factory](https://unit.ua/en/)))
###### made by tmaluh __(\_ipal)__

![screenshot](https://github.com/Iipal/RTv1-42/blob/master/screenshot_all.png)

### Addiitonal SDL2 pre-installation:

__Ubuntu, Debian__:
```bash
$> sudo apt-get install libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev
```

__Fedora:__

```bash
$> sudo dnf install SDL2-devel SDL2_ttf-devel SDL2_image-devel
```

__MacOS:__

```bash
$> brew install sdl2 sdl2_image sdl2_ttf
```

###### I'm not tested this on other OS or distros.

### Additional info:
This project inlcudes also a few my other projects. It's libraries [libvectors](https://github.com/Iipal/libvectors), [libft](https://github.com/Iipal/lft) and [libftsdl](https://github.com/Iipal/libftsdl), and 1 other - forked [parson](https://github.com/Iipal/parson)

## Compiling

Use [make](https://en.wikipedia.org/wiki/Makefile) for compiling all files.

When you have already installed SDL2 library you can use this simple rules:
- **make**: Compile all.
- **make clean**: Delete all RTv1, libft and libftsdl temporary files.
- **make del**: Delete temporary RTv1 files only.
- **make fclean**: Expands `make clean` to delete also executable RTv1, libraries libft and libftsdl.
- **make re**: It's rules - **make fclean** & **make** in one.
- **make pre**: It's rules - **make del** & **make** in one.
- **make profie_all**: Re-compile all RTv1 source files without optimization flags but with `-no-pie -pg -O0` for profiling.
- **make debug_all**: Re-compile all RTv1 source files without optimization flags but with `-g3` for debug.
- **make profile**: Compile RTv1 source files without optimization flags but with `-no-pie -pg -O0` for profiling.
- **make debug**: Compile RTv1 source files without optimization flags but with `-g3` for debug.
- **make norme**: Check all libft, libftsdl and RTv1 `*.c` and `*.h` files for norme errors. (Works only on MacOS in school42)
> If you change RTv1 source code use: `make del & make` or equal rule - `make pre` for re-compile only RTv1 executable without re-compile libft and libftsdl.
>
> If you chnage libft or libftsdl source code use: `make -C libft` or `cd libft && make` || `make -C libftsdl` or `cd libftsdl && make`
>
> If you wants to re-compile libft and libftsdl for debug use: `make -C libft debug_all` and `make -C libftsdl debug_all`.

## Usage:

```bash
$> ./RTv1 [flags-params] scenes/<scene_name>.rtv1
```
### Flags:

| Flag                  | Description                                                               | Shortcut | Valid values   | Default value | Value type | Dependency on `-dbg` mode |
| --------------------- | ------------------------------------------------------------------------- | -------- | -------------- | ------------- | ---------- | ------------------------- |
| --help                | Print short flags description. After print RTv1 will automatically close. | -h       | none           | none          | none       | no                        |
| WITH PARAMS:          |                                                                           |          |                |               |            |                           |
| --viewportScale       | How many times will be increased viewport.                                | -vps     | 0.000001-10.0  | 1.0           | Float      | no                        |
| --ambientLight        | On how much shadow must be darker. (Greater - brighter)                   | -al      | 0.000001-100.0 | 0.0           | Float      | no                        |
| --fpsTextColor        | FPS counter info text color.                                              | -ftc     | All HEX values | 0x7FFF00      | HEX        | yes                       |
| --fpsRefreshTimer     | How often will refresh FPS counter. (in ms)                               | -frt     | 0-500          | 25            | Integer    | yes                       |
| --antiAliasing        | Enable simplified anti-aliasing algorithm.                                | -aa      | 2-16           | 0             | Integer    | no                        |
| BOOLEAN:              |                                                                           |          |                |               |            |                           |
| --debug               | Enable keybinds switcher(debug) mode.                                     | -dbg     | none           | not enabled   | none       |                           |
| --noCalcLight         | Disable calc all light origins.                                           | -ncl     | none           | not enabled   | none       | no                        |
| --textured            | Enable textured rendering.                                                | -t       | none           | not enabled   | none       | no                        |
| --randomLightsIntense | Enable randomaize lights intense.                                         | -rli     | none           | not enabled   | none       | yes                       |
| --printUsage          | Print usage for -dbg mode.                                                | -pu      | none           | not enabled   | none       | yes                       |
| OTHER:                |                                                                           |          |                |               |            |                           |
| --noBorder            | Create window without borders.                                            | -nb      | none           | not enabled   | none       | no                        |

###### Note: always put scene file in arguments line, because flags will parse only after successful read scene file.
#### Example:
```bash
$> ./RTv1 --debug -vps 0.5 -t -pu -ftc 0x1 -frt 0 -al 10 -nb -aa 4 scenes/sphere.rtv1
```

## Keybinds:
###### All binds below works only with `-dbg` flag.

### General keybinds what works in all keybind modes:
| Description                                                                   | Keybinding     |
| ----------------------------------------------------------------------------- | -------------- |
| Toggle on\off rendering info.                                                 | <kbd>Z</kbd>   |
| Toggle on\off calculating and rendering shadows. (__`eShadows`__ scene param) | <kbd>H</kbd>   |
| Toggle on\off rendering textures. (-t)                                        | <kbd>Y</kbd>   |
| Toggle on\off calculating light origins. (-ncl)                               | <kbd>N</kbd>   |
| Exit.                                                                         | <kbd>Esc</kbd> |

## [[__`Keybinds mode switcher binds`__](#keybinds-mode-switcher-binds)]:
| Name                                                           | Description                                                                                                                                                                                                                                                                                                                                        | Keybinding        |
| -------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------- |
| Switcher keybind mode to control all light origins or objects. | After first press is active [__`Lights Control Mode`__](#lights-control-mode) keybinds, after second press - [__`Objects Control Mode`__](#objects-control-mode). Keybinds after third press retruns to [__`Default Camera Control Mode`__](#default-camera-control-mode). All keybinds valid for all light origins or objects dependecny on mode. | <kbd>X</kbd>      |
| Increase speed value.                                          | Increase speed value for changing movements[default] or intensity\specular[optional].                                                                                                                                                                                                                                                              | <kbd>LShift</kbd> |
| Decrease speed value.                                          | Decrease speed value for changing movements[default] or intensity\specular[optional].                                                                                                                                                                                                                                                              | <kbd>LCtrl</kbd>  |

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
### [[__`Objects Control Mode`__](#objects-control-mode)]:
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


## Profilig (with gprof, gprof2dot and graphviz):

For re-compile whole project for correct profiling use this command:
```bash
$> make profile_allr
```
After re-compile just run `./RTv1`. More info about profiling on [eax.me](https://eax.me/c-cpp-profiling/)(RU).

Example on:
```bash
$> ./RTv1 -dbg scenes/sphere.json
```
![./RTv1 -dbg scenes/sphere.json](https://github.com/Iipal/RTv1-42/blob/master/profiles/RTV1_sphere.svg)

Example on:
```bash
$> ./RTv1 -dbg scenes/all.json
```
![./RTv1 -dbg scenes/all.json](https://github.com/Iipal/RTv1-42/blob/master/profiles/RTv1_all.svg)
![./RTv1 -dbg scenes/all.json](https://github.com/Iipal/RTv1-42/blob/master/profiles/RTv1_all_v2.svg)

Example on:
```bash
$> ./RTv1 scenes/all.json
```
![./RTv1 scenes/all.json](https://github.com/Iipal/RTv1-42/blob/master/profiles/RTv1_no_dbg_all.svg)

Example on:
```bash
$> ./RTv1 scenes/sphere.json
```
![./RTv1 scenes/sphere.json](https://github.com/Iipal/RTv1-42/blob/master/profiles/RTv1_no_dbg_sphere.svg)
