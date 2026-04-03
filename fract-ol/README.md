# 🌌 Fract-ol

*Explore infinity, one pixel at a time.*

A graphical fractal exploration program written in **C**, developed as part of the **42 School curriculum**. This project focuses on complex numbers, graphical rendering, and user interaction using the MiniLibX library.

---

## 📌 Overview

Fract-ol is a real-time fractal renderer that visualizes mathematical sets such as:

- Mandelbrot Set
- Julia Set
- **Burning Ship (Bonus)** 🔥

The program allows users to explore fractals interactively through zooming, panning, and dynamic parameter adjustments.

---

## 🚀 Features

### Mandatory
- Render **Mandelbrot** fractal
- Render **Julia** fractal
- Smooth zoom in/out
- Mouse and keyboard interaction
- Dynamic coloring

### Bonus
- 🔥 **Burning Ship fractal** implementation
- Color shifting / palettes
- Smooth continuous zoom
- Julia parameter control via mouse

---

## 🧠 Mathematical Background

Fractals are generated using iterative formulas on complex numbers:

### Mandelbrot
```
Z(n+1) = Z(n)^2 + C
```
- Z starts at 0
- C represents each pixel in the complex plane

### Julia
```
Z(n+1) = Z(n)^2 + C
```
- Z starts at pixel coordinate
- C is constant (user-defined)

### Burning Ship 🔥
```
Z(n+1) = (|Re(Z)| + i|Im(Z)|)^2 + C
```
- Uses absolute values before squaring
- Produces a flame-like fractal structure

---

## 🛠️ Installation

### Requirements
- GCC
- Make
- MiniLibX (provided by 42)
- X11 libraries (Linux)

### Clone Repository
```
git clone https://github.com/faizanmkhan/42_Warsaw.git
cd 42_Warsaw/fract-ol
```

### Compile
```
make
```

---

## ▶️ Usage

### Run Mandelbrot
```
./fractol mandelbrot
```

### Run Julia
```
./fractol julia -0.7 0.27015
```

### Run Burning Ship (Bonus)
```
./fractol burningship
```

---

## 🎮 Controls

| Key / Mouse        | Action                      |
|-------------------|----------------------------|
| Mouse Scroll      | Zoom in / out              |
| Arrow Keys        | Move view                  |
| ESC               | Exit program               |
| R                 | Reset view                 |
| C                 | Change color palette       |
| Mouse Move        | Adjust Julia parameters    |

---

## 🧱 Project Structure

```
fract-ol/
├── src/
│   ├── main.c
│   ├── render.c
│   ├── fractals.c
│   ├── burning_ship.c
│   ├── julia.c
│   └── mandelbrot.c
├── include/
│   └── fractol.h
├── libft/
├── minilibx/
├── Makefile
└── README.md
```

---

## ⚙️ Implementation Details

- Uses **MiniLibX** for window management and pixel rendering
- Each pixel is mapped to a point in the complex plane
- Iteration count determines color
- Escape radius typically set to 2
- Optimized using:
  - Double precision floating points
  - Efficient loop calculations

---

## 🎨 Coloring

Color is determined based on iteration depth:

- Low iterations → darker colors
- High iterations → brighter colors
- Optional smooth coloring for gradients

---

## 📈 Learning Outcomes

- Complex number arithmetic
- Event-driven programming
- Graphics programming fundamentals
- Optimization techniques
- Mathematical visualization

