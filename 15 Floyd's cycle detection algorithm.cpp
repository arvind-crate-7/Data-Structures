  
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

//floyd's cycle detection algorithm
bool floyds_algo(Node* head){
    if(head == NULL){
        return 0;
    }
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
        if(slow == fast){
            return 1;
        }
    }
    return 0;
}

//insertation at ending

void insertation_at_ending(Node* &head,Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next = temp;
    temp->next=NULL;
    tail=temp;
}
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
    Node* tail=node1;
    insertation_at_ending(head,tail,101);
    insertation_at_ending(head,tail,1021);
    print_linkedlist(head);

    cout<<"linkedlist have loop or not:"<<floyds_algo(head)<<endl;

    return 0;
}
