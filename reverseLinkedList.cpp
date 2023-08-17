#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        this->val=data;
        this->next=NULL;
    }

};

class LinkedList{
    public:
    Node *head;
    LinkedList(){
        head=NULL;
    }
  
    void insertAtTail(int value){
          Node * newNode= new Node(value);
        if(head==NULL){
            head =newNode;
            return;
        }
        Node *temp= head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }

    void display(){
        Node *temp= head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp= temp->next;
        }
        cout<<"NULL"<<endl;
    }

};

Node* reverseLL(Node*  &head){
    Node* prevptr= NULL;
    Node* currPtr=head;
   while(currPtr!=NULL){
    Node* next= currPtr->next;
    currPtr->next=prevptr;
    prevptr=currPtr;
    currPtr=next;
   }

   return prevptr;

}

Node* reverseLLRecursion(Node *&head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node *new_node= reverseLLRecursion(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_node;
}



int main(){

    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.display();
    cout<<endl;

   ll.head= reverseLLRecursion(ll.head);
    
    ll.display();

}