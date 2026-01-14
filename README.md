# vexRobotics8995E
### 8995E — 2025–2026 VEX Robotics Season (PUSH BACK)

<p align="center">
  <img src="./media/IMG_0377.jpeg" width="600">
</p>

This repository contains all programming projects developed by **Team 8995E** during the **2025–2026 VEX Robotics Push Back season**.

The focus of this season is **robust autonomous consistency**, **clean code organization**, and **match-ready performance** using PROS-based frameworks.

---

## Season Overview

# **2025–2026 Season — PUSH BACK**
During the Push Back season, our team is developing and iterating on multiple autonomous routines and control systems designed for both **skills challenges** and **match play**.

This repository is organized as a **monorepo**, containing separate projects for different autonomous strategies while sharing common drivetrain and utility code.

---

## Project Breakdown

### Skills Autonomous
The **Skills** project is built using **LemLib** with dead-wheel odometry.

**Key features:**
- Dead-wheel odometry for precise field positioning
- PID-controlled linear and angular motion
- Long-route autonomous optimized for consistency
- Designed for repeatability under competition conditions

📁 Location: `autons.cpp`

---

### Match Autonomous
The **Match Auton** project contains autonomous routines tailored for different starting positions and strategies.

**Key features:**
- Left / Right side autonomous routines
- Fast initial scoring and controlled positioning
- Shared chassis and control logic with Skills
- Tuned for reliability rather than maximum risk

📁 Location: `autons.cpp`

---

### Shared Code
Common logic used across all projects is stored in the shared directory.

Includes:
- Drivetrain and chassis configuration
- PID and motion utilities
- Sensor wrappers and helper functions

---

## 🎥 Autonomous Demo Runs

<p align="center">
  <img src="./media/IMG_0447.jpg" width="500">
</p>

> Videos are hosted externally and linked here for easy viewing.

###  Autonomous Skills Runs
*(Links will be added as the season progresses)*
- [Skills Run #1 Early Run](https://youtube.com/shorts/S56K8_ltfkg)
-  Skills Run #2 — TBD  

### Match Autonomous Runs
*(Links will be added as routines are finalized)*
-  Match Auton (Left) — TBD  
-  Match Auton (Right) — TBD  

---

## 🛠️ Getting Started

### Requirements
- VS Code  
- PROS Extension for VS Code  
- VEX V5 hardware  

Each project directory is its **own PROS project**.

### Build & Upload
```bash
cd skills
pros build
pros upload
