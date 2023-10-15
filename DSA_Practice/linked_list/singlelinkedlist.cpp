#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize a node
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Linked list class with various operations
class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Insertion at the beginning of the linked list
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Insertion at the end of the linked list
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Traversal of the linked list
    void traverse()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Searching for a specific value in the linked list
    bool search(int key)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Deletion of a node from the linked list
    void deletionNode(int key)
    {
        Node *temp = head;
        Node *prev = NULL;

        if (temp != NULL && temp->data == key)
        {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Key not found." << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    // Reversal of the linked list
    void reverse()
    {
        Node *prev = NULL, *curr = head, *next = head;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main()
{
    LinkedList myList;

    myList.insertAtBeginning(3);
    myList.insertAtEnd(5);
    myList.insertAtBeginning(3);
    myList.insertAtEnd(7);

    cout << "Original List: ";
    myList.traverse();

    myList.deletionNode(5);
    cout << "After Deletion: ";
    myList.traverse();

    cout << "Is 2 present? " << (myList.search(2) ? "Yes" : "No") << endl;

    myList.reverse();
    cout << "After Deletion: ";
    myList.traverse();

    return 0;
}