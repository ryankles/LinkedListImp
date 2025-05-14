# Linked List Study Report

## 1. Study Plan

**Topic Chosen:** Singly Linked Lists

**Why You Chose It:**
I chose linked lists because they demonstrate fundamental pointer operations and form the basis for more complex data structures. Their sequential yet dynamic nature provides an excellent case study for memory management.

**Learning Goals:**
- Understand node-based structure and pointer manipulation
- Implement core operations (insert/delete at head/tail/middle)
- Master iterative vs recursive approaches
- Analyze time/space complexity tradeoffs
- Build a production-quality templated C++ implementation

**Resources Used:**
- "Data Structures and Algorithm Analysis" by Mark Allen Weiss
- MIT OpenCourseWare lectures on pointers and memory
- C++ documentation on template classes and rule of three

## 2. What You Learned

**Concept Summary:**
A singly linked list consists of nodes where each node contains data and a pointer to the next node. This creates a chain that can grow/shrink dynamically. Unlike arrays, insertion/deletion at head is O(1), but random access is O(n).

**Insights:**
- Surprise: How maintaining both head and tail pointers enables O(1) append
- Challenge: Properly handling edge cases (empty list, single node)
- Intuitive: The natural correspondence between iterative traversal and the physical structure

**Time Complexity:**
- Insert at head/tail: O(1)
- Delete at head: O(1)
- Delete at tail: O(n)
- Random access: O(n)
- Search: O(n)
- Space: O(n) total, O(1) per operation

## 3. Implementation Summary

**Approach:**
- Templated C++ implementation for type flexibility
- Used both head and tail pointers for efficiency
- Implemented rule of three (copy constructor, assignment, destructor)
- Included comprehensive exception handling

**Key Files/Functions:**
- LinkedList.h: Complete class declaration
  - Node structure with T data and Node* next
  - push_front()/push_back(): O(1) insertion
  - pop_front()/pop_back(): Head/tail removal
  - insert()/erase(): Positional operations
  - at(): Bounds-checked access
  - clear(): Full memory cleanup

**Sample Input & Output:**
Input:
list.push_back(10);
list.push_front(5);
list.insert(1, 7);
list.erase(2);

Output:
5 -> 7 -> 10 (after insertion) 
5 -> 7 (after erase)

## 4. Reflection

**Interesting/Difficult Aspects:**
Most interesting was seeing how pointer manipulation enables efficient operations. Most challenging was implementing exception-safe operations while maintaining proper memory management.

**Future Applications:**
- Foundation for stacks/queues
- Music playlists
- Browser history
- As a component in more complex structures (hash tables, graphs)

**Would Choose Again?**
Absolutely. Next time I would extend this to a doubly-linked list to enable O(1) tail removal and backward traversal.