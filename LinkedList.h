#ifndef LinkedList_H
#define LinkedList_H

#include "GPU.h"
#include <iostream>

using namespace std;

template <class T>
class LinkedList
{
private:
	struct ListNode
	{
		T value;
		struct ListNode* next;
		struct ListNode* prev;
	};

	ListNode* head;
	ListNode* tail;

public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	//list operations
	void appendNodeFront(T);
	void appendNodeEnd(T);
	void insertNodeAfter(T, int);
	void deleteNode(T);
	void search(T&, string);
	void print();
	int size();
};

template <class T>
int LinkedList<T>::size() 
{
	// Initialize the size counter
	int size = 0;

	// Traverse the linked list and count the number of nodes
	ListNode* nodePtr = head;
	while (nodePtr) {
		size++;
		nodePtr = nodePtr->next;
	}

	// Return the size of the linked list
	return size;
}

template <class T>
void LinkedList<T>::appendNodeFront(T num)
{
	ListNode* newNode, * nodePtr = nullptr;

	//allocate a new node and store num
	newNode = new ListNode;
	newNode->value = num;
	newNode->prev = nullptr;
	newNode->next = nullptr;

	if (!head)   //if there no node in the list
		head = newNode;
	//insert a new node in the front of the existing list
	else
	{
		newNode->next = head;

		//previous of head is the new node
		head->prev = newNode;

		head = newNode;

	}
}

template <class T>
void LinkedList<T>::appendNodeEnd(T num)
{
	ListNode* newNode, * nodePtr = nullptr;

	//allocate a new node and store num
	newNode = new ListNode;
	newNode->value = num;
	newNode->prev = nullptr;
	newNode->next = nullptr;

	if (!head)   //if there no node in the list
		head = newNode;
	//insert a new node in the front of the existing list
	else
	{
		nodePtr = head;

		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
		newNode->prev = nodePtr;

		tail = newNode;

	}
}

template <class T>
void LinkedList<T>::insertNodeAfter(T, int)
{

}

template <class T>
void LinkedList<T>::deleteNode(T p)
{
	ListNode* newNode, * nodePtr = nullptr, * previousNode = nullptr;

	if (!head)
		return;

	if ((head->value).getLastName() == p.getLastName())
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		head->prev = nullptr;
	}

	else
	{
		nodePtr = head->next;

		while (nodePtr != nullptr && ((nodePtr->value).getLastName() != p.getLastName()))
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}



template <class T>
void LinkedList<T>::print()
{
	ListNode* nodePtr = nullptr;

	nodePtr = head;

	while (nodePtr)
	{
		(nodePtr->value).showInfo();
		cout << endl;
		nodePtr = nodePtr->next;
	}
}

/// <Search Function>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name=""></param>
/// <param name="name"></param>
template <class T>
void LinkedList<T>::search(T&, string name)
{
	ListNode* nodePtr = nullptr;

	nodePtr = head;

	bool status = false;


	while (nodePtr)
	{
		if ((nodePtr->value).getName() == name)
		{
			status = true;
			cout << (nodePtr->value).getName() << name << endl;
			break;
		}
		else
			nodePtr = nodePtr->next;
	}

	if (status == false)
	{
		cout << "GPU not Found" << endl;
	}
	else
	{
		cout << "GPU Found\n";
		(nodePtr->value).showInfo();
	}
		
}


#endif