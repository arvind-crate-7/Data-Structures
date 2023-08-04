#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next =NULL;
    }
};

//reverse linkedlist
       
        //iterative aproach
void reverseLinkedList(Node* &head) 
{
    // Write your code here
    Node* curr = head;
    Node* prev = NULL;
    Node* forword = curr;
    while(curr != NULL){
        forword = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forword;  
    }
    head = prev;
}


//Inderting node at staring
void indert_at_starting(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}


//printing node
void PrintNode(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* node1=new Node(10);
    Node* head = node1;
    indert_at_starting(head,12);
    indert_at_starting(head,15);
    PrintNode(head);

    reverseLinkedList(head);
    PrintNode(head);

}
