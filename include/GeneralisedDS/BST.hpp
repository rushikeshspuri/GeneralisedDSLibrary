#pragma once

#include <iostream>

namespace GeneralisedDS
{
    template <class T>
    class Node
    {
        public:
            T data;
            Node<T> *lchild;
            Node<T> *rchild;
    
            Node(T iNo)
            {
                data = iNo;
                lchild = NULL;
                rchild = NULL;
            }
    };
    
    
    ////////////////////////////////////////////////////////////////////////////
    //
    //  Author : Rushikesh Puri
    //  Class : Binary Search Tree (BST)   
    //  Date :  11/07/2026
    //
    /////////////////////////////////////////////////////////////////////////////
    
    template <class T>
    class BST
    {
        private:
            Node<T> *root;
    
            void Inorder(Node<T> *root);
            void Preorder(Node<T> *root);
            void Postorder(Node<T> *root);
            int Count(Node<T> *root);
            int CountLeaf(Node<T> *root);
            int CountParent(Node<T> *root);
    
        public:
            BST();
    
            void Insert(T iNo);
            bool Search(T iNo);
    
            void Inorder();
            void Preorder();
            void Postorder();
    
            int Count();
            int CountLeaf();
            int CountParent();
    };
    
    // ---------- Constructor ----------
    
    template <class T>
    BST<T> :: BST()
    {
        root = NULL;
    }
    
    // ---------- Private recursive helpers (take a Node<T>*) ----------
    
    template <class T>
    void BST<T> :: Inorder(Node<T> *root)
    {
        if(root != NULL)
        {
            Inorder(root -> lchild);
            std::cout << root -> data << std::endl;
            Inorder(root -> rchild);
        }
    }
    
    template <class T>
    void BST<T> :: Preorder(Node<T> *root)
    {
        if(root != NULL)
        {
            std::cout << root -> data << std::endl;
            Preorder(root -> lchild);
            Preorder(root -> rchild);
        }
    }
    
    template <class T>
    void BST<T> :: Postorder(Node<T> *root)
    {
        if(root != NULL)
        {
            Postorder(root -> lchild);
            Postorder(root -> rchild);
            std::cout << root -> data << std::endl;
        }
    }
    
    template <class T>
    int BST<T> :: Count(Node<T> *root)
    {
        if(root == NULL)
        {
            return 0;
        }
    
        return 1 + Count(root -> lchild) + Count(root -> rchild);
    }
    
    template <class T>
    int BST<T> :: CountLeaf(Node<T> *root)
    {
        if(root == NULL)
        {
            return 0;
        }
    
        if(root -> rchild == NULL && root -> lchild == NULL)
        {
            return 1;
        }
    
        return CountLeaf(root -> lchild) + CountLeaf(root -> rchild);
    }
    
    template <class T>
    int BST<T> :: CountParent(Node<T> *root)
    {
        if(root == NULL)
        {
            return 0;
        }
    
        if(root -> rchild != NULL || root -> lchild != NULL)
        {
            return 1 + CountParent(root -> lchild) + CountParent(root -> rchild);
        }
    
        return 0;
    }
    
    // ---------- Public functions (take no argument, use member 'root') ----------
    
    template <class T>
    void BST<T> :: Insert(T iNo)
    {
        Node<T> *newn = NULL;
        Node<T> *temp = NULL;
    
        newn = new Node<T>(iNo);
    
        if(root == NULL)
        {
            root = newn;
        }
        else
        {
            temp = root;
            while(1)
            {
                if(iNo > temp -> data)
                {
                    if(temp -> rchild == NULL)
                    {
                        temp -> rchild = newn;
                        break;
                    }
    
                    temp = temp -> rchild;
                }
                else if(iNo < temp -> data)
                {
                    if(temp -> lchild == NULL)
                    {
                        temp -> lchild = newn;
                        break;
                    }
    
                    temp = temp -> lchild;
                }
                else if(iNo == temp -> data)
                {
                    std::cout << "Unable to insert bcoz element is duplicate." << std::endl;
                    delete newn;
                    break;
                }
            }
        }
    }
    
    template <class T>
    bool BST<T> :: Search(T iNo)
    {
        bool bFlag = false;
        Node<T> *temp = root;
    
        while(temp != NULL)
        {
            if(iNo == temp -> data)
            {
                bFlag = true;
                break;
            }
            else if(iNo > temp -> data)
            {
                temp = temp -> rchild;
            }
            else if(iNo < temp -> data)
            {
                temp = temp -> lchild;
            }
        }
    
        return bFlag;
    }
    
    template <class T>
    void BST<T> :: Inorder()
    {
        Inorder(root);
    }
    
    template <class T>
    void BST<T> :: Preorder()
    {
        Preorder(root);
    }
    
    template <class T>
    void BST<T> :: Postorder()
    {
        Postorder(root);
    }
    
    template <class T>
    int BST<T> :: Count()
    {
        return Count(root);
    }
    
    template <class T>
    int BST<T> :: CountLeaf()
    {
        return CountLeaf(root);
    }
    
    template <class T>
    int BST<T> :: CountParent()
    {
        return CountParent(root);
    }
}
