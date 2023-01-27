# Game of Life

A [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway's_Game_of_Life) implementation written in C.

![GIF of game of life](./gifs/glider.gif)

## Build Dependencies
gcc <br />
ncurses library

## Installation

Clone the repository locally.

```bash
git clone https://github.com/jibrilfdev/game-of-life-c.git
cd game-of-life-c
gcc src/main.c -o life -l ncurses
```

## Usage

```bash
./life
```

ENTER on the main screen to go to the seed editor. Press x on a location to toggle the cell's status. Move locations using arrow keys or h, j, k, l. q to quit seed editor, and q to quit simulation loop.

![Screenshot of Game of Life title screen.](./screenshots/titlescreen.png)

![Screenshot of Game of Life in the middle of a simulation.](./screenshots/gamestate.png)

## Contributing

Pull requests are welcome. Issues are welcome, and will potentially be addressed.

## License

[MIT](https://choosealicense.com/licenses/mit/)
