#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<int> list;

    std::cout << "Linked List Demonstration\n";
    std::cout << "------------------------\n";

    // Add elements
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.insert(1, 7);

    // Display list
    std::cout << "List contents: ";
    list.print();
    std::cout << "Size: " << list.getSize() << "\n";

    // Access elements
    std::cout << "First element: " << list.front() << "\n";
    std::cout << "Last element: " << list.back() << "\n";
    std::cout << "Element at index 2: " << list[2] << "\n";

    // Remove elements
    list.pop_front();
    list.remove(1);

    std::cout << "After removals: ";
    list.print();

    // Iterate using iterators
    std::cout << "Iterating with range-based for loop: ";
    for (int num : list)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Test copy constructor
    LinkedList<int> list2 = list;
    std::cout << "Copied list: ";
    list2.print();

    return 0;
}