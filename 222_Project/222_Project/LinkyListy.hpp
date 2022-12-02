

#ifndef LinkyListy_hpp
#define LinkyListy_hpp
#include <stdio.h>

using namespace std;
template <class T>
void LinkyListy<T>::appendNodeFront(T num)
{
    ListNode* newNode, * nodePtr = nullptr;

    newNode = new ListNode;
    newNode->value = num;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (!head)
        head = newNode;

    else
    {
        newNode->next = head;

        head->prev = newNode;
        
        head = newNode;
    }

}

template <class T>
void doublyLinkedList<T>::appendNodeEnd(T num)
{
    ListNode* newNode, * nodePtr = nullptr;


    newNode = new ListNode;
    newNode->value = num;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    
    if (!head)
        head = newNode;
    else
    {
        nodePtr = head;
        while (nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
        newNode->prev = nodePtr;
        newNode->next = nullptr;
        tail = newNode;
    }

}


template <class T>
void doublyLinkedList<T>::deleteNode(T item)
{
    ListNode newNode, * nodePtr = nullptr, * previousNode = nullptr;

    // if the list is empty - print error and return
    if (!head)
    {
        cout << "Error: Node List is Empty." << endl;
        return;
    }

    // checks the head value + removes it if it matches the required item
    if (((head->value).getID()) == item.getID() && ((head->value).getLastName() == item.getLastName()))
    {
        nodePtr = head->next;
        if (head->next)
        {
            delete head;
            head = nodePtr;
            head->prev = nullptr;
            cout << "Node deleted." << endl;
        }
        else
        {
            delete head;
            head = nullptr;
            cout << "Node deleted." << endl;
        }
    }
    else
    {
        nodePtr = head->next;

        // loops through the rest of the linked list + finds the required item (if it exists)
        while (nodePtr != nullptr && (((nodePtr->value).getID() != item.getID()) || ((nodePtr->value).getLastName() != item.getLastName())))
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // if the required item was found - remove it.
        // print error if it is not found.
        if (nodePtr)
        {
            // checks if the item is the second item in the list so the item can be removed properly
            if (nodePtr != head->next)
            {
                previousNode->next = nodePtr->next;
                delete nodePtr;
                cout << "Node deleted." << endl;
            }
            else
            {
                head->next = nodePtr->next;
                delete nodePtr;
                cout << "Node deleted." << endl;
            }
        }
        else
            cout << "Error: Node not found." << endl << endl;
    }
}

//set last name
template <class T>
void doublyLinkedList<T>::search(T&, string name)
{
    ListNode* nodePtr = nullptr;

    nodePtr = head;

    bool status = false;


    while (nodePtr)
    {
        if ((nodePtr->value).getName() == _name)
        {
            cout << (nodePtr->value).getName() << endl;
            status = true;
            break;
        }
        else
            nodePtr = nodePtr->next;
    }

    if (status == false)
        cout << "Not found in Database" << endl;
    else
        cout << "Found in database \n";
}


#endif /* LinkyListy_hpp */
