#pragma once

#include <iostream>

namespace GeneralisedDS
{
    //  Class : DoublyLL   (Doubly Linear Linked List)
    //  Date :  11/07/2026
    //
    /////////////////////////////////////////////////////////////////////////////

    template <class T>
    struct DoublyLLNode
    {
        T data;
        struct DoublyLLNode* next;
        struct DoublyLLNode* prev;
        
    };

    template <class T>
    class DoublyLL
    {
        private:
            struct DoublyLLNode<T>* first;
            int iCount;
        
        public:
            DoublyLL();
            
            void Display();
            int Count();

            void InsertFirst(T iNo);
            void InsertLast(T iNo);
            void InsertAtPos(T iNo, int iPos);

            void DeleteFirst();
            void DeleteLast();
            void DeleteAtPos(int iPos);
    };

    template <class T>
    DoublyLL<T> :: DoublyLL()
    {
        this -> first = NULL;
        this -> iCount = 0;
    }
            
    template <class T>
    void DoublyLL<T> :: Display()
    {
        struct DoublyLLNode<T>* temp = NULL;

        temp = first;

        while(temp != NULL)
        {
            std::cout<<"| "<< temp -> data <<" | ->";
            temp = temp -> next;
        }

        std::cout<<std::endl;
    }

    template <class T>
    int DoublyLL<T> :: Count()
    {
        return iCount;
    }

    template <class T>
    void DoublyLL<T> :: InsertFirst(T iNo)
    {
        struct DoublyLLNode<T>* newn = NULL;
        newn = new struct DoublyLLNode<T>;

        newn -> data = iNo;
        newn -> next = NULL;
        newn -> prev = NULL;

        if(this -> first == NULL)
        {
            this -> first = newn;
        }
        else
        {
            newn -> next = this -> first;
            this -> first -> prev = newn;
            this -> first = newn;
        }

        this -> iCount++;
    }

    template <class T>
    void DoublyLL<T> :: InsertLast(T iNo)
    {
        struct DoublyLLNode<T>* newn = NULL;
        struct DoublyLLNode<T>* temp = NULL;

        newn = new struct DoublyLLNode<T>;


        newn -> data = iNo;
        newn -> next = NULL;
        newn -> prev = NULL;

        if(this -> first == NULL)
        {
            this -> first = newn;
        }
        else
        {
            temp = this -> first;

            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }

            temp -> next = newn;
            newn -> prev = temp;
        }

        this -> iCount++;
    }

    template <class T>
    void DoublyLL<T> :: InsertAtPos(T iNo, int iPos)
    {
        struct DoublyLLNode<T>* newn = NULL;
        struct DoublyLLNode<T>* temp = NULL;
        int i = 0;

        if((iPos < 1)||(iPos > iCount + 1))
        {
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(iNo);
        }
        else if(iPos == iCount + 1)
        {
            InsertLast(iNo);
        }
        else
        {
            newn = new struct DoublyLLNode<T>;
            
            newn -> data = iNo;
            newn -> next = NULL;
            newn -> prev = NULL;
            
            temp = first;
            
            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp -> next;
            }

            newn -> next = temp -> next;
            temp -> next -> prev = newn;
            temp -> next = newn;
            newn -> prev = temp;

            this -> iCount++;
        }
    }

    template <class T>
    void DoublyLL<T> :: DeleteFirst()
    {
        if(this -> first == NULL)
        {
            return;
        }
        else if(this -> first -> next == NULL)
        {
            delete this -> first;
            this -> first = NULL;   
        }
        else
        {
            this -> first = first -> next;
            delete first -> prev;
            this -> first -> prev = NULL;
        }

        this -> iCount--;
    }

    template <class T>
    void DoublyLL<T> :: DeleteLast()
    {
        struct DoublyLLNode<T>* temp = NULL;
        
        if(this -> first == NULL)
        {
            return;
        }
        else if(this -> first -> next == NULL)
        {
            delete this -> first;
            this -> first = NULL;   
        }
        else
        {
            temp = this -> first;

            while(temp -> next -> next != NULL)
            {
                temp = temp -> next;
            }

            delete(temp -> next);
            temp -> next = NULL;
        }

        this -> iCount--;
    }

    template <class T>
    void DoublyLL<T> :: DeleteAtPos(int iPos)
    {
        struct DoublyLLNode<T>* temp = NULL;

        int i = 0;

        if((iPos < 1)||(iPos > iCount))
        {
            return;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == iCount)
        {
            DeleteLast();
        }
        else
        {   
            temp = first;
            
            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp -> next;
            }

            temp -> next = temp -> next -> next;
            delete temp -> next -> prev;
            temp -> next -> prev = temp;

            this -> iCount--;
        }
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    //  Author : Rushikesh Puri
}
