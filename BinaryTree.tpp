#include <iostream>
#include "BinaryTree.h"

template <typename T>
BinaryTree<T>::Node::Node(T nData) : data(nData), left(nullptr), right(nullptr) {}

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    clear();
}

template <typename T>
bool BinaryTree<T>::insert(T data){
    return insertRecursive(root, data);
}

template <typename T>
bool BinaryTree<T>::insertRecursive(Node *&node, T data){
    if(!node){
        node = new(std::nothrow) Node(data);
        if(!node)
            return false;
        return true;
    }

    if(data < node->data)
        return insertRecursive(node->left, data);
    else if(data > node->data)
        return insertRecursive(node->right, data);
    return false;
}


template <typename T>
bool BinaryTree<T>::search(T data){
    return searchRecursive(root, data);
}

template <typename T>
bool BinaryTree<T>::searchRecursive(Node *node, T data){
    if(!node)
        return false;

    if(node->data == data)
        return true;

    if(node->data > data)
        return searchRecursive(node->left, data);
    if(node->data < data)
        return searchRecursive(node->right, data);
    return false;
}

template <typename T>
bool BinaryTree<T>::deleteNode(T data){
    if(!root)
        return false;
    searchNodeToErase(root, data);
    return true;
}

template <typename T>
bool BinaryTree<T>::searchNodeToErase(Node *&node, T data){
    if(!node)
        return false;

    if(data == node->data){
        return deleteNodeExcecute(node);  
    }

    if(data < node->data)
        return searchNodeToErase(node->left, data);
    if(data > node->data)
        return searchNodeToErase(node->right, data);
    
    return false;
}

template <typename T>
bool BinaryTree<T>::deleteNodeExcecute(Node *&node){
    if(!node->left && !node->right){
        delete node;
        node = nullptr;
        return true;
    }
    if(!node->left){
        Node *tmp = nullptr;
        tmp = node->right;

        delete node;
        node = tmp;
        return true;
    }
    if(!node->right){
        Node *tmp = nullptr;
        tmp = node->left;

        delete node;
        node = tmp;
        return true;
    }
    if(node->left && node->right){
        Node *&tmp = maxLeft(node->left);

        node->data = tmp->data;

        if(tmp->left){
            Node *leftTree = nullptr;
            leftTree = tmp->left;
            delete tmp;
            tmp = leftTree;
            return true;
        }

        delete tmp;
        tmp = nullptr;
        return true;
    }
    return false;
}

template <typename T>
typename BinaryTree<T>::Node*& BinaryTree<T>::maxLeft(Node *&node){
    if(node->right)
        return maxLeft(node->right);   
    return node;
}

template <typename T>
bool BinaryTree<T>::clear(){
    if(!root)
        return false;
    clearRecursive(root);
    return true;
}

template <typename T>
void BinaryTree<T>::clearRecursive(Node *&node){
    if(node->left){
        clearRecursive(node->left);
    }
    if(node->right){
        clearRecursive(node->right);
    }

    delete node;
    node = nullptr;
    return;   
}

template <typename T>
void BinaryTree<T>::print(){
    if(!root)
        return;
    int depth = 0;   
    printRecursive(root, depth);
}

template <typename T>
void BinaryTree<T>::printRecursive(Node *node, int depth){
    if(node->right)
        printRecursive(node->right, depth+1);
    
    for(int i = 0;i < depth; i++){
        std::cout << "    ";
    }
    std::cout << node->data << std::endl;
    
    if(node->left)
        printRecursive(node->left,depth+1);
}