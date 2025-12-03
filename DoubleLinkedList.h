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
    Node *tail;
};

#include "DoubleLinkedList.tpp"