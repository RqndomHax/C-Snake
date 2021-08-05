# 🐍 C_Snake

### Default config file
```yml
fps:        60 # This is the fps cap".
tickrate:   12 # This is the tick rate of the game, tickrate: 10 means 10 ticks per second.
speed:      1 # The amount of tick it takes to move the snake.
size:       4 # This is the default snake size".
booster:    1 # This is the size gained by the snake when it eats".
arena:      20 # This is the size of the arena (20 = 20x20)".
display:    sfml # This is the type of display of the game (ncurses / sfml)).
does_tp:    1 # If set to 1 the snake is tped to the other side of the map when going through a wall, else (0) it dies.
force_move: 1 # If set to 1 when a movement key is pressed the snake will move next turn.
```

##### Note that if a value is incorrect in the config file, it will be set to the default config values.

### Build

```bash
make
```

### Run

```bash
./c_snake
```

###### Examples

- Start the program with the desired config path (default `snake.cfg`)
```bash
./c_snake configPath
```

- Start the program with custom values to the tickrate, speed and size, the rest set from the default configPath
```bash
./c_snake --tickrate 250 --speed 23 --size 2
```

### Have fun playing my game !

###### Made with ❤️ by RqndomHax