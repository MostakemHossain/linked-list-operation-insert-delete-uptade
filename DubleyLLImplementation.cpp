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

    void insertAtStart(int val)
    {

        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
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

    void insertAtPosition(int val, int k)
    {
        Node *temp = head;
        int cnt = 1;
        while (cnt < (k - 1))
        {
            temp = temp->next;
            cnt++;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next->prev = newNode;
        return;
    }

    void deleteAtHead()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head == NULL)
        { // if node is one
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    void deleteAtTail()
    {
        if (head == NULL)
            return;

        Node *temp = tail;
        tail = tail->prev;

        if (tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }
        free(temp);
    }

    void deleteAtKthPosition(int k)
    {
        Node *temp = head;
        int counter = 1;
        while (counter < k)
        {
            temp = temp->next;
            counter++;
        }
        // Now temp is pointing the kth position

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
};

int main()
{

    DoublyLinkedList dll;

    dll.insertAtStart(1);
    dll.insertAtStart(2);
    dll.insertAtStart(3);
    dll.insertAtStart(4);

    dll.display();

    dll.insertAtTail(5);
    dll.insertAtTail(6);
    dll.insertAtTail(7);
    dll.insertAtTail(8);

    dll.display();

    dll.insertAtPosition(10, 5);
    dll.display();

    dll.deleteAtHead();
    dll.display();
    dll.deleteAtTail();
    dll.display();
    dll.deleteAtKthPosition(2);
    dll.display();
}