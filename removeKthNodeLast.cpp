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

void removeKthNodeFromTheEnd(Node * &head,int k){

    Node* ptr1=head;
    Node* ptr2=head;

    int count=k;
    while(count--){
        ptr2=ptr2->next;
    }

    if(ptr2==NULL){
        Node *temp= head;
        head=head->next;
        free(temp);
        return;
    }

    while(ptr2->next!=NULL){
        ptr2=ptr2->next;
        ptr1=ptr1->next;
    }

    Node *temp= ptr1->next;
    ptr1->next=ptr1->next->next;
    free(temp);
}



int main(){

    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.insertAtTail(6);
    ll1.display();

    removeKthNodeFromTheEnd(ll1.head,6);
    ll1.display();

    

    



}