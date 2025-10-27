#pragma once
#include <iostream>

template <class T>

class LinkedList {
public:
	class Node {
		public:
			Node();
			T data;
			Node *next;		
	};

	LinkedList();
	~LinkedList();

	bool insertHead(T data);
    bool insertTail(T data);
	bool deleteHead();
	bool deleteTail();
	bool deleteNode(T data);

    void printList();
    void clear();
	
private:
	Node *head;
};

#include "LinkedList.tpp"