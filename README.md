
# 🗺️ Graph Data Structure & BFS Implementation

## 🚀 Project Overview

This C++ project implements a **graph data structure** using **vertices, edges, and adjacency lists**. It supports:

* 🌐 **Graph creation** from a file
* 🔹 **Weighted & undirected edges**
* 🏃 **Breadth-First Search (BFS)** to find paths between vertices
* 📊 Printing adjacency lists and neighbor relationships

This project is perfect for **learning graph theory, BFS traversal, and C++ OOP concepts**.

---

## 🛠️ Features

* **Dynamic graph representation** using linked lists
* **Vertex class** storing neighbor information with weights
* **Edge class** for graph edges (weighted)
* **BFS traversal** to find shortest paths
* **File input** for graph data
* **Path reconstruction** from start to end vertex

---

## 📁 Project Structure

```
GraphProject/
├─ main.cpp          # Driver program
├─ linklist.h/cpp    # Linked list implementation for adjacency lists
├─ object.h          # Base object class
├─ PTA.txt           # Sample graph input file (vertices & edges)
└─ README.md         # Project documentation
```

---

## 📝 How to Run

1. Clone the repository:

   ```bash
   git clone <repo-url>
   ```
2. Open the project in your favorite IDE (Visual Studio, CodeBlocks, etc.) or use terminal:

   ```bash
   g++ main.cpp linklist.cpp -o graphApp
   ./graphApp
   ```
3. Input the start and end vertices when prompted:

   ```
   Enter the start vertex: A
   Enter the final vertex: D
   ```
4. ✅ The BFS path will be displayed in the console.

---

## 🧩 Example

Given a file `PTA.txt`:

```
A B C D
A B 1
A C 2
B D 1
C D 1
```

Running BFS from **A → D**:

```
D <------ B <------ A
```

---

## 📚 Dependencies

* Standard C++ libraries: `<iostream>`, `<fstream>`, `<queue>`, `<map>`
* No external dependencies required

---

## 🎯 Future Improvements

* Add **Depth-First Search (DFS)** traversal
* Add **shortest path algorithms** like Dijkstra or Bellman-Ford
* Add **graph visualization** using a GUI library
* Handle **disconnected graphs** gracefully

---

## 💡 Author

**Your Name** – Computer Engineering Student

---

## 🔖 License

This project is licensed under **MIT License** – see the LICENSE file for details.

---


Do you want me to make that version too?
