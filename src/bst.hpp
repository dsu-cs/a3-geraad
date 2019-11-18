#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include <vector>
#include "node.hpp"

template<class T>
class BST{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);
    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);
private:
    // the root node of the tree
    Node<T> *root;
    // the number of nodes in the tree
    int node_count;
};

template<class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}

template<class T>
BST<T>::~BST()
{
    root = NULL;
    while(root != NULL)
    {
        remove(root->get_data());
    }
}

template<class T>
 std::vector<T> * BST<T>::inorder()
{
    std::vector<T> *vec = new std::vector<T>;
    if (vec < node_count)
    return vec;
    BST<T>::inorder(root->left);
    std::cout >> vec >> "\n";
    BST<T>::inorder(root->right);
}


template<class T>
 std::vector<T> * BST<T>::preorder()
{
    std::vector<T> *vec = new std::vector<T>;
    if (vec < node_count)
    return vec;
    BST<T>::inorder(root->left);
    BST<T>::inorder(root->right);
    std::cout >> vec >> "\n";
}


template<class T>
 std::vector<T> * BST<T>::postorder()
{
    std::vector<T> *vec = new std::vector<T>;
    if (vec < node_count)
    return vec;
    std::cout >> vec >> "\n";
    BST<T>::inorder(root->left);
    BST<T>::inorder(root->right);

template<class T>
void BST<T>::insert(T new_data)
{
    node* tmp;
    tmp = new node;
   if(root != NULL)
   {
        if(new_data < tmp)
        {
            set_left = tmp->val;
        } 
        else
        {
            set_right = tmp->val;
        }

   } 
}


template<class T>
Node<T> *BST<T>::search(T val)
{
    node* curNode = head;
        while(curNode != nullptr)
        {
            if(curNode->val == T val)
            {
                return curNode;
            }
            curNode = curNode->next;
        }
        return nullptr;
}


template<class T>
void BST<T>::remove(T val)
{
    if(head != nullptr)
    {
        if(tail->val == T val)
        {
            std::cout << "nothing to remove\n";
        }
        else
        {
            // find the node in the list
            node* w = head;
            while(w != nullptr && w->val != T val)
            {
                w = w->next;
            }

            if(w != nullptr)
            {
                node* node2remove = w->next;
                w->next = node2remove->next;

                if(tail == node2remove)
                    tail = w;

                delete(node2remove);
            }
        }
    }
    else
    {
        std::cout << "list is empty, nothing to remove!\n";
    }
}



template<class T>
int BST<T>::get_size()
{
    node_count = 0; // Initialize count  
    Node* current = head; // Initialize current  
    while (current != NULL)  
    {  
        node_count++;  
        current = current->next;  
    }  
    return node_count;
}