#pragma once

template <typename T>
class DoubleLinkedList{
public:
    class Node{
    public:
        Node();
        Node *next;
        Node *prev;
        T data;
    };
    DoubleLinkedList();
    ~DoubleLinkedList();

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

#include "DoubleLinkedList.tpp"