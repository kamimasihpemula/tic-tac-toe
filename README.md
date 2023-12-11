# Tic Tac Toe

## Description

This is a console-based Tic Tac Toe game implemented in C. The game features a simple user interface, multiple game modes (player vs. player, player vs. computer), a shop to purchase in-game sounds, and a history system to track game results.

## Features

- Player vs. Player (PvP) mode
- Player vs. Computer (PvC) mode with adjustable difficulty
- Shop to purchase in-game sounds
- History system to track game results
- Settings to configure game options and sounds

## How to Play

1. Clone the repository to your local machine.
2. Open a terminal and navigate to the project directory.

### Compilation

- If you have `make` installed:

  ```bash
  make
  ```

- If you don't have `make`, manually compile the code using `gcc`:

  ```bash
  gcc -Wall -Wextra -std=c11 -o bin/tictactoe.exe src/main.c -lwinmm
  ```

3. To run the Tic Tac Toe game, execute the generated executable:

   ```bash
   ./bin/tictactoe.exe
   ```

## Build and Run (Including Unit Tests)

To build the game and run unit tests without `make`, follow these steps:

```bash
# Compile the code and generate the executable
gcc -Wall -Wextra -std=c11 -o bin/tictactoe.exe src/main.c -lwinmm
```

```bash
# Run the Tic Tac Toe game
./bin/tictactoe.exe
```

```bash
# Compile and run unit tests
gcc -Wall -Wextra -std=c11 -o bin/unit_test.exe test/test_main.c -lwinmm
./bin/unit_test.exe
```

## Dependencies

- Windows Multimedia API (winmm)
- Unity Testing Framework: [Unity](https://github.com/ThrowTheSwitch/Unity)

## Directory Structure

- `src`: Contains the main source code files.
- `test`: Includes unit test source files.
- `bin`: The directory where executable files are generated.
- `build`: Holds object files and other build-related files.

## License

This project is licensed under the [MIT License](LICENSE).
