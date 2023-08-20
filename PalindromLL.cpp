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

bool palindrome(Node *head)
{
    // step 1: find middle element
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // now slow is pointing to middle element

    // step 2: break the linked list in the middle

    Node *prev = slow;
    Node *current = slow->next;
    slow->next = NULL;

    // step 3: reverse the second half of the linked list

    while (current)
    {
        Node *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    // step 4: check the two linked list are equal or not

    Node *head1 = head;
    Node *head2 = prev;
    while (head2)
    {
        if (head1->val != head2->val)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

int main()
{
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(2);
    ll1.insertAtTail(1);

    cout << palindrome(ll1.head) << endl;
}