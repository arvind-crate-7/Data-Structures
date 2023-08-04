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
        int val = this->data;
        if(this -> next != NULL){
            delete next;
            this -> next =NULL;
            cout<<"memory is free node data is: "<<val<<endl;
        }
    }
};

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
    print(tail);
    insertation_after_given_element(tail,12,11);
    print(tail);
    insertation_after_given_element(tail,12,121);
    print(tail);
}
