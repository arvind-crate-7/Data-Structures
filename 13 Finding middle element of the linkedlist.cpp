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

Node *findMiddle(Node *head) {
    // Write your code here

        //fast slow aproach

    if(head == NULL || head -> next == NULL){
        return head;
    }
    if(head -> next -> next == NULL){
        return head;
    }

    Node* fast = head -> next;
    Node* slow = head;
    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    return slow;



         //Normal approach


    // Node* middle = head;
    // int cnt=0;
    // while(head != NULL){
    //     cnt++;
    //     head = head -> next;
    // }
    // cnt = cnt /2;
    // while(--cnt){
    //     middle = middle -> next;
    // }
    // cnt = cnt*2;
    // if(cnt % 2 == 0){
    //     middle = middle -> next;
    // }
    // return middle;
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
    print_linkedlist(head);

    Node* middle=findMiddle(head);
    cout<<" the middle value is: "<<middle -> data<<endl;
}
