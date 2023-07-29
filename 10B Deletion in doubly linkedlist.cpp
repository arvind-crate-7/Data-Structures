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

    //destructor
    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free for data: "<<val<<endl;
    }

};

//deletion at given position
void delete_by_given_position(Node* &head,int position){
    //deletion at starting
    if(position == 1){
        if(head -> next ==NULL){
            Node* temp =head;
            head=NULL;
            temp->next = NULL;
            delete temp;
            return ;
        }
        Node* temp = head;
        head->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return ;
    }
    else{
        //deletion at middle or last position
        Node* curr=head;
        Node* previous=NULL;
        int cnt=1;
        while(cnt < position){
            previous = curr;
            curr =curr->next;
            cnt++;
        }
        curr->prev =NULL;
        previous -> next =curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

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

    Insert_at_starting(head,12);
    Insert_at_starting(head,112);
    Insert_at_starting(head,111);
    Insert_at_starting(head,1);
    Insert_at_starting(head,13);
    Insert_at_starting(head,11212);
    print(head);

    delete_by_given_position(head,1);
    print(head);
    delete_by_given_position(head,2);
    print(head);
    delete_by_given_position(head,1);
    print(head);
    delete_by_given_position(head,3);
    print(head);
    delete_by_given_position(head,2);
    print(head);
    delete_by_given_position(head,1);
    print(head);
}
