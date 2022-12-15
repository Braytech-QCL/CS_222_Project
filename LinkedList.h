/*
Linked list functionality for GPU database
*/
#ifndef LinkedList_H
#define LinkedList_H

#include "GPU.h"
#include <iostream>

using namespace std;

template <class T>
class LinkedList
{
private:
	/**

	This is the ListNode struct for the LinkedList class.
	It contains a value of the specified type and pointers to the next and previous nodes in the list.
	*/
	struct ListNode
	{
		T value;
		struct ListNode* next;
		struct ListNode* prev;
	};

	ListNode* head; //This is the head pointer for the LinkedList class. It points to the first node in the list.
	ListNode* tail; //This is the tail pointer for the LinkedList class. It points to the last node in the list.
	

public:
	/**
	This is the default constructor for the LinkedList class.
	It initializes the head and tail pointers to nullptr.
	*/
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	//list operations
	void appendNodeFront(T); //appends a new node with the given value to the front of the list
	void appendNodeEnd(T); //not used, appends a new node with the given value to the end of the list
	void deleteNode(T); //not used, deletes the first node with the given value from the list
	void deleteItem(T& item, string name); //deletes the item with the given name from the list
	void destroyList(); //deletes all nodes in the list
	void search(T&, string); // searches for an item with the given name in the list and outputs its information if found
	void print(); //outputs the information of all items in the list
	int size(); //returns the number of nodes in the list

	void printByArch(string arch); //This function prints the items in the LinkedList that are of the specified architecture.
	void printByMan(string manufacturer); //This function prints the items in the LinkedList that are manufactured by the specified manufacturer.
	void printByGen(string generation); //This function prints the items in the LinkedList that are of the specified generation.
};

/**
	This function returns the number of nodes in the LinkedList.

	Preconditions:
		'head' points to the first node of a LinkedList

	Postconditions:
		the number of nodes in the LinkedList is returned
*/
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

/**

	This function adds a new node to the front of the LinkedList.

	Preconditions:
		'num' is a T object
		'head' points to the first node of a LinkedList

	Postconditions:
		a new node is created and added to the front of the list
		the 'head' pointer is updated to point to the new node
*/
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

/**

	This function adds a new node to the end of the LinkedList.

	Preconditions:
		'num' is a T object
		'head' points to the first node of a LinkedList

	Postconditions:
		a new node is created and added to the end of the list
		the 'tail' pointer is updated to point to the new node
*/
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

/**
	This function deletes a node from the LinkedList.

	Preconditions:
		'p' is a T object
		'head' points to the first node of a LinkedList

	Postconditions:
		if 'p' is the first item in the list, it is deleted and the head pointer
	is updated to point to the next item in the list

		if 'p' is not the first item in the list, it is deleted and the next
	pointer of the previous node is updated to point to the next node in the
	list
*/
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



/**

	This function prints the items in the LinkedList to the console.

	Preconditions:
		'head' points to the first node of a LinkedList

	Postconditions:
		the items in the list are printed to the console
*/
template <class T>
void LinkedList<T>::print()
{
	ListNode* nodePtr = nullptr;

	nodePtr = head;

	// Traverse the list and print the items
	while (nodePtr)
	{
		(nodePtr->value).showInfo();
		cout << endl;
		nodePtr = nodePtr->next;
	}
}

/**
This function prints the items in the LinkedList that are manufactured by the specified manufacturer.

Preconditions:
	'head' points to the first node of a LinkedList
	'manufacturer' is a string specifying the name of the manufacturer

Postconditions:
	the items in the list that are manufactured by the specified manufacturer are printed to the console

*/
template <class T>
void LinkedList<T>::printByMan(string manufacturer)
{
	ListNode nodePtr = nullptr;

	nodePtr = head;

	// Traverse the list and print the items
	while (nodePtr)
	{
		if ((nodePtr-> value).getBrand() == manufacturer)
		{
			(nodePtr->value).showInfo();
			cout << endl;
		}
		nodePtr = nodePtr->next;
	}
}

/**
This function prints the items in the LinkedList that are of the specified generation.

Preconditions:
	'head' points to the first node of a LinkedList
	'generation' is an string specifying the generation of graphics cards to print

Postconditions:
	the items in the list that are of the specified generation are printed to the console
	*/
template <class T>
void LinkedList<T>::printByGen(string generation)
{
	ListNode nodePtr = nullptr;

	nodePtr = head;

	// Traverse the list and print the items
	while (nodePtr)
	{
		if ((nodePtr-> value).getGeneration() == generation)
		{
			(nodePtr->value).showInfo();
			cout << endl;
		}
		nodePtr = nodePtr->next;
	}
}

/**
This function prints the items in the LinkedList that are of the specified architecture.
	
Preconditions:
	'head' points to the first node of a LinkedList
	'arch' is a string specifying the architecture of graphics cards to print

Postconditions:
	the items in the list that are of the specified architecture are printed to the console
	*/
template <class T>
void LinkedList<T>::printByArch(string arch)
{
	ListNode* nodePtr = nullptr;

	nodePtr = head;

	// Traverse the list and print the items
	while (nodePtr)
	{
		if ((nodePtr-> value).getArchitecture() == arch)
		{
			(nodePtr->value).showInfo();
			cout << endl;
		}
		nodePtr = nodePtr->next;
	}
}

/**

	This function searches for an item in the LinkedList.

	Preconditions:
		'item' is a reference to a T object
		'name' is the name of the item to be searched for

	Postconditions:
		if the item with the specified name is found in the list, information
	about the item is printed to the console and a message is printed
	indicating that the item was found 
	
		if the item with the specified name is not found in the list, a message
	is printed to the console indicating that the item was not found

	@param item A reference to a T object
	@param name The name of the item to be searched for
*/
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

/**

	This function deletes an item from the LinkedList.

	Preconditions:
		'item' is a reference to a T object
		'name' is the name of the item to be deleted

	Postconditions:
		if the item with the specified name is found in the list, it is deleted

	and a message is printed to the console indicating that the item has been

	deleted
		if the item with the specified name is not found in the list, a message

	is printed to the console indicating that the item was not found

	@param item A reference to a T object

	@param name The name of the item to be deleted
*/
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

/**

	This function destroys the LinkedList by freeing up the memory occupied by its

	nodes.

	Preconditions:
		'head' points to the first node of a LinkedList

	Postconditions:
		the memory occupied by the LinkedList is freed
		the head pointer is set to null to indicate that the list is empty
*/
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