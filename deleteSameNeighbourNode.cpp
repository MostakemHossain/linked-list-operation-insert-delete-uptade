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

void deleteSameNeighbourNodes(Node *&head, Node *&tail)
{
    Node *currNode = tail->prev;
    while (currNode != head)
    {
        Node *prevNode = currNode->prev;
        Node *nextNode = currNode->next;
        if (prevNode->val == nextNode->val)
        {
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            free(currNode);
        }
        currNode = prevNode;
    }
}

int main()
{

    DoublyLinkedList dll;
    dll.insertAtTail(2);
    dll.insertAtTail(1);
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(1);

    dll.display();

    deleteSameNeighbourNodes(dll.head, dll.tail);
    dll.display();
}