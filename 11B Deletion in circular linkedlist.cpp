#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int val = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next =NULL;
            
        }
        cout<<"memory is free node data is: "<<val<<endl;
    }
};

//deletion in circular linkedlist
void deletion_at_given_element(Node* &tail,int val){
    if(tail == NULL){
        cout<<"No element is present for deletion."<<endl;
    }
    else{
        Node* prev = tail;
        Node* curr = prev -> next;
        while(curr -> data != val){
            prev =curr;
            curr = curr -> next;
        }
        //means linked list is only one node
        if(curr == prev){
            tail = NULL;
        }
        else if(tail == curr){
            //deleting last element that's why we need to maintain tail 
            tail = prev;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;

    }
}


//Insertation in circular linkedlist
void insertation_after_given_element(Node* &tail,int insertation_pos_data,int val){
    Node* temp = new Node(val);
    if(tail == NULL){
        tail = temp;
        temp -> next = temp;
    }
    else{
        //asuming element is present in linked list
        Node* curr = tail;
        while (curr -> data != insertation_pos_data){
            curr = curr -> next;
        }
        temp -> next =curr -> next;
        curr -> next = temp;
    }
}

//printing circular linkedlist

void print(Node* tail){
    if(tail == NULL){
        cout<<"linkedlist is empty.";
    }
    Node* temp =tail;
    do{
        cout<<tail -> data<<" ";
        tail = tail -> next;
    }
    while(temp  != tail);
    cout<<endl;
}
int main(){
    Node* tail = NULL;
    insertation_after_given_element(tail,1,12);
    insertation_after_given_element(tail,12,11);
    insertation_after_given_element(tail,12,121);
    print(tail);

    deletion_at_given_element(tail,12);
    print(tail);
    deletion_at_given_element(tail,121);
    print(tail);
    deletion_at_given_element(tail,11);
    print(tail);
}
