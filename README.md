# Linked List Implementation in C++

## Description

This repository contains a C++ implementation of a Singly Linked List data structure with insertion, deletion, access, and traversal operations.

## How to Run

### Requirements

* C++11 compatible compiler (g++ or clang++ recommended)

### Compilation and Execution

1. **Clone the repository:**

```bash
git clone https://github.com/yourusername/linked-list-cpp.git
cd linked-list-cpp
```

2. **Compile the program:**

```bash
g++ -std=c++11 src/main.cpp -I include -o linked_list
```

3. **Run the executable:**

```bash
./linked_list
```

### Cleanup

To remove the compiled binary:

```bash
rm linked_list
```

## Expected Output

```
Initial list: 5 -> 10 -> 20 -> 30
Element at position 2: 20
After inserting 15 at position 2: 5 -> 10 -> 15 -> 20 -> 30
After popping front and back: 10 -> 15 -> 20
After erasing position 1: 10 -> 20
Copied list: 10 -> 20
Assigned list: 10 -> 20
After clear, list size: 0
```

## Files Included

* **include/LinkedList.h**: Header file with class declaration
* **src/main.cpp**: Demonstration program
* **README.md**: This documentation file

## Key Features

* Templated implementation works with any data type
* O(1) operations at both ends (head and tail)
* Complete memory management with proper destructor
* Exception-safe implementation
* Rule of Three compliant (copy constructor, assignment operator, destructor)
* No external dependencies - Standard Library only

## Operations Supported

| Operation      | Description                    | Time Complexity |
| -------------- | ------------------------------ | --------------- |
| `push_back()`  | Add element at end             | O(1)            |
| `push_front()` | Add element at beginning       | O(1)            |
| `pop_back()`   | Remove last element            | O(n)            |
| `pop_front()`  | Remove first element           | O(1)            |
| `insert()`     | Insert at arbitrary position   | O(n)            |
| `erase()`      | Remove from arbitrary position | O(n)            |
| `at()`         | Access element by position     | O(n)            |
| `length()`     | Get current size               | O(1)            |
| `empty()`      | Check if list is empty         | O(1)            |
