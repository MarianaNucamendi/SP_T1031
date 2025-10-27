#include <iostream>
#include "DoubleLinkedList.h"

template <typename T>
DoubleLinkedList<T>::Node::Node(){
    next = nullptr;
    prev = nullptr;
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(){
    head = nullptr;
    tail = nullptr;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){
    clear();
}

template <typename T>
bool DoubleLinkedList<T>::insertHead(T data){
    Node *newNode = new(std::nothrow) Node;
    if(!newNode)
        return false;

    newNode->data = data;

    if(!head){
        head = newNode;
        tail = newNode;
        return true;
    }

    Node *tmp = head;

    tmp->prev = newNode;

    head = newNode;

    head->next = tmp;

    return true;
}

template <typename T>
bool DoubleLinkedList<T>::insertTail(T data){
    Node *newNode = new(std::nothrow) Node;
    if(!newNode)
        return false;

    newNode->data = data;

    if(!head){
        head = newNode;
        tail = newNode;
        return true;
    }

    Node *tmp = tail;

    tmp->next = newNode;
    tail = newNode;
    tail->prev = tmp;
    return true;
}

template <typename T>
bool DoubleLinkedList<T>::deleteHead(){
    if(!head)
        return false;

    if(!head->next){
        delete head;
        head = nullptr;
        tail = nullptr;
        return true;
    }

    Node *tmp = head->next;
    
    delete head;

    head = tmp;
    head->prev = nullptr;
    return true;
}

template <typename T>
bool DoubleLinkedList<T>::deleteTail(){
    if(!head)
        return false;

    if(!head->next){
        delete head;
        head = nullptr;
        tail = nullptr;
        return true;
    }

    Node *tmp = tail->prev;

    delete tail;

    tail = tmp;
    tail->next = nullptr;
    return true;
}

template <typename T>
bool DoubleLinkedList<T>::deleteNode(T data){
    if(!head)
        return false;

    if(head->data == data){
        deleteHead();
        return true;
    }

    if(tail->data == data){
        deleteTail();
        return true;
    }

    Node *tmp = head->next, *tmpPrev = nullptr, *tmpNext = nullptr;

    while(tmp){
        if(tmp->data == data){
            tmpPrev = tmp->prev;
            tmpNext = tmp->next;

            tmpPrev->next = tmpNext;
            tmpNext->prev = tmpPrev;

            delete tmp;
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

template <typename T>
void DoubleLinkedList<T>::clear(){
    if(!head)
        return;

    Node *tmp = head;

    while(tmp){
        tmp = head->next;
        delete head;
        head = tmp;
    }

    head = nullptr;
    tail = nullptr;
}

template <typename T>
void DoubleLinkedList<T>::printList(){
    if(!head)
        return;

    Node *tmp = head;

    while(tmp){
        std::cout << tmp->data << "\n";
        tmp = tmp->next;
    }
    std::cout << "\n";
}