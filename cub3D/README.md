# 🎮 cub3D

> A first-person 3D game engine built using **raycasting**, inspired by *Wolfenstein 3D*, developed as part of the **42 School curriculum**.

## 📌 Overview

**cub3D** is a lightweight 3D rendering engine that simulates a first-person view inside a maze using **2D maps** and **raycasting techniques**.  
The project focuses on understanding how early 3D engines worked and strengthening skills in:

- Computer graphics fundamentals
- Linear algebra and geometry
- Raycasting and perspective projection
- Event handling and real-time rendering
- Parsing and validation of configuration files

All rendering is done manually without the use of modern 3D libraries.

---

## ✨ Features

- Real-time **raycasting-based 3D rendering**
- Textured walls with correct perspective
- Player movement:
  - Forward / backward
  - Left / right strafing
  - Rotation
- Collision detection with walls
- Configurable maps and textures via `.cub` file
- Ceiling and floor color rendering
- Keyboard input handling
- Window management and clean exit

---

## 🛠️ Technologies & Concepts

- **Language:** C
- **Graphics Library:** MiniLibX
- **Math & Graphics Concepts:**
  - Raycasting
  - Vector math
  - Trigonometry
  - Perspective projection
- **OS Concepts:**
  - Event loops
  - Frame rendering
  - Memory management

---

## 🧠 Architecture Overview

The engine follows a clear rendering pipeline:


Each stage is isolated to ensure correctness and maintainability.

---

## 📄 Configuration & Parsing (`.cub` file)

The `.cub` file defines the **game world configuration** and map layout.

### File Components

- Texture paths:
  - `NO` – North wall texture
  - `SO` – South wall texture
  - `WE` – West wall texture
  - `EA` – East wall texture
- Colors:
  - `F` – Floor color (RGB)
  - `C` – Ceiling color (RGB)
- Map layout:
  - `1` → Wall
  - `0` → Empty space
  - `N`, `S`, `E`, `W` → Player start position and orientation

Example:
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
10N001
100001
111111


---

### Parsing Rules & Validation

The parser:
- Ensures all required elements are present
- Validates RGB values
- Checks texture file accessibility
- Ensures the map is closed (surrounded by walls)
- Verifies exactly **one player starting position**
- Normalizes inconsistent spacing

Any invalid configuration results in a clean error and exit.

---

## 🔦 Raycasting Engine

Raycasting is the core of cub3D.

### Raycasting Flow

For each vertical screen column:
1. Calculate ray direction based on player angle
2. Perform **DDA (Digital Differential Analysis)** to detect wall collisions
3. Measure perpendicular wall distance
4. Calculate projected wall height
5. Select correct wall texture
6. Draw the vertical stripe to the screen

This creates the illusion of 3D depth from a 2D map.

---

## 🧮 Perspective & Depth Correction

To avoid the **fish-eye effect**, distances are corrected using perpendicular distance calculations.  
This ensures consistent wall scaling and realistic perspective.

---

## 🧱 Texturing

- Each wall direction uses a separate texture
- Texture X coordinate is calculated based on hit position
- Texture Y is scaled to match wall height
- Textures are mapped column-by-column for accuracy

---

## 🚶 Player Movement & Collision

- Movement is vector-based
- Rotation uses angle increments
- Collision detection prevents walking through walls
- Movement speed and rotation speed are controlled per frame

---

## 🎮 Controls

| Key | Action |
|----|-------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `← / →` | Rotate camera |
| `ESC` | Exit game |

---

## 🧱 Limitations

- No sprites or enemies
- No dynamic lighting
- No vertical look (up/down)
- No minimap (unless bonus)

---

## 🎓 Learning Outcomes

This project deepened my understanding of:

- How early 3D engines work
- Raycasting algorithms
- Low-level graphics rendering
- Parsing and validating complex input files
- Real-time event handling in C

---

## 🏁 Conclusion

**cub3D** is a foundational graphics project that demonstrates how immersive 3D environments can be created using simple mathematical principles and efficient rendering techniques.

It bridges the gap between **mathematics**, **computer graphics**, and **systems programming**.
