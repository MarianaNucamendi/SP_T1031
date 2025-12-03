#include "queue.h"
#include <iostream>

template <typename T>
Queue<T>::Queue(){
    front = nullptr;
    back = nullptr;
}

template <typename T>
Queue<T>::Node::Node(){
    prev = nullptr;
}

template <typename T>
Queue<T>::~Queue(){
    clear();
}

template <typename T>
bool Queue<T>::enqueue(T data){
    Node *newNode = nullptr;
    newNode = new(std::nothrow) Node;

    if(!newNode)
        return false;

    newNode->data = data;

    if(!front){
        front = newNode;
        back = newNode;
        return true;
    }

    back->prev = newNode;
    back = newNode;
    return true;
}

template <typename T>
bool Queue<T>::dequeue(){
    if(!front)
        return false;

    if(front == back){
        delete front;
        front = nullptr;
        back = nullptr;
        return true;
    }

    Node *tmp = front;
    front = front->prev;

    delete tmp;
    tmp = nullptr;
    return true;
}

template <typename T>
T* Queue<T>::getFront(){
    return &front->data;
}

template <typename T>
bool Queue<T>::isEmpty(){
    if(!front)
        return true;
    return false;
}

template <typename T>
void Queue<T>::clear(){
    if(!front)
        return;

    if(front == back){
        delete front;
        front = nullptr;
        back = nullptr;
        return;
    }

    Node* tmp = front;

    while(tmp){
        front = front->prev;
        delete tmp;
        tmp = front;
    }

    front = nullptr;
    back = nullptr;
    tmp = nullptr;
}