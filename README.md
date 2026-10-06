# 🏃 Endless Runner Game

A 2D Endless Runner Game developed in **C++** as a Programming Fundamentals project at **FAST – National University of Computer & Emerging Sciences (FAST-NUCES)**.

## 🎮 About the Game

In this game, the player continuously runs forward and must avoid obstacles while collecting coins and covering as much distance as possible.

The game becomes more challenging as the player progresses.

## ✨ Features

* Three-lane player movement
* Automatic running
* Left and right movement
* Limited forward and backward movement
* Obstacles
* Coin collection
* Three lives
* Increasing game speed
* Distance tracking
* Enemy introduced after 2000m
* Side-wall boundaries
* Pause and resume
* Restart functionality
* Game-over system
* Menu-driven gameplay
* High-score functionality

## 🎮 Controls

| Key     | Action        |
| ------- | ------------- |
| `Enter` | Start Game    |
| `←`     | Move Left     |
| `→`     | Move Right    |
| `↑`     | Move Forward  |
| `↓`     | Move Backward |
| `P / p` | Pause Game    |
| `R / r` | Resume Game   |
| `A / a` | Restart Game  |
| `ESC`   | Exit          |

## 🛠️ Technologies Used

* **C++**
* **OpenGL**
* **GLUT**
* **Make**
* **Linux**

## 🚀 How to Run

### 1. Clone the repository

```bash
git clone https://github.com/YOUR-USERNAME/YOUR-REPOSITORY.git
```

### 2. Open the project directory

```bash
cd YOUR-REPOSITORY
```

### 3. Install the required libraries

```bash
bash install-libraries.sh
```

### 4. Compile the project

```bash
make
```

### 5. Run the game

```bash
./game-release
```

## 📁 Project Structure

```text
.
├── game-release.cpp
├── util.cpp
├── util.h
├── Makefile
├── install-libraries.sh
└── README.md
```

## 🎯 Game Objective

The objective is to achieve the highest possible score and distance while avoiding obstacles and collecting coins.

The game starts with **three lives**. A life is lost when the player collides with an obstacle. The game ends when all lives are lost.

As the player covers more distance, the game speed increases. After reaching **2000m**, an enemy is introduced to make the game more challenging.

## 🎓 Academic Information

**Course:** Programming Fundamentals
**University:** FAST – National University of Computer & Emerging Sciences
**Campus:** Multan
**Semester:** Fall 2025

## 👤 Author

**Muhammad Fasihudin**

BS Artificial Intelligence
FAST – National University of Computer & Emerging Sciences

---

⭐ **Thank you for checking out the project!**
