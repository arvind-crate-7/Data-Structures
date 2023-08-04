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


                                    //removing duplicates in unsorted linkedlist

Node *removeDuplicates(Node *head)
{
    // Write your code here

    //if linkedlist is empty or linkedlist have only one node
    if(head == NULL && head -> next == NULL){
        return head;
    }


    //else
    Node* curr = head;
    while(curr != NULL){
        Node* prev = curr;
        Node* next = curr -> next;
        while(next != NULL){
            if(next -> data == curr -> data){
                Node* next_for_deletion = next;
                prev -> next = next -> next;
                delete(next_for_deletion);
                next = prev -> next;
            }
            else{
                prev = prev -> next;
                next = next -> next;
            }
        }
        curr = curr -> next;
    }

    return head;

}


                                                        //another way less time complexity tc:- O(n),sp:- O(n)
                                                        //using map
Node *removeDuplicates(Node *head)
{
    // Write your code here
    
    //if linkedlist is empty or only one node
    if(head == NULL && head -> next == NULL){
        return head;
    }
    
    //else
    map<int ,bool> visited;
    Node* prev = head;
    Node* temp = head -> next;
    visited[prev -> data] = 1;
    while(temp != NULL){
        if(visited[temp -> data] == 1){
           Node* duplicate = temp;
           prev -> next = temp -> next;
           delete(duplicate);
           temp = temp -> next;
        }
        else{
            visited[temp -> data] = 1;
            prev = temp;
            temp = temp -> next;
            
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
    insert_at_starting(head,212);
    Insert_at_given_position(1,122,head);
    Insert_at_given_position(3,12,head);
    insert_at_starting(head,122);
    insert_at_starting(head,10);

    cout<<"before removing duplicates in unsorted linkedlist:";
    print_linkedlist(head);

    cout<<endl<<"After removing duplicates in unsorted linkedlist:";
    removeDuplicates(head);
    print_linkedlist(head);
}
