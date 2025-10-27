#include "LinkedList.h"
#include <iostream>

template <typename T>
LinkedList<T>::Node::Node() {
	next = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList() {
	head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
bool LinkedList<T>::insertHead(T data) {
	Node *newNode = nullptr;

	newNode = new(std::nothrow) Node();
	if(!newNode)
		return false;
    
    newNode->data = data;
    
    if(!head){
        head = newNode;
        return true;
    }
	newNode->next = head;

	head = newNode;

	return true;
}

template <typename T>
bool LinkedList<T>::insertTail(T data) {
    Node *newNode = nullptr;
    
    newNode = new(std::nothrow) Node();
    if(!newNode)
        return false;

    newNode->data = data;

    if(!head){
        head = newNode;
        return true;
    }

    Node *temp = head;

    while(temp->next){
        temp = temp->next;
    }

    temp->next = newNode;
    return true;
}

template <typename T>
bool LinkedList<T>::deleteHead(){
    if(!head)
        return false;

    Node *temp = head->next;

    delete head;

    head = temp;
    return true;
}

template <typename T>
bool LinkedList<T>::deleteTail(){
    if(!head)
        return false;

    if(!head->next){
        delete head;
        head = nullptr;
        return true;
    }

    Node *newTail = head;

    while(newTail->next->next){
        newTail = newTail->next;
    }

    delete newTail->next;
    newTail->next = nullptr;

    return true;
}

template <typename T>
bool LinkedList<T>::deleteNode(T data){
    if(!head)
        return false;

    if(head->data == data){
        deleteHead();
        return true;
    }

    Node *prevNode = head, *nodeData = prevNode->next;

    while(nodeData && nodeData->data != data){
        prevNode = prevNode->next;
        nodeData = nodeData->next;
    }

    if(!nodeData)
        return false;

    prevNode->next = nodeData->next;

    delete nodeData;
    nodeData = nullptr;
    return true;
}

template <typename T>
void LinkedList<T>::printList(){
    if(!head)
        return;

    Node *temp = head;
    while(temp){
        std::cout << temp->data << "\n";
        temp = temp->next;
    }
    std::cout << "\n";
}

template <typename T>
void LinkedList<T>::clear(){
    if(!head)
        return;

    Node *temp = head;

    while(temp){
        head = head->next;
        delete temp;
        temp = head;
    }
    head = nullptr;
}