#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    void insertAtTail(int value)
    {
        Node *newNode = new Node(value);
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

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

Node *rotateByK(Node *head, int k)
{

    // step 1: find ll length & capture last node(find tail)
    int n = 1;
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
        n++;
    }

    k = k % 10;

    if (k == 0)
    {
        return head;
    }
    tail->next = head;

    // step 2: Traverse n-k nodes
    Node *temp = head;

    for (int i = 1; i < n - k; i++)
    {
        temp = temp->next;
    }

    // temp is now pointing n-k nodes
    Node *newhead = temp->next;
    temp->next = NULL;

    return newhead;
}

int main()
{
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.insertAtTail(6);

    ll1.display();

    ll1.head = rotateByK(ll1.head, 3);
    ll1.display();
}