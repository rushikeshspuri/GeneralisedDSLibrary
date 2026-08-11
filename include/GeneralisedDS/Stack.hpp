#pragma once

#include <iostream>

namespace GeneralisedDS
{
    //  Class : Stack   
    //  Date :  11/07/2026
    //
    /////////////////////////////////////////////////////////////////////////////


    template <class T>
    struct StackNode
    {
        T data;
        struct StackNode<T>* next;
    };

    template <class T>
    class Stack
    {
        private:
            int iCount;
            struct StackNode<T>* first;

        public:
            Stack();
            
            void Push(T iNo);
            T Pop();
            T Peep();
            void Display();
            int Count();
    };

    template <class T>
    Stack<T> :: Stack()
    {
        this -> iCount = 0;
        this -> first = NULL;
    }

    template <class T>
    void Stack<T> :: Push(T iNo)
    {
        struct StackNode<T>* newn = NULL;
        newn = new struct StackNode<T>();

        newn -> data = iNo;
        newn -> next = NULL;

        newn->next = first;
        first = newn;

        iCount++;

    }

    template <class T>
    T Stack<T> :: Pop()
    {
        struct StackNode<T>* temp = NULL;
        T iValue = T();

        if(this -> first == NULL)
        {
            std::cout<<"Stack is Empty"<<"\n";
            std::cout<<"-------------------------"<<"\n";
            return iValue;
        }
        else
        {
            temp = this -> first;
            
            iValue = this -> first -> data;

            this -> first = this -> first -> next;

            delete temp;

            this -> iCount--;
            return iValue;
        }

    }

    template <class T>
    T Stack<T> :: Peep()
    {

        if(this -> first == NULL)
        {
            std::cout<<"Stack is Empty"<<"\n";
            std::cout<<"-------------------------"<<"\n";
            return T();
        }
        else
        {
           return(first -> data);
        }
    }

    template <class T>
    void Stack<T>::Display()
    {
        struct StackNode<T> *temp = first;

        std::cout << "\n=================================\n";
        std::cout << "             STACK\n";
        std::cout << "=================================\n";

        if(temp == NULL)
        {
            std::cout << "\n\tStack is Empty\n";
            std::cout << "=================================\n";
            return;
        }

        std::cout << "\n\t      TOP\n\n";

        while(temp != NULL)
        {
            std::cout << "\t   +-------+\n";
            std::cout << "\t   | " << temp->data << " |\n";
            std::cout << "\t   +-------+\n";

            temp = temp->next;
        }

        std::cout << "=================================\n";
    }

    template <class T>
    int Stack<T> :: Count()
    {
        return iCount;
    }


    ////////////////////////////////////////////////////////////////////////////
    //
    //  Author : Rushikesh Puri
}
