#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    
    //constructor
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};


//insert node at starting
void insert_at_starting(node* &head,int d){
    node* temp=new node(d);
    node* temp2=head;
    while(temp2->next!= NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
    temp->next=NULL;
}

node* merge(node* left , node* right){
    //if left is empty
    if(left == NULL){
        return right;
    }
    //if right is empty
    if(right == NULL){
        return left;
    }

    //creating ans linkedlist
    node* ans = new node(-1);
    node* temp = ans;
    while(left != NULL && right != NULL){
        if(left -> data < right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    //left is not empty
    while(left != NULL){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }

    //right is not empty
    while(right != NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    ans  = ans -> next;
    return ans;


}
node* findmid(node* head){
    node* slow = head;
    node* fast = head -> next;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}
node* mergeSort(node* head) {
    // Write your code here.
    if(head == NULL || head -> next == NULL){
        return head;
    }

    //finding mid element 
    node* mid = findmid(head);

    //asigining left and right
    node* left = head;
    node* right = mid -> next;
    mid -> next = NULL;

    //sorting left and right
    left = mergeSort(left);
    right = mergeSort(right);

    //merging left and right
    node* result = merge(left,right);

    return result;
}

//printing node

void print_linkedlist(node* head){
    node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node* node1=new node(10);
    node* head=node1;
    insert_at_starting(head,12);
    insert_at_starting(head,212);
    
    print_linkedlist(head);

    mergeSort(head);
    print_linkedlist(head);
}
