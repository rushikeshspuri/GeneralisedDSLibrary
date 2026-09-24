#pragma once

#include <iostream>

namespace GeneralisedDS
{
    /////////////////////////////////////////////////////////////////////////////
    //  Class : SinglyCL   (Singly Circular Linked List)
    //  Date :  11/07/2026
    //  Author : Rushikesh Puri
    /////////////////////////////////////////////////////////////////////////////


    template <class T>
    struct SinglyCLNode
    {
        T data;
        struct SinglyCLNode<T>* next;
        
    };

    template <class T>
    class SinglyCL
    {
        private:
            struct SinglyCLNode<T>* first;
            struct SinglyCLNode<T>* last;
            int iCount;
        
        public:
            SinglyCL();
            
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
    SinglyCL<T> :: SinglyCL()
    {
        this -> first = NULL;
        this -> last  = NULL;
        this -> iCount = 0;
    }

    template <class T>
    void SinglyCL<T> :: Display()
    {
        if(first == NULL && last == NULL)
        {
            return;
        }
        
        struct SinglyCLNode<T>* temp = NULL;

        temp = first;

        do
        {
            std::cout<<"| "<<temp -> data <<" | ->" ;
            temp = temp -> next;
        } while (temp != last -> next);
        
      

        std::cout<<std::endl;
    }

    template <class T>
    int  SinglyCL<T> :: Count()
    {
        return iCount;
    }

    template <class T>
    void SinglyCL<T> :: InsertFirst(T iNo)
    {
        struct SinglyCLNode<T>* newn = NULL;

        newn = new struct SinglyCLNode<T>;
        newn -> data = iNo;
        newn -> next = NULL;

        if(first == NULL && last == NULL)
        {
            this -> first = newn;
            this -> last = newn;
        }
        else
        {
            newn -> next = this -> first;
            this -> first = newn;
        }

        this -> iCount++;
        this -> last -> next = this -> first ;
        
    }

    template <class T>
    void SinglyCL<T> :: InsertLast(T iNo)
    {
        struct SinglyCLNode<T>* newn = NULL;

        newn = new struct SinglyCLNode<T>;
        newn -> data = iNo;
        newn -> next = NULL;

        if(first == NULL && last == NULL)
        {
            this -> first = newn;
            this -> last = newn;
        }
        else
        {
            this -> last -> next = newn;
            this -> last = newn;
        }

        this -> iCount++;
        this -> last -> next = this -> first;
    }

    template <class T>
    void SinglyCL<T> :: InsertAtPos(T iNo, int iPos)
    {
        int i = 0;
        struct SinglyCLNode<T>* newn = NULL;
        struct SinglyCLNode<T>* temp = NULL;

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
            temp = this -> first;
            newn = new struct SinglyCLNode<T>;

            newn -> data = iNo;
            newn -> next = NULL;

            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp -> next;
            }

            newn -> next = temp -> next;
            temp -> next = newn;

            this -> iCount++;
            this -> last -> next = this -> first;

        }
    }

    template <class T>
    void SinglyCL<T> :: DeleteFirst()
    {
        if(first == NULL)
        {
            return;
        }
        else if(first == last)
        {
            delete this -> first;
            this -> first = NULL;
            this -> last =  NULL;
        }
        else
        {
            this -> first = this -> first -> next;
            delete last -> next;
        }

        this -> iCount--;

        if(this -> first != NULL)
        {
            this -> last -> next = this -> first;
        }
    }

    template <class T>
    void SinglyCL<T> :: DeleteLast()
    {
        struct SinglyCLNode<T>* temp = NULL;

        if(first == NULL)
        {
            return;
        }
        else if(first == last)
        {
            delete this -> first;
            this -> first = NULL;
            this -> last =  NULL;
        }
        else
        {
            temp = this -> first;

            while(temp -> next -> next != this -> first)
            {
                temp = temp -> next;
            }

            delete temp -> next;
            this -> last = temp;
        }

        this -> iCount--;

        if(this -> first != NULL)
        {
            this -> last -> next = this -> first;
        }
    }

    template <class T>
    void SinglyCL<T> :: DeleteAtPos(int iPos)
    {
        int i = 0;
        struct SinglyCLNode<T>* temp = NULL;
        struct SinglyCLNode<T>* target = NULL;

        if((iPos < 1)||(iPos > iCount))
        {
            return;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == iCount )
        {
            DeleteLast();
        }
        else
        {
            temp = this -> first;

            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp -> next;
            }

            target = temp -> next;
            temp -> next = temp -> next -> next;
            delete target;

            this -> iCount--;
            this -> last -> next = this -> first;

        }
    }

}
