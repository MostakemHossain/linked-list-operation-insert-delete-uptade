#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;

    Node(int val)
    {
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {

            cout << temp->val;
            if (temp->next != NULL)
            {
                cout << "<->";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        return;
    }
};

void reverseDLL(Node *&head, Node *&tail)
{

    Node *currPtr = head;
    while (currPtr)
    {
        Node *nextPtr = currPtr->next;
        currPtr->next = currPtr->prev;
        currPtr->prev = nextPtr;
        currPtr = nextPtr;
    }

    // swap head & tail

    Node *temp = tail;
    tail = head;
    head = temp;
}
int main()
{

    DoublyLinkedList dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.insertAtTail(4);
    dll.insertAtTail(5);
    dll.display();
    reverseDLL(dll.head, dll.tail);
    dll.display();
}