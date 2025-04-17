
# Project Title

A brief description of what this project does and who it's for

# Tic Tac Toe Bot Comparison

## Overview
This project compares two versions of a Tic Tac Toe bot written in C++. The updated version (Version 1) improves upon the original (Version 2) by fixing bugs, enhancing the user experience, and introducing additional features.

---

## ✅ Bug Fixes

### 1. Win Detection for Empty Cells
- **Issue (Version 2):** Incorrectly considers three '_' in a row as a win.
- **Fix (Version 1):** Added condition to ignore '_' when checking for wins:
  ```cpp
  if (b[row][0] == b[row][1] && b[row][1] == b[row][2] && b[row][0] != '_')
  ```

### 2. Repeated `evaluate()` Calls
- **Issue (Version 2):** Evaluates the board state multiple times redundantly.
- **Fix (Version 1):** Introduced `checkGameOver()` to centralize win/tie checks.

### 3. Input Validation
- **Issue (Version 2):** Accepts out-of-range inputs like 0.
- **Fix (Version 1):** Validates that input is between 1 and 3.

---

## ⚖️ Improvements

### 1. Modular Design
- Added `checkGameOver()` to reduce duplicated win/tie checking logic.

### 2. Board Display Enhancements
- **Color-coded output using ANSI escape codes:**
  - Player ('x'): [34mx[0m (Blue)
  - Opponent ('o'): [31mo[0m (Red)
  - Empty: [90m_[0m (Gray)

- **Grid Formatting:**
  ```
  +---+---+---+
  | x | o | _ |
  +---+---+---+
  ```

### 3. Cleaner Turn Loop
- Structured and reduced duplicated code blocks for better readability.

### 4. Screen Clearing Between Turns
- Clears the terminal using `\033[2J\033[H` to refresh display each turn.

### 5. Depth-based Minimax Scoring
- Earlier wins are now scored higher by subtracting depth:
  ```cpp
  return score - depth;
  ```

---

## ✨ Extra Features in Version 1

- **Intro Banner and Role Assignment**
  ```
  Player: o
  Computer: x
  -----------Beat the bot-----------
  ```

- **Bot Turn Indicator**
  - Clearly displays when the bot is making a move.

- **Comprehensive Code Comments**
  - Easier to understand logic and flow.

- **Better Randomized Start**
  - Randomly decides who starts the game.

---

## 🚀 Future Suggestions

- Display move computation time for bot.
- Add replay option after game ends.
- Let players choose between 'x' and 'o'.
- Add difficulty levels (limit minimax depth).

---

## 📄 Summary Table

| Feature                           | Version 1 (Updated) ✅ | Version 2 (Original) ❌ |
|-----------------------------------|------------------------|-------------------------|
| Bug-free win detection logic      | ✅ Fixed               | ❌ Incorrect `_ == _` matches |
| Clean, color-coded board display  | ✅ Yes                 | ❌ Plain output         |
| Modular win/tie detection         | ✅ Via checkGameOver() | ❌ Repeated everywhere  |
| Input validation (1–3 range)      | ✅ Yes                 | ❌ Accepts 0            |
| Screen clearing between moves     | ✅ Yes                 | ❌ No                   |
| Centralized game result messages  | ✅ Yes                 | ❌ Repetitive           |
| Move commentary & highlights      | ✅ Yes                 | ❌ No                   |
| Better comments & documentation   | ✅ Yes                 | ❌ Minimal              |

---

## 📝 Author Note
This README highlights the evolution and enhancements of your Tic Tac Toe bot project. The first version not only improves core logic but also makes the gameplay smoother, more intuitive, and visually engaging.

Happy coding!

