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

Node *findMiddleElement(Node *&head){

    Node *slow=head;
    Node *fast= head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;

}




int main(){

    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(7);
    ll1.insertAtTail(8);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(9);
    ll1.display();

    Node *middleElement= findMiddleElement(ll1.head);
    cout<<middleElement->val<<endl;
   


    
    

    

    



}