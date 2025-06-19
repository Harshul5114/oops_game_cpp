# Terminal RPG Battle Game

A simple yet engaging turn-based RPG battle game playable entirely in the terminal.
You take control of a champion, face off against randomized enemies, and survive as many battles as possible. Equip powerful weapons, charge special moves, and defend strategically to win.

---

## 🚀 Features

* 🎮 Turn-based battle loop
* 🧍 Three distinct champion classes: Warrior, Mage, and Tank
* ⚔️ Basic attacks, defend mechanics, and special moves that charge over turns
* 🔋 Special charge bar for special moves
* 💥 Weapon system with stat boosts and combat effects (e.g., Burn, Heal, Stun)
* 🎲 Randomly generated enemies with themed names
* 🧠 Smart display logic using emojis and terminal formatting

---

## 📦 Getting Started

1. Clone this repository
2. Open terminal and navigate to the project folder
3. Compile using g++:

   ```bash
   g++ src/*.cpp -o rpg_game
   ```
4. Run the game:

   ```bash
   ./rpg_game   # or rpg_game.exe on Windows
   ```

> Make sure your terminal supports UTF-8 if you want emoji rendering.

---

## 🛠 File Structure

```
📁 include/
  Champion.h         # Base class for all champions
  Weapon.h           # Weapon class and enums
  Classes.h          # Derived classes (Warrior, Mage, Tank)
  WeaponsList.h      # Preset weapons with class restrictions and effects

📁 src/
  main.cpp           # Game loop and UI
  Champion.cpp
  Weapon.cpp
  Classes.cpp        # Special moves for each class

📄 README.md
```

---

## 🔮 Future Ambitions (In Development)

* 🛍️ Weapon shop system for upgrades
* 🧠 Enemy AI improvements (stun handling, smarter moves)
* 🧱 Status effects with turn duration (burn over time, poison, etc.)
* 💼 Inventory management (swap weapons mid-run)
* 🗺️ Campaign mode with map and branching stages
* 🎨 Visual polish: animated ASCII effects, improved terminal UI
* 💾 Save/load system

---

## 👨‍💻 Contributions

This project is actively being developed for fun and learning. Contributions, feedback, and suggestions are most welcome!

---

## 🧠 Author

Made by Harshul 🛠️
A hands-on C++ learner exploring game systems and terminal UI.

---

## 📜 License

This project is released under the MIT License. See `LICENSE` for details.
