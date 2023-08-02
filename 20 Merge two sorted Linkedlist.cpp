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



Node* solve(Node* first,Node* second){
    //first linkedlist puting all element into first linkedlist
    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    
    Node* curr2 = second;
    Node* next2 = curr2 -> next;
    
    //why next1 checking because we check second element lies in between first current and first next;
    while(next1 != NULL && curr2 != NULL){
        if((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)){
            
            //puting second node into first;
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;
            
            //update pointer
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1 -> next;
            
            //checking if first linkedlist is empty or not
            if(next1 == NULL){
                curr1 -> next = curr2;
                return first;
            }
        }
    }
    return first;
}
Node* sortTwoLists(Node* first, Node* second)
{
    // Write your code here.
    if(first == NULL){
        return second;
    }
    else if(second == NULL){
        return first;
    }
    else if(first -> next == NULL && second -> next == NULL){
        if(first -> data <= second -> data){
            first -> next = second;
            return first;
        }
        else{
            second -> next = first;
            return second;
        }
    }
    
    //checking which linkelist  first value is lowest value
    if(first -> data <= second -> data){
        return solve(first,second);
    }
    else{
        return solve(second,first);
    }
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
    Node* node1=new Node(17);
    Node* head = node1;
    indert_at_starting(head,15);

    indert_at_starting(head,1);
    PrintNode(head);

    Node* node2 = new Node(14);
    Node* head2 = node2;
    indert_at_starting(head2,12);
    indert_at_starting(head2,11);
    indert_at_starting(head2,8);
    indert_at_starting(head2,7);
    cout<<endl;

    PrintNode(head2);

    Node* head3 = sortTwoLists(head,head2);
    PrintNode(head3);
}


