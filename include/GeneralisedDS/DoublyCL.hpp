#pragma once

#include <iostream>

namespace GeneralisedDS
{
    //  Class : DoublyCL   (Doubly Circular Linked List)
    //  Date :  11/07/2026
    //
    /////////////////////////////////////////////////////////////////////////////

    template <class T>
    struct DoublyCLNode
    {
        T data;
        struct DoublyCLNode* next;
        struct DoublyCLNode* prev;
    };

    template <class T>
    class DoublyCL
    {
        private:
            struct DoublyCLNode<T>* first;
            struct DoublyCLNode<T>* last;
            int iCount;

        public:
            DoublyCL();    

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
    DoublyCL<T> :: DoublyCL()
    {
        this -> first  = NULL;
        this -> last   = NULL;
        this -> iCount = 0;
    }   

    template <class T>
    void DoublyCL<T> ::  Display()
    {
        if(first == NULL)
        {
            return;
        }
        
        struct DoublyCLNode<T>* temp = NULL;

        temp = this -> first;

        do
        {
            std::cout<<"| " << temp -> data << " | -> ";
            temp = temp -> next;
        } while (temp != last -> next);
        
        std::cout<<"\n";
    }

    template <class T>
    int DoublyCL<T> :: Count()
    {
        return iCount;
    }

    template <class T>
    void DoublyCL<T> :: InsertFirst(T iNo)
    {
        struct DoublyCLNode<T>* newn = NULL;

        newn = new struct DoublyCLNode<T>;

        newn -> data = iNo;
        newn -> next = NULL;
        newn -> prev = NULL;

        if(this -> first == NULL)
        {
            this -> first = newn;
            this -> last  = newn;
        }
        else
        {
            newn -> next = this -> first;
            this -> first -> prev = newn;
            this -> first = newn;
        }

        this -> iCount++;
        this -> last -> next = this -> first;
        this -> first -> prev = this -> last;
    }

    template <class T>
    void DoublyCL<T> :: InsertLast(T iNo)
    {
        struct DoublyCLNode<T>* newn = NULL;

        newn = new struct DoublyCLNode<T>;

        newn -> data = iNo;
        newn -> next = NULL;
        newn -> prev = NULL;

        if(this -> first == NULL)
        {
            this -> first = newn;
            this -> last  = newn;
        }
        else
        {
            this -> last -> next = newn;
            newn -> prev = this -> last;
            this -> last = newn;
        }

        this -> iCount++;
        this -> last -> next = this -> first;
        this -> first -> prev = this -> last;
    }

    template <class T>
    void DoublyCL<T> :: InsertAtPos(T iNo, int iPos)
    {
        int i = 0;
        struct DoublyCLNode<T>* newn = NULL;
        struct DoublyCLNode<T>* temp = NULL;

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
            newn = new struct DoublyCLNode<T>;
            temp = this -> first;

            newn -> data = iNo;
            newn -> next = NULL;
            newn -> prev = NULL;

            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp -> next;
            }

            newn -> next = temp -> next;
            temp -> next -> prev = newn;
            newn -> prev = temp;
            temp -> next = newn;

            this -> iCount++;
            this -> last -> next = this -> first;
            this -> first -> prev = this -> last;

        }

    }

    template <class T>
    void DoublyCL<T> :: DeleteFirst()
    {
        if(this -> first == NULL && this -> last == NULL)
        {
            return;
        }
        else if(this -> first == this -> last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            this -> first = this -> first -> next;
            delete this -> first -> prev;
        }

        this -> iCount--;
        if(this -> first != NULL)
        {
            this -> last -> next = this -> first;
            this -> first -> prev = this -> last;
        }
    }

    template <class T>
    void DoublyCL<T> :: DeleteLast()
    {
        struct DoublyCLNode<T>* temp = NULL;

        if(this -> first == NULL && this -> last == NULL)
        {
            return;
        }
        else if(this -> first == this -> last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            temp = this -> last;
            this -> last = this -> last -> prev;
            delete temp;
        }

        this -> iCount--;
        if(this -> first != NULL)
        {
            this -> last -> next = this -> first;
            this -> first -> prev = this -> last;
        }

    }

    ////////////////////////////////////////////////////////////////////////////
    //
    //  Author : Rushikesh Puri
}
