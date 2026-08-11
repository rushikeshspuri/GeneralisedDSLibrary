# Generalised Data Structures Library

A simple generic C++ library implementing common data structures using templates and object-oriented programming.

## Data Structures

- Singly Linear Linked List
- Singly Circular Linked List
- Doubly Linear Linked List
- Doubly Circular Linked List
- Stack
- Queue
- Binary Search Tree

## Features

- C++ templates for generic data types
- Separate header file for each data structure
- Simple reusable API
- Example program included

## Requirements

- C++ compiler with C++17 support

## Compile the Example

From the project root:

```bash
g++ -std=c++17 examples/Demo.cpp -I include -o Demo
./Demo
```

## Example

```cpp
#include <GeneralisedDS/Stack.hpp>

int main()
{
    GeneralisedDS::Stack<int> stack;
    stack.Push(10);
    stack.Push(20);
    stack.Display();
}
```

## Project Purpose

This project was created to practice generic programming, OOP, pointers, dynamic memory, linked lists, stacks, queues, and binary search trees while organizing the implementations into a reusable library.

## Author

Rushikesh Puri
