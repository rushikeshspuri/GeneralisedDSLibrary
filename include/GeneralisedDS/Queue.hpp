#pragma once

#include <iostream>

namespace GeneralisedDS
{
    /////////////////////////////////////////////////////////////////////////////
    //  Class : Queue   
    //  Date :  11/07/2026
    //  Author : Rushikesh Puri  
    /////////////////////////////////////////////////////////////////////////////


    template <class T>
    struct QueueNode
    {
        T data;
        struct QueueNode<T> *next;
    };

    template <class T>
    class Queue
    {
        private:
            struct QueueNode<T> *first;
            int iCount;

        public:
            Queue();

            void Enqueue(T iNo);
            T Dequeue();
            void Display();
            int Count();
    };

    template <class T>
    Queue<T> :: Queue()
    {
        this -> first = NULL;
        this -> iCount = 0;
    }

    template <class T>
    void Queue<T> :: Enqueue(T iNo)
    {
        struct QueueNode<T> *newn = NULL;
        struct QueueNode<T> *temp = NULL;

        newn = new QueueNode<T>;

        newn->data = iNo;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }

            temp -> next = newn;
        }

        iCount++;
    }

    template <class T>
    T Queue<T> :: Dequeue()
    {
        struct QueueNode<T>* temp = NULL;
        T iValue = T();

        if(first == NULL)
        {
            std::cout<<"Queue is Empty"<<"\n";
            std::cout<<"-------------------------"<<"\n";
            return iValue;
        }
        else
        {
            temp = first;

            iValue = first -> data;

            first = first -> next;

            delete temp;

            iCount--;
            return iValue;
        }
    }

    template <class T>
    void Queue<T> :: Display()
    {
        struct QueueNode<T>* temp = NULL;

        temp = first;

        std::cout << "\n=================================\n";
        std::cout << "             QUEUE\n";
        std::cout << "=================================\n";

        if(temp == NULL)
        {
            std::cout << "\n\tQueue is Empty\n";
            std::cout << "=================================\n";
            return;
        }

        std::cout<< "Front -> ";

        while(temp != NULL)
        {
            std::cout << "| " << temp->data << " |";

            if(temp->next != NULL)
            {
                std::cout << " -> ";
            }

            temp = temp->next;
        }

        std::cout << " <- Rear\n";
        std::cout << "=================================\n";
    }

    template <class T>
    int Queue<T> :: Count()
    {
        return iCount;
    }

}
