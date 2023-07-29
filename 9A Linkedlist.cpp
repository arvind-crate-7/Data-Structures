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
int main(){
    Node* node1=new Node(10);
    cout<<"data: "<<node1 -> data<<endl;
    cout<<"next: "<<node1 -> next;
    return 0;
}
