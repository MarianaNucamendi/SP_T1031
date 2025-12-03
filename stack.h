#pragma once

template<class T>
class Stack{
public:
    class Node{
    public:
        Node();
        Node *prev;
        T data;  
    };
    Stack();
    ~Stack();

    bool push(T data);
    bool pop();
    T* getTop();
    bool isEmpty();
    void clear();
private:
    Node *top;
};

#include "stack.tpp"