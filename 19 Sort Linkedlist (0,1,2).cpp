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
Node* sortList(Node *head){
    // Write your code here.
    int zerocount = 0;
    int onecount = 0;
    int twocount = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == 0){
            zerocount++;
        }
        else if(temp -> data == 1){
            onecount++;
        }
        else if(temp -> data == 2){
            twocount++;
        }
        temp = temp -> next;
    }
    temp = head;
    while(temp != NULL){
        if(zerocount){
            temp -> data = 0;
            --zerocount;
        }
        else if(onecount){
            temp -> data = 1;
            --onecount;
        }
        else if(twocount){
            temp -> data = 2;
            --twocount;
        }
        temp = temp -> next;
    }
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
    Node* node1=new Node(1);
    Node* head = node1;
    indert_at_starting(head,0);

    indert_at_starting(head,2);
    PrintNode(head);

    sortList(head);
    PrintNode(head);
}
