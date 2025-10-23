#pragma once

template <typename T>
class BinaryTree{
public:
    class Node{
    public:
        Node(T data);
        T data;
        Node *left;
        Node *right;
    };
    BinaryTree();
    ~BinaryTree();
    bool insert(T data);
    bool search(T data);
    bool deleteNode(T data);
    void print();
    bool clear();
    
private:
    bool insertRecursive(Node *&nodo, T data);
    void clearRecursive(Node *&nodo);
    bool searchRecursive(Node *nodo, T data);
    void printRecursive(Node *node, int depth);
    bool searchNodeToErase(Node *&node, T data);
    bool deleteNodeExcecute(Node *&node);
    Node*& maxLeft(Node *&node);

    Node *root;
};

#include "BinaryTree.tpp"