#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data){
        this->data=data;
        prev=NULL;
        next=NULL;
    }

};

//Insertation in doubly linkedlist at head

void Insert_at_starting(Node* &head,int d){
    if(head == NULL){
        Node* temp=new Node(d);
        head=temp;
        return ;
    }
    Node* temp = new Node(d);
    temp->prev = NULL;
    head->prev = temp;
    temp->next = head;
    head=temp;
}

//Insertation at tail

void insert_at_tail(Node* &head,int d){
    if(head == NULL){
        Node* temp=new Node(d);
        head=temp;
        return ;
    }
    Node* temp = new Node(d);
    Node* tail=head;
    while(tail->next != NULL){
        tail=tail->next;
    }
    temp->prev = tail;
    tail->next = temp; 
}


//insertation at given position

void Insert_at_position(Node* &head,int position,int d){
    if(head == NULL){
        Node* temp=new Node(d);
        head=temp;
        return ;
    }
    Node* temp = new Node(d);

    //insertation at starting
    if(position == 1){
         Insert_at_starting(head,d);
         return ;
    }

    //insertation at middle ar end of the doubly linkedlist
    Node* pos = head;
    int cnt=1;
    while(cnt < position-1){
        pos=pos->next;
        cnt++;
    }
    
    //Insertation at last
    if(pos->next ==NULL){
        insert_at_tail(head,d);
        return ;
    }

    //insertation at middle
    temp->next=pos->next;
    pos->next->prev = temp;
    temp->prev = pos;
    pos->next = temp;

}

void print(Node* head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    // Node* node1=new Node(10);
    Node* head=NULL;

    Insert_at_position(head,1,222);
    print(head);

    print(head);

    Insert_at_starting(head,12);
    print(head);

    Insert_at_starting(head,112);
    print(head);

    Insert_at_starting(head,122);
    print(head);

    insert_at_tail(head,33);
    print(head);

    insert_at_tail(head,331);
    print(head);

    insert_at_tail(head,3213);
    print(head);

    Insert_at_starting(head,1122);
    print(head);

    //insert at position

    Insert_at_position(head,1,222);
    print(head);
    Insert_at_position(head,3,3223333);
    print(head);
    Insert_at_position(head,5,2222322);
    print(head);
    Insert_at_position(head,1,2212322);
    print(head);
    Insert_at_position(head,13,1000);
    print(head);
}
