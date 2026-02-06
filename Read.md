# Page Replacement Algorithms

C++ implementation of **FIFO**, **LRU**, and **Optimal** page replacement algorithms used in Operating Systems.

## Algorithms
- **FIFO (First In First Out)**
- **LRU (Least Recently Used)** – Doubly linked list + hash map
- **Optimal** – Replaces the page used farthest in the future

## Complexity
- **FIFO:** O(1)  
- **LRU:** O(1)  
- **Optimal:** O(N²)

## How to Run
```bash
g++ main.cpp
./a.out
