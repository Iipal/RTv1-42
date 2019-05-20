# RTv1-42
## Ray Tracing Engine on C using SDL2. (project from [UNIT Factory](https://unit.ua/en/))
###### made by tmaluh __(\_ipal)__

## Addiitonal pre-installation:

### SDL2

__*Ubuntu:*__

```bash
$> sudo apt-get install libsdl2-dev libsdl2-ttf-dev
```

__*Fedora:*__

```bash
$> sudo dnf install SDL2-devel SSDL2_ttf-devel
```

__*MacOS:*__

All ready for use. Just type **make**.

__*Windows:*__

- [MinGW](http://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/mingw/index.php).
- [Visual Studio](http://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/msvsnet2010u/index.php).

## Additional info:
This project inlcudes also a few my other projects. It's library [libft] and [libftsdl]

## Compiling

Use [make](https://en.wikipedia.org/wiki/Makefile) for compiling all files.

When you have already installed SDL2 library you can use this simple rules:
- **make**: Compile all.
- **make clean**: Delete all RTv1, libft and libftsdl temporary files.
- **makde del**: Delete temporary RTv1 files only.
- **make fclean**: Expands `make clean` to delete also executable RTv1, libraries libft and libftsdl.
- **make re**: It's rules - **make fclean** & **make** in one.
- **make pre**: It's rules - **make del** & **make** in one.
- **make debug**: Re-compile RTv1 without optimization flags but with `-g3` for debug.
###### If you change code use: `make del & make` or equal rule - `make pre` for re-compile only RTv1 executable without re-compile libft and libftsdl.
###### If you wants to re-compile libft and libftsdl for debug use: `make -C libft debug` and `make -C libftsdl debug`.

## Usage:

```bash
$> ./RTv1 [flags-params] scenes/<scene_name>.rtv1
```
### Flags:

| Flag             | Description                                                               | Shortcut | Valid values | Default value | Value type |
| ---------------- | ------------------------------------------------------------------------- | -------- | ------------ | ------------- | ---------- |
| --help           | Print short flags description. After print RTv1 will automatically close. | -h       | none         | none          | none       |
| --viewport-scale | How many times will be increased viewport.                                | -vps     | 1-10         | 1             | Integer    |
| --shadow-bright  | How dark the shadows should be. (Less - brighter)                         | -sb      | 1-10         | 100           | Integer    |  | --help | Print short flags description. After print RTv1 will automaticly close. | -h | none | none | none |
| --fps-text-color | Render info text color.                                                   | -ftc     | All HEX values | 0x7FFF00      | HEX        |
#### Example:
```bash
$> ./RTv1 -vps 1 -sb 5 -ftc 0x5dba5f scenes/sphere.rtv1
```
###### Note: always put scene file in arguments line, because flags will parse only after successful read scene file.

## Keybinds:

### General keybinds in all keybind modes:
| Description                | Keybinding     |
| -------------------------- | -------------- |
| Show render info. (FPS\ms) | <kbd>Z</kbd>   |
| Exit.                      | <kbd>Esc</kbd> |

## Keybinds mode switcher binds:
| Name                                                                                  | Description                                                                                                                                                                                                                                                                                                                                        | Keybinding        |
| ------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------- |
| Switcher keybind mode to control all light origins or objects.                        | After first press is active [__`Lights Control Mode`__](#lights-control-mode) keybinds, after second press - [__`Objects Control Mode`__](#objects-control-mode). Keybinds after third press retruns to [__`Default Camera Control Mode`__](#default-camera-control-mode). All keybinds valid for all light origins or objects dependecny on mode. | <kbd>X</kbd>      |
| Increase speed value for changing movements[default] or intensity\specular[optional]. |                                                                                                                                                                                                                                                                                                                                                    | <kbd>LShift</kbd> |
| Decrease speed value for changing movements[default] or intensity\specular[optional]. |                                                                                                                                                                                                                                                                                                                                                    | <kbd>LCtrl</kbd>  |

### [[__`Default Camera Control Mode`__](#default-camera-control-mode)]:
| Description           | Keybinding   |
| --------------------- | ------------ |
| Move camera up.       | <kbd>W</kbd> |
| Move camera left.     | <kbd>A</kbd> |
| Move camera down.     | <kbd>S</kbd> |
| Move camera right.    | <kbd>D</kbd> |
| Move camera backward. | <kbd>Q</kbd> |
| Move camera forward.  | <kbd>E</kbd> |

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
