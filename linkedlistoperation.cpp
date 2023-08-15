#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node *next;
    Node(int data){
        this->val=data;
        this->next=NULL;
    }
};


void insertAtHead(Node* &head,int val){
    Node *new_node= new Node(val);
    new_node->next=head;
    head= new_node;
}

void insert_at_Tail(Node*&head,int val){
    Node *new_node= new Node(val);
    Node*temp= head;
    while(temp->next!=NULL){
        temp = temp -> next ;
    }
    temp->next=new_node;

}
void updateAt_position(Node *&head,int k,int val){
    int curr_pos=0;
    Node *temp= head;
    while(curr_pos!=k){
        temp=temp->next;
        curr_pos++;
    }

    temp->val=val;
}


void insert_at_position(Node *&head,int val,int pos){

    if(pos==0){
        insertAtHead(head,val);
        return;
    }
    int current_pos=0;
    Node *temp=head;
    Node * new_node= new Node(val);
    while(current_pos!=pos-1){
        temp=temp->next;
        current_pos++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}



void display(Node *& head){
    Node *temp= head;
    while(temp!=NULL){
        cout<< temp -> val <<" ";
        temp = temp-> next ;
    }
    cout<<"NULL"<<endl;
   
}


void deleteAtHead(Node *&head){
    Node *temp= head;
    head=head->next;
    free(temp);
}

void deleteAtTail(Node* &head){
    Node *temp= head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    Node *deleteNode= temp->next;
    temp->next= NULL;
    free(deleteNode);
}

void deleteAtPosition(Node *&head,int pos){
    if(pos==0){
        deleteAtHead(head);
        return;
    }
    int curr_pos=0;
    Node *prev= head;
    while(curr_pos!=pos-1){
        prev=prev->next;
        curr_pos++;
    }
    Node *temp= prev->next;// node to be deleted
    prev->next=prev->next->next;
    free(temp);
}

int main(){
    Node *head= NULL;
    insertAtHead(head,2);
    display(head);
    insertAtHead(head,1);
    display(head);
    insert_at_Tail(head,3);
    display(head);
    insert_at_Tail(head,5);
    display(head);
    insert_at_position(head,4,3);
    display(head);
    updateAt_position(head,2,10);
    display(head);
    deleteAtHead(head);
    display(head);
    deleteAtTail(head);
    display(head);
    deleteAtPosition(head,1);
    display(head);
    
    


}