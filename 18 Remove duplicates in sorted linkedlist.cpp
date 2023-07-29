#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

                                                //removing duplicates in sorted linkedlist

Node* remove_duplicate(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* curr = head;
    while(curr != NULL){
        if((curr -> next != NULL) && (curr -> data == curr -> next -> data)){
            Node* next_next_node = curr -> next -> next;
            Node* next_node_for_deletion = curr -> next;
            delete(next_node_for_deletion);
            curr -> next = next_next_node;
        }
        else{
            curr = curr -> next;
        }
    }
    return head;
}



                                       //another way

Node * uniqueSortedList(Node * head) {
    // Write your code here.
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* curr = head;
    Node* next = head -> next;

    while(next != NULL){
        if(curr -> data == next -> data){
            curr -> next = next -> next;
            next = next -> next;
        }
        else{
            curr = curr -> next;
            next = next -> next;
        }
    }
    return head;
}






//Inseration at given position

void Insert_at_given_position(int position, int d, Node* &head){
    Node* temp=new Node(d);
    if(position == 1){
        temp->next=head;
        head=temp;
        return ;
    }
    Node* temp2=head;
    while(--position){
        temp2=temp2->next;
    }
    temp->next=temp2->next;
    temp2->next=temp;

}

//insert node at starting
void insert_at_starting(Node* &head,int d){
    Node* temp=new Node(d);
    Node* temp2=head;
    while(temp2->next!= NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
    temp->next=NULL;
}

//printing node

void print_linkedlist(Node* head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    insert_at_starting(head,12);
    insert_at_starting(head,12);
    insert_at_starting(head,12);
    insert_at_starting(head,12);
    insert_at_starting(head,212);
    Insert_at_given_position(1,122,head);
    print_linkedlist(head);

    Node* remove_duplicate1 = remove_duplicate(head);
    print_linkedlist(remove_duplicate1);
}
