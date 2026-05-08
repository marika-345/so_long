_This project has been created as part of the 42 curriculum by mgumberi._

# so_long

A small 2D game written in C using the **MiniLibX** graphical library.
The player must collect every collectible on the map and then reach the exit
in the fewest moves possible.

## Description

`so_long` opens a window, reads a map description from a `.ber` file, and lets
the user move a character around with **W / A / S / D** (or the arrow keys).
The current move count is printed in the shell after every successful move.
The window can be closed cleanly with **ESC** or by clicking the close button
on the window frame. When the player has picked up every collectible and steps
onto the exit, the program prints the final move count and exits cleanly.

The mandatory part is implemented; the bonus part is not.

### Map format (`.ber`)

| char | meaning            |
|------|--------------------|
| `0`  | empty (walkable)   |
| `1`  | wall               |
| `C`  | collectible        |
| `E`  | exit               |
| `P`  | player start       |

A valid map must:

- be rectangular
- be fully enclosed in walls
- contain exactly one `P` and one `E`, and at least one `C`
- have a path from `P` to every `C` and to `E`

If any rule is broken the program prints `Error\n` followed by an explicit
message on stderr and exits with status 1.

## Instructions

### Build

```sh
make
```

This first builds `libft`, then `minilibx-linux`, then the `so_long` binary.

The MiniLibX `configure` script needs the X11 development headers
(`libx11-dev`, `libxext-dev`) and OpenGL headers; on the school machines they
are already installed.

### Run

```sh
./so_long maps/map_simple.ber
./so_long maps/map_medium.ber
```

Try the failing maps to see the error messages:

```sh
./so_long maps/invalid/not_rectangular.ber
./so_long maps/invalid/not_closed.ber
./so_long maps/invalid/no_path.ber
./so_long maps/invalid/no_collectible.ber
./so_long maps/invalid/duplicate_player.ber
./so_long maps/invalid/bad_char.ber
```

### Controls

| key                | action       |
|--------------------|--------------|
| `W` / `↑`          | move up      |
| `S` / `↓`          | move down    |
| `A` / `←`          | move left    |
| `D` / `→`          | move right   |
| `ESC`              | quit         |
| close button       | quit         |

## Layout

```
so_long/
├── Makefile
├── README.md
├── includes/so_long.h
├── libft/                # copy of my libft
├── minilibx-linux/       # bundled MiniLibX sources
├── src/                  # 10 .c files, see below
├── textures/*.xpm        # wall, floor, player, coin, exit (32×32)
└── maps/*.ber            # valid + invalid example maps
```

Source files (split by responsibility, all Norm-compliant):

| file              | role                                              |
|-------------------|---------------------------------------------------|
| `main.c`          | argv check, parse phase, graphics phase           |
| `error.c`         | `error_exit`, `init_game`, `has_extension`        |
| `map_read.c`      | read `.ber`, sanity-check newlines, split lines   |
| `map_validate.c`  | dimensions, borders, char set, P/E/C counts       |
| `map_path.c`      | recursive flood-fill reachability check           |
| `game_init.c`     | `mlx_init`, window, load XPM textures             |
| `render.c`        | redraw the whole frame                            |
| `input.c`         | key & destroy hooks                               |
| `move.c`          | movement logic + collectibles + exit condition    |
| `cleanup.c`       | image / window / display destruction, free helper |

## Resources

- 42 subject — *So Long, And thanks for all the fish!* (v5.0)
- MiniLibX manual pages (`minilibx-linux/man/man3/*`)
- *The Hitchhiker's Guide to the MiniLibX* — Harm Smits' tutorial
- X11 keysym values for keyboard handling (`/usr/include/X11/keysymdef.h`)
- The XPM format specification

### Use of AI

AI was used as a **pair-programming assistant** for:

- drafting the project skeleton (file split, struct layout, Makefile shape) so
  the implementation could focus on game logic
- reviewing the flood-fill reachability check and the partial-cleanup paths
  for memory-leak risks
- generating placeholder XPM textures procedurally

All generated code was read, edited and tested before commit; nothing is
included that I cannot explain in defense.
