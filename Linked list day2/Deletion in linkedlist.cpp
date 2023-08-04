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
    //destructor
    ~Node(){
        int value = this->data;
        //free memory
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is release value is:"<<value<<endl;
    }
};



// delete node
void delete_by_position(Node* &head,int position){
    //deleting at staring
    if(position == 1){
        Node* temp = head;
        head=head->next;
        //release memory
        temp->next=NULL;
        delete temp;
    }
    else{
        //deleting in middle and last
        Node* current=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt < position){
            prev=current;
            current=current->next;
            cnt++;
        }
        prev->next=current->next;
        current->next=NULL;
        delete current;
    }
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
    delete_by_position(head,1);
    print_linkedlist(head);
    delete_by_position(head,2);
    print_linkedlist(head);
    delete_by_position(head,2);
    print_linkedlist(head);
    delete_by_position(head,1);
    print_linkedlist(head);
}
