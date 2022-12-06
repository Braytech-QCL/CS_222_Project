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
	void appendNodeEnd(T); //not implemented
	void insertNodeAfter(T, int); //not implemented
	void deleteNode(T); //not implemented
	void deleteItem(T& item, string name);
	void destroyList();
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
void LinkedList<T>::search(T& item, string name)
{
	ListNode* nodePtr = nullptr; // Create a pointer to traverse the list

	nodePtr = head; // Start at the head of the list

	bool status = false; // Keep track of whether the item was found

	// Traverse the list until we find the item with the specified name
	while (nodePtr != nullptr)
	{
		if ((nodePtr->value).getName() == name)
		{
			// We have found the item
			status = true;
			break;
		}
		else
		{
			// Move to the next node
			nodePtr = nodePtr->next;
		}
	}

	// Check if the item was found
	if (status == false)
	{
		cout << "Item not found" << endl;
	}
	else
	{
		cout << "Item found\n\n";
		(nodePtr->value).showInfo(); // Output information about the item
	}
}


template <class T>
void LinkedList<T>::deleteItem(T& item, string name)
{
	ListNode* nodePtr = head; // Start at the head of the list
	ListNode* previousNode = nullptr; // Keep track of the previous node

	// Traverse the list until we find the item with the specified name
	while (nodePtr != nullptr)
	{
		if ((nodePtr->value).getName() == name)
		{
			// We have found the item to delete
			break;
		}
		else
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
	}

	// Check if the item was found
	if (nodePtr == nullptr)
	{
		cout << "Item not found" << endl;
		return;
	}

	// If the item to delete is the head of the list, we need to update the head pointer
	if (nodePtr == head)
	{
		head = nodePtr->next;
	}
	else
	{
		previousNode->next = nodePtr->next;
	}

	// Delete the node
	delete nodePtr;
	cout << "Item deleted" << endl;
}


template <class T>
void LinkedList<T>::destroyList()
{
	ListNode* nodePtr = head; // Start at the head of the list

	// Traverse the list, deleting each node
	while (nodePtr != nullptr)
	{
		ListNode* temp = nodePtr;
		nodePtr = nodePtr->next;
		delete temp;
	}

	// Set the head pointer to null to indicate that the list is empty
	head = nullptr;
}


#endif