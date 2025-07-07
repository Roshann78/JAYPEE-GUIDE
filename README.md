
# 🗺️ Jaypee Maps – Campus Navigation System

This is a console-based C++ project that helps users navigate through the **Jaypee Institute of Information Technology (JIIT)** campus by computing the shortest path between different campus locations using **Dijkstra’s Algorithm**. It supports two implementations: one using a **simple queue (BFS-based)** and another using a **priority queue (min-heap based)**.

---

## 🔧 Features

- Custom-built **Graph** structure using both Adjacency Matrix and Adjacency List
- **Two pathfinding implementations**:
  - Queue-based (BFS-like traversal with distance updates)
  - Priority Queue-based (classical Dijkstra using min-heap)
- Clear **console UI** with color-coded outputs and formatted path tables
- Displays:
  - Full path from source to destination
  - Step-by-step distance tracking
  - Vertical arrow-format route
- **Custom Queue and Priority Queue** classes implemented manually
- Includes **robust user input handling**

---

## 🏗️ Locations in the Graph

These are the mapped nodes in the graph:
| Index | Location |
|-------|----------|
| 0     | Gate-1   |
| 1     | Gate-2   |
| 2     | Gate-3   |
| 3     | ABB-1    |
| 4     | JBS      |
| 5     | Cafe     |

---

## 🚀 How It Works

1. Program welcomes the user with a menu.
2. User chooses to continue or exit.
3. User selects current location and destination from a list.
4. Program asks for preferred implementation:
   - Queue (simplified)
   - Priority Queue (optimized)
5. Computes and displays the shortest path with step-by-step breakdown.

---

## 🧠 Algorithms Used

- **Dijkstra’s Algorithm**:
  - Implemented using:
    - Custom Queue (for educational BFS-style simulation)
    - Min-heap Priority Queue (efficient)
- **Graph Representation**:
  - Adjacency Matrix to store edge weights
  - Converted to Adjacency List for traversal efficiency

---

## 💡 Example Output (Simplified)

```
Shortest Path (Queue):
Step | Node    | Distance
--------------------------
  1  | Gate-1  | 0
  2  | Gate-2  | 100
  3  | ABB-1   | 120
  4  | JBS     | 190

Vertical Path:
Gate-1 → Gate-2 → ABB-1 → JBS
```

---

## 📁 File Structure

```
main.cpp          → Contains all class definitions and main() function
README.md         → Project overview and usage instructions
```

---

## 🛠️ Technologies Used

- Language: **C++**
- Environment: **Windows Console** (uses `system("cls")` and `system("Color")`)
- No external libraries

---

## 📌 Notes

- Error checking is implemented for invalid location inputs and method choices.
- This project is for educational and demonstration purposes. In practice, STL containers like `priority_queue` should be preferred over custom implementations for production code.

---

## 👨‍💻 Author

**Roshan Sharma**  
Jaypee Institute of Information Technology  
[LinkedIn](https://www.linkedin.com/in/roshan-sharma-719a81286/) | [GitHub](https://github.com/Roshann78)
