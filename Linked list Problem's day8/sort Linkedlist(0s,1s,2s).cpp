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
//Inderting node at staring
void indert_at_starting(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void insert_at_tail(Node* &tail, Node* curr){
    tail -> next = curr;
    tail = curr;
}
                                       //sorting 0s,1s,2s in three different linkedlist
Node* sortList(Node *head){
    // Write your code here.
    
    //dummy node
    Node* zerohead = new Node(-1);
    Node* onehead = new Node(-1);
    Node* twohead = new Node(-1);
    
    Node* zerotail = zerohead;
    Node* onetail = onehead;
    Node* twotail = twohead;
    
    Node* temp = head;
    
    //creating three linkedlist 
    
    while(temp != NULL){
        int val = temp -> data;
        if(val == 0){
            insert_at_tail(zerotail,temp);
        }
        else if(val ==1){
            insert_at_tail(onetail,temp);
        }
        else if(val == 2){
            insert_at_tail(twotail,temp);
        }
        temp = temp -> next;
    }

    //merging three linkedlist
    
    //is 1s in linkedlist is 0;
    if(onehead -> next != NULL){
        zerotail -> next = onehead -> next;
    }
    else{
        zerotail -> next = twohead -> next;
    }
    
    onetail -> next = twohead -> next;
    twotail -> next = NULL;
    
    head = zerohead -> next;
    delete zerohead;
    delete onehead;
    delete twohead;
    
    
    return head;
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
    PrintNode(head);
    indert_at_starting(head,12);
    PrintNode(head);

    indert_at_starting(head,15);
    PrintNode(head);
}
