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

//checking linkedlist is circular or not
bool isCircular(Node* head){
    // Write your code here.
    if(head == NULL){
        return 1;
    }
    map< Node*, bool> visited;
    Node* temp = head;
    while(temp != NULL ){
        if(visited[temp] == 1){
            if(temp == head)
                return 1;
            break;
        }
        visited[temp] = 1;
        temp = temp -> next;
    }
    return 0;
}
              //another method:-
// //cheacking linkedlist is circular or not
// bool circular_or_not(Node* head){
//     //if linkedlist is empty
//     if(head == NULL){
//         return 1;
//     }
    
//     Node* temp =head -> next;
//     while(temp != NULL && temp != head){
//         temp = temp -> next;
//     }

//     if(temp == NULL){
//         return 0;
//     }
//     return 1;
// }
//Inderting node at staring
void indert_at_starting(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
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

    cout<<"is linkedlist is circular or not:"<<circular_or_not(head);
}
