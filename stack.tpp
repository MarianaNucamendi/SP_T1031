#include "stack.h"
#include <iostream>

template <typename T>
Stack<T>::Stack(){
    top = nullptr;
}

template <typename T>
Stack<T>::Node::Node(){
    prev = nullptr;
}

template <typename T>
Stack<T>::~Stack(){
    clear();
}

template<typename T>
bool Stack<T>::push(T data){
    Node *newNode = nullptr;
    newNode = new(std::nothrow) Node;

    if(!newNode)
        return false;

    newNode->data = data;

    if(!top){
        top = newNode;
        return true;
    }

    newNode->prev = top;
    top = newNode;
    return true;
}

template<typename T>
bool Stack<T>::pop(){
    if(!top)
        return false;
    Node *tmp = top;
    top = top->prev;

    delete tmp;
    tmp = nullptr;
    return true;
}

template<typename T>
T* Stack<T>::getTop(){
    return &top->data;
}

template<typename T>
bool Stack<T>::isEmpty(){
    if(!top){
        return true;
    }
    return false;
}

template<typename T>
void Stack<T>::clear(){
    if(!top)
        return;

    Node *tmp = top;

    while(top){
        top = top->prev;
        delete tmp;
        tmp = top;
    }

    top = nullptr;
}