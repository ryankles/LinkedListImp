// LinkedList.h
#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T &data) : data(data), next(nullptr) {}
    };

    Node *head;
    Node *tail;
    size_t size;

public:
    // Constructor/Destructor
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList()
    {
        clear();
    }

    // Copy constructor
    LinkedList(const LinkedList &other) : head(nullptr), tail(nullptr), size(0)
    {
        Node *current = other.head;
        while (current != nullptr)
        {
            push_back(current->data);
            current = current->next;
        }
    }

    // Assignment operator
    LinkedList &operator=(const LinkedList &other)
    {
        if (this != &other)
        {
            clear();
            Node *current = other.head;
            while (current != nullptr)
            {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // Core operations
    void push_front(const T &data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr)
        {
            tail = newNode;
        }
        size++;
    }

    void push_back(const T &data)
    {
        Node *newNode = new Node(data);
        if (tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            throw std::out_of_range("List is empty");
        }
        Node *temp = head;
        head = head->next;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        delete temp;
        size--;
    }

    void pop_back()
    {
        if (tail == nullptr)
        {
            throw std::out_of_range("List is empty");
        }
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *current = head;
            while (current->next != tail)
            {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        size--;
    }

    void insert(size_t index, const T &data)
    {
        if (index > size)
        {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0)
        {
            push_front(data);
        }
        else if (index == size)
        {
            push_back(data);
        }
        else
        {
            Node *newNode = new Node(data);
            Node *current = head;
            for (size_t i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }

    void remove(size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0)
        {
            pop_front();
        }
        else if (index == size - 1)
        {
            pop_back();
        }
        else
        {
            Node *current = head;
            for (size_t i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
        }
    }

    void clear()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    // Accessors
    T &front()
    {
        if (head == nullptr)
        {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    const T &front() const
    {
        if (head == nullptr)
        {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    T &back()
    {
        if (tail == nullptr)
        {
            throw std::out_of_range("List is empty");
        }
        return tail->data;
    }

    const T &back() const
    {
        if (tail == nullptr)
        {
            throw std::out_of_range("List is empty");
        }
        return tail->data;
    }

    T &at(size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        Node *current = head;
        for (size_t i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    const T &at(size_t index) const
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        Node *current = head;
        for (size_t i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    T &operator[](size_t index)
    {
        return at(index);
    }

    const T &operator[](size_t index) const
    {
        return at(index);
    }

    bool empty() const
    {
        return size == 0;
    }

    size_t getSize() const
    {
        return size;
    }

    // Utility functions
    void print() const
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data;
            if (current->next != nullptr)
            {
                std::cout << " -> ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Iterator class
    class Iterator
    {
    private:
        Node *current;

    public:
        Iterator(Node *node) : current(node) {}

        Iterator &operator++()
        {
            if (current)
                current = current->next;
            return *this;
        }

        bool operator!=(const Iterator &other) const
        {
            return current != other.current;
        }

        T &operator*()
        {
            return current->data;
        }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};