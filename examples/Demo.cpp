#include <iostream>
#include <GeneralisedDS/GeneralisedDS.hpp>

int main()
{
    GeneralisedDS::SinglyLL<int> list;

    list.InsertFirst(20);
    list.InsertFirst(10);
    list.InsertLast(30);

    std::cout << "Singly Linear Linked List:\n";
    list.Display();
    std::cout << "Count: " << list.Count() << "\n\n";

    GeneralisedDS::Stack<int> stack;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Display();
    std::cout << "Pop: " << stack.Pop() << "\n\n";

    GeneralisedDS::Queue<int> queue;
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Display();
    std::cout << "Dequeue: " << queue.Dequeue() << "\n\n";

    GeneralisedDS::BST<int> tree;
    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);

    std::cout << "BST Inorder: ";
    tree.Inorder();
    std::cout << "Nodes: " << tree.Count() << "\n";
    std::cout << "Leaf Nodes: " << tree.CountLeaf() << "\n";
    std::cout << "Parent Nodes: " << tree.CountParent() << "\n";
    std::cout << "Count Again: " << tree.Count() << "\n";

    return 0;
}
