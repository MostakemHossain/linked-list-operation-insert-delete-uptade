Node* reverseLLRecursion(Node *&head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node *new_node= reverseLLRecursion(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_node;
}