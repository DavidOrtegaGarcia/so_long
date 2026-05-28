# so_long - 42 Project

This project is part of the 42 curriculum. The main objective is to create a **simple 2D game** using the MiniLibX (MLX) graphics library. The goal is to learn about **graphics programming**, window management, event handling (keyboard and mouse), and basic game loops by building a top-down game from scratch in C.

## 🚀 Prerequisites & Compatibility
To compile and run this project, you must have the following ready on your Mac:
* [GCC](https://gcc.gnu.org/)
* [Make](https://www.gnu.org/software/make/)
* **MiniLibX (MacOS/Cocoa version):** Included within the local repository repository files.
  
> 🍏 **Platform Note:** This project is explicitly designed, developed, and optimized to run exclusively on **macOS**. Due to the specific API calls of the MiniLibX Cocoa version, it is not compatible with Linux or Windows environments out of the box.

## 🏗 Project Structure
The project is organized with the automation setup (`Makefile`) at the root level, standard submodules, and your modularized source code inside the `src` directory:
```text
.
├── Makefile            # Automation setup and compiler manager
├── libft/              # 42 standard library extension
├── libs/               # Header files directory
├── maps/               # Directory containing valid/invalid .ber map files
├── mlx/                # MiniLibX graphics library (MacOS Cocoa version)
├── img/                # Miscellaneous image resources
├── textures/           # Game asset textures (XPM files)
└── src/                # Source code files (.c)
```

## ⚙️ Configuration & Features

`so_long` replicates classic top-down 2D game mechanics. Before running it, ensure you understand the supported rules:

* **Map Requirements:** The game only accepts `.ber` files that strictly comply with the following grid characters:
```text
0  -> Empty space where the player can walk
1  -> Wall that blocks the player's movement
C  -> Collectible item to be gathered
E  -> Map exit (opens or triggers victory once all C are collected)
P  -> Starting position of the player
```
* **Movement Rules:** The game tracks and displays the current state of the player:

```text
W / Up Arrow    -> Move up
A / Left Arrow  -> Move left
S / Down Arrow  -> Move down
D / Right Arrow -> Move right
ESC / Close (X) -> Safely close the game window
```
> ⚠️ Warning: The map must be rectangular, completely surrounded by walls ('1'), and contain exactly one 'P', exactly one 'E', and at least one 'C'. Furthermore, there must be a valid path allowing the player to reach all collectibles and the exit; otherwise, the program will trigger a parsing error.

## 📊 Event & Graphic Management

To ensure a smooth user experience, the game relies heavily on event hooks and dynamic rendering:

* **Movement Counter:** Every successful move increases the step count, which is printed directly in the terminal (or rendered on screen if bonus features are included).
* **Window Interruptions:** Properly hooks into the window destruction event (clicking the Mac 'X' red button or pressing `ESC`), guaranteeing a clean termination.

## 🛠 Usage

I have included a robust `Makefile` configured with the necessary flags for standard compilation (`-Wall -Wextra -Werror`) and macOS framework linking (`-framework OpenGL -framework AppKit`). It automatically manages library compilation triggers (`libft` and `mlx`) and handles dynamic object generation inside a local `tmp/` directory.

You can use the following commands in your terminal:
* `make` or `make all`: Compiles `libft`, `mlx`, creates the `tmp/` directory structure, processes all source files into objects, and generates the final `so_long` executable.
* `make clean`: Removes the temporary `tmp/` directory along with all generated object files (`.o`), and triggers the cleaning rules (`clean`) for both internal libraries (`libft` and `mlx`).
* `make fclean`: Performs a full reset. It purges all object files, triggers deep cleanup configurations inside `libft`, and completely deletes the compiled `so_long` binary.
* `make re`: Runs `fclean` followed by `make` to execute a pristine re-compilation of the entire project.

To launch the game after compilation, provide a valid map path as an argument:
```bash
./so_long maps/valid_map.ber
```

## 🛡 Security & Memory Considerations

* **Memory Management:** Every allocated image, window pointer, and map array is strictly tracked. When the game closes, all assets are unloaded from the GPU/RAM to ensure **zero leaks**.
* **Error Handling:** The program reacts dynamically depending on the execution phase:
  * **Successful Execution:** If the map is valid, the terminal remains completely silent and launches the graphics window directly.
  * **Parsing & Validation Errors:** If any step fails during the setup (e.g., file descriptor errors, an invalid map layout, or a `malloc` failure), the program halts execution instantly and prints a **specific, custom error description** clarifying the exact cause (e.g., `"The file doesn't exist\n"`, `"Invalid map\n"`, `"Malloc failed\n"`).
  * **Game Closure (MLX):** When exiting the game normally via the window interface or `ESC`, the application cleans up all graphic loops and hooks, and prints `GAME OVER` to indicate a clean and successful termination.
---
*Project developed as part of the 42 curriculum.*
