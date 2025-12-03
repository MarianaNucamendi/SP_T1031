#pragma once

template <typename T>
class Queue{
public:
    class Node{
    public:
        Node();
        T data;
        Node *prev;
    };
    Queue();
    ~Queue();

    bool enqueue(T data);
    bool dequeue();
    T* getFront();
    bool isEmpty();

    void clear();
    void print();


private:
    Node *front, *back;
};

#include "queue.tpp"