#pragma once

template <typename T>
class LinkedList{
public:
    class Node{
    public:
        Node();
        Node *next;
        Node *prev;
        T data;
    };
    LinkedList();
    ~LinkedList();

    bool insertHead(T data);
    bool insertTail(T data);
    bool deleteHead();
    bool deleteTail();
    bool deleteNode(T data);

    void clear();
    void printList();

private:
    Node *head;
    Node *tail;
};

#include "LinkedList.tpp"