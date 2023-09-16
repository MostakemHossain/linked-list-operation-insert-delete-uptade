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

void insertAtHead(Node *&head, int val)
{
    Node *new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void insert_at_Tail(Node *&head, int val)
{
    Node *new_node = new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}
void updateAt_position(Node *&head, int k, int val)
{
    int curr_pos = 1;
    Node *temp = head;
    while (curr_pos != k)
    {
        temp = temp->next;
        curr_pos++;
    }

    temp->val = val;
}

void insert_at_position(Node *&head, int val, int pos)
{

    if (pos == 1)
    {
        insertAtHead(head, val);
        return;
    }
    int current_pos = 1;
    Node *temp = head;
    Node *new_node = new Node(val);
    while (current_pos != pos - 1)
    {
        temp = temp->next;
        current_pos++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void deleteAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteAtTail(Node *&head)
{
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = NULL;
    free(deleteNode);
}

void deleteAtPosition(Node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    int curr_pos = 1;
    Node *prev = head;
    while (curr_pos != pos - 1)
    {
        prev = prev->next;
        curr_pos++;
    }
    Node *temp = prev->next;
    prev->next = prev->next->next;
    free(temp);
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {

        cout << temp->val;
        if (temp->next != NULL)
        {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl
         << endl;
}

int main()
{
    Node *head = NULL;
    cout << "Case 1:Insert at head\n";
    cout << "Case 2:Insert at Tail\n";
    cout << "Case 3:Insert at Specific Position\n";
    cout << "Case 4:Insert at Specific Position Update value\n";
    cout << "Case 5:Delete at head\n";
    cout << "Case 6:Delete at Tail\n";
    cout << "Case 7:Delete at Specific Position\n";
    cout << "Case 8:Display the linked list\n";

    cout << "\n\n";
    cout << "Which operation you want to avobe list: ";
    int choice;
    cin >> choice;
    int pos, val;

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> val;
            insertAtHead(head, val);
            display(head);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> val;
            insert_at_Tail(head, val);
            display(head);
            break;
        case 3:
            cout << "Enter the value: ";
            cin >> val;
            cout << "Enter your position: ";
            cin >> pos;
            insert_at_position(head, val, pos);
            display(head);
            break;
        case 4:
            cout << "Enter your value to updated value :";
            cin >> val;
            cout << "Enter which position to update value: ";
            cin >> pos;
            updateAt_position(head, pos, val);
            display(head);
            break;
        case 5:
            deleteAtHead(head);
            display(head);
            break;
        case 6:
            deleteAtTail(head);
            display(head);
            break;
        case 7:
            cout << "Which position want to delete: ";
            cin >> pos;
            deleteAtPosition(head, pos);
            display(head);
            break;
        case 8:
            display(head);
            break;
        }
        cout << "Which operation you want to avobe list: ";
        cin >> choice;
    }
}