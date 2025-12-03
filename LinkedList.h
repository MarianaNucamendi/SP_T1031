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
	bool insertInOrder(T data);

	bool deleteHead();
	bool deleteTail();
	bool deleteNode(T data);

	bool exists(T data);
	unsigned int getSize();

    void printList();
    void clear();

	class Iterator{
	public:
		Iterator(Node* ptr) : current(ptr) {}
		Iterator& operator++() { if (current) current = current->next; return *this;}
		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
		bool operator!=(const Iterator& other) const { return current != other.current; }
		bool operator==(const Iterator& other) const { return current == other.current; }
		T& operator*() const { return current->data; }
		T* operator->() const { return &(current->data); }
		private:
			Node* current;
	};

	Iterator begin() const { return Iterator(head); }
	Iterator end() const { return Iterator(nullptr); }
	
private:
	Node *head;
};

#include "LinkedList.tpp"