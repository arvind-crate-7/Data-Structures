#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //consturctor
    Node(int data){
        this -> data =data;
        this -> next = NULL;
    }

};

//floyd's cycle detection algorithm
Node* floyds_algo(Node* head){
    if(head == NULL){
        return NULL;
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
            return slow;
        }
    }
    return NULL;
}







                                           //get starting loop node


Node* get_starting_loop_node(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* interaction = floyds_algo(head);
    Node* slow = head;
    while(slow != interaction){
        slow = slow -> next;
        interaction = interaction -> next;
    }
    return slow;
}



                                            //removing loop in linkedlist

void remove_loop_in_Linkedlist(Node* &head){
    if(head == NULL){
        return ;
    }
    Node* starting_loop_node = get_starting_loop_node(head);
    Node* temp = starting_loop_node;
    while(temp -> next != starting_loop_node){
        starting_loop_node = starting_loop_node -> next;
    }
    starting_loop_node -> next = NULL;
}








void insertation_in_circular_linkedlist_at_end(Node* &head, int d,Node* &tail){
    if(head == NULL){
        head = new Node(d);
        head -> next = head;
        tail = head;
    }
    else{
        Node* temp = new Node(d);
        Node* temp2 = head;
        while(temp2 -> next != head){
            temp2 = temp2 -> next;
        }
        temp2 -> next = temp;
        temp -> next = head;
        tail = temp;
    }

}

//printing circular linkedlist

void print(Node* head){
    Node* temp = head;
    do{
        cout<<head -> data<<" ";
        head = head -> next;
    }
    while(temp  != head);
    cout<<endl;
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
    Node* head = NULL;
    Node* tail = NULL;
    insertation_in_circular_linkedlist_at_end(head,12,tail);
    print(head);
    insertation_in_circular_linkedlist_at_end(head,121,tail);
    print(head);
    insertation_in_circular_linkedlist_at_end(head,11212,tail);
    print(head);

    // it does not give loop present at position node means if loop present at middle of the linkedlist then it give node of the middle not middle or somewhere of loop present in linkedl
    Node* loop_Node = floyds_algo(head);
    cout<<"loop is present at : "<<loop_Node -> data<<endl;

    cout<<"tai node data is: "<<tail->data<<endl;;

    Node* starting_loop_node = get_starting_loop_node(head);
    cout<<"starting loop node data is: "<<starting_loop_node -> data<<endl;
    
    //remove loop
    remove_loop_in_Linkedlist(head);
    print_linkedlist(head);
    Node* starting_loop_node1 = get_starting_loop_node(head);
    cout<<"starting loop node data is: "<<starting_loop_node1 -> data<<endl;
}
