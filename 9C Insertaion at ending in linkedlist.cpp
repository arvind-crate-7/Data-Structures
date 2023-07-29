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
    print_linkedlist(head);
    insert_at_starting(head,12);
    print_linkedlist(head);
    insert_at_starting(head,212);
    print_linkedlist(head);
    
}
