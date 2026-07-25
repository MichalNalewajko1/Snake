# Snake

A polished, lightweight implementation of the classic Snake game written in modern C++ and built with CMake. This project focuses on simplicity, readability, and portability — a great starting point for learning game loops, input handling, and basic game design in C++.

Languages: C++ (primary), CMake (build)

## Features

- Classic Snake gameplay (eat, grow, avoid collisions)
- Simple, easy-to-read C++ codebase suitable for learning
- Cross-platform build using CMake
- Configurable gameplay parameters (board size, speed)
- Keyboard controls (arrow keys and WASD)

## Requirements

- A C++ compiler with C++17 support (gcc, clang, MSVC, etc.)
- CMake 3.10 or newer
- (Optional) Any platform-specific dependencies if the project uses a graphics/audio library — see the source or CMakeLists.txt for details.

## Build Instructions

1. Clone the repository
   ```bash
   git clone https://github.com/MichalNalewajko1/Snake.git
   cd Snake
   ```

2. Create a build directory and compile
   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build . --config Release
   ```

3. Run the game
   - On Linux / macOS:
     ```bash
     ./Snake
     ```
   - On Windows (from the build folder):
     ```powershell
     .\Release\Snake.exe
     ```

If CMake options or dependency steps are required (for example, installing SDL2 or SFML), consult the top of `CMakeLists.txt` or the source README sections and install the required libraries before running CMake.

## Usage & Controls

- Move the snake: Arrow keys or W/A/S/D
- Pause/resume: P or Space (if implemented)
- Quit: Esc or close window

Check the source or comments for exact key mappings if they differ.

## Configuration

Board size, initial speed, and other gameplay parameters can typically be configured in the source files or as compile-time options in `CMakeLists.txt`. Search for constants like `BOARD_WIDTH`, `BOARD_HEIGHT`, or `SPEED` to adjust game behavior.

## Contributing

Contributions are welcome! If you'd like to help:

1. Fork the repository.
2. Create a feature branch: `git checkout -b feature-name`.
3. Commit your changes with clear messages.
4. Open a pull request describing the change and why it's useful.

Please follow conventional commit messages and keep changes focused and well-documented.

## Testing & Debugging

- Run locally after building and check console output for errors.
- Add logging or assertions in game loop areas if you need to debug collision or timing issues.
- If adding new dependencies, add checks or helpful error messages in the CMake configuration.

## License

This repository does not specify a license by default. If you intend to publish or allow reuse, add a LICENSE file. A common choice is the MIT License:

```
MIT License
...
```

Change the license to match your intentions.

## Acknowledgements

- Classic Snake gameplay inspiration
- Any libraries or tutorials you used (list them here)

## Contact

For questions or suggestions, open an issue or contact the repository owner: https://github.com/MichalNalewajko1/Snake

Enjoy coding and playing!
