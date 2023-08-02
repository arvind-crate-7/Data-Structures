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

Node* middle_node(Node* head){
    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}
Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
class Solution {

public:
    bool isPalindrome(Node* head) {

        if(head -> next == NULL){
            return 1;
        }
        //finding middle element;
        Node* middle = middle_node(head);
        
        //revese after middle element 
        Node* temp = middle -> next;
        middle -> next = reverse(temp);

            Node* head1 = head;
            Node* head2 = middle -> next;

        while(head2 != NULL){
            if(head1 -> data != head2 -> data){
                return 0;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }

        //again making linkedlist as like it is in starting
        temp = middle -> next;
        middle -> next = reverse(temp);

        return 1;


        
    }
};


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
    indert_at_starting(head,2);

    indert_at_starting(head,1);
    PrintNode(head);

    Solution ispalidrome;
    bool ans =ispalidrome.isPalindrome(head);
    cout<<ans;
}


