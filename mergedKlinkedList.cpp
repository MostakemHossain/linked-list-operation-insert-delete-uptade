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

Node * margeLinkedList(Node *head1,Node *head2){
    Node *dummyNode= new Node(-1);

    Node* ptr1=head1;
    Node* ptr2=head2;
    Node* ptr3=dummyNode;

    while(ptr1 && ptr2){
        if(ptr1->val<ptr2->val){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;

        }
        ptr3=ptr3->next;
    }

    if(ptr1){
        ptr3->next=ptr1;
    }else{
         ptr3->next=ptr2;
    }

    return dummyNode->next;

}


Node *mergeKLinkedList(vector<Node*>&lists){

    if(lists.empty()){
        return NULL;    
    }

    while(lists.size()>1){
        Node *mergedList= margeLinkedList(lists[0],lists[1]);
        lists.push_back(mergedList);
        lists.erase(lists.begin());
        lists.erase(lists.begin());

    }

    return lists[0];

}

int main(){

    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(7);
    ll1.insertAtTail(8);
    ll1.display();

    LinkedList ll2;
    ll2.insertAtTail(2);
    ll2.insertAtTail(4);
    ll2.insertAtTail(5);
    ll2.display();

    LinkedList ll3;
   ll3.insertAtTail(3);
   ll3.insertAtTail(6);
    ll3.display();

    vector<Node*> lists;
    lists.push_back(ll1.head);
    lists.push_back(ll2.head);
    lists.push_back(ll3.head);
    LinkedList ll4;
    ll4.head = mergeKLinkedList(lists);
    ll4.display();


    
    

    

    



}