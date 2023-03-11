#include<iostream>
using namespace std;

class node
{
    public:
        int key;
        int data;
        node* next;
        node* previous;
        node()
        {
            key=0;
            data=0;
            next=NULL;
            previous=NULL;
        }
        node(int k,int d)
        {
            key=k;
            data=d;
        }
       
};
class DoublyLinkedlist
{
    public:
        node* head;
        DoublyLinkedlist()
        {
            head=NULL;
        }
        DoublyLinkedlist(node* n)
        {
            head=n;
        }
        //Chicking Node exist or not
        node* nodeExist(int k)
        {
            node* temp=NULL;
            node* ptr=head;
            while(ptr!=NULL)
            {
                if(ptr->key==k)
                {
                    temp=ptr;
                }
                ptr=ptr->next;
            }
            return temp;
        }
        //Append a Node to the list
        void AppendNode(node* n)
        {
            if(nodeExist(n->key)!=NULL)
            {
                cout<<"Node Already Exist with key value"<<n->key<<endl;
            }
            else
            {
                if(head==NULL)
                {
                    head=n;
                    cout<<"Node Appended."<<endl;
                }
                else
                {
                    node* ptr=head;
                    while(ptr->next!=NULL)
                    {
                        ptr=ptr->next;
                    }
                    ptr->next=n;
                    n->previous=ptr;
                    cout<<"Node Appended."<<endl;
                }
            }
        }
        
        //Prepand a Node - Node added at the starting
        void PrepandNode(node* n)
        {
            if(nodeExist(n->key)!=NULL)
            {
                cout<<"Node already Exist with key value"<<n->key<<".Append another node with different Node"<<endl;
            }
            else
            {
                if(head==NULL)
                {
                    head=n;
                    cout<<"Node Prepanded."<<endl;
                }
                else
                {
                    n->next=head;
                    head->previous=n;
                    
                    head=n;
                    cout<<"Node Prepanded."<<endl;
                }
            }
        }
        
        //Insert a Node after a particular node in the list
        void InsertNode(int k,node* n)
        {
            node* ptr=nodeExist(n->key);
            if(ptr==NULL)
            {
                cout<<"No Node exist with key value:"<<k<<endl;
            }
            else
            {
                if(nodeExist(n->key)!=NULL)
                {
                    cout<<"Node Already exist with key value:"<<n->key<<".Insert Another node with different key vlaue"<<endl;
                }
                else
                {
                    node* nextnode=ptr->next;
                    if(nextnode==NULL)
                    {
                        nextnode=n;
                        n->previous=ptr;
                        cout<<"Node Inserted Sucessfully."<<endl;
                    }
                    else
                    {
                        n->next=nextnode;
                        nextnode->previous=n;
                        n->previous=ptr;
                        ptr->next=n;
                        cout<<"Node Inserted Sucessfully."<<endl;
                    }
                }
            }
        }
        //Delete Node by unique key vlaue
        void DeleteNode(int k)
        {
            node* ptr=nodeExist(k);
            if(ptr==NULL)
            {
                cout<<"No node exist with key value"<<k<<".Enter different node for Deleting."<<endl;
            }
            else if(ptr!=NULL)
            {
                if(head->key==k)
                {
                    head=head->next;
                    cout<<"Node is Deleted"<<endl;
                }
                else
                {
                    node* nextNode=ptr->next;
                    node* prevNode=ptr->previous;
                    
                    //Node is at end of the list
                    if(nextNode==NULL)
                    {
                        prevNode=NULL;
                        cout<<"Node is Deleted at the end."<<endl;
                    }
                    
                    //node is at the middle of the list
                    else
                    {
                        prevNode->next=nextNode;
                        nextNode->previous=prevNode;
                        cout<<"Node Deleted at the middle of the list."<<endl;
                    }
                }
            }
        }
        
        
        //Updating Node
        void updateNode(int k,int d)
        {
            node* ptr=nodeExist(k);
            if(ptr!=NULL)
            {
                ptr->data=d;
                cout<<"Node Data updated Sucessfully"<<endl;
            }
            else
            {
                cout<<"Node Doesn't Exist with key value:"<<k<<endl;
            }
        }
        
        //printing
        
        void printList()
        {
            node* temp=head;
            if(head==NULL)
            {
                cout<<"Linkedlist is empty."<<endl;
            }
            else
            {
                cout<<endl<<"Doubly Linkedlist values:";
                while(temp!=NULL)
                {
                    cout<<"("<<temp->key<<","<<temp->data<<")-->";
                    temp=temp->next;
                }
            }
        }
};


int main()
{
    DoublyLinkedlist d;
    int key1,data1,k1;
    int option;
    
    do
    {
        cout<<"\nWhat Operation do you want to performe? Select option Number.Enter 0 to exit."<<endl;
        cout<<"1.appendNode()"<<endl;
        cout<<"2.prepandNode()"<<endl;
        cout<<"3.insertNode()"<<endl;
        cout<<"4.deleteNodeBykey()"<<endl;
        cout<<"5.updateNodeBykey()"<<endl;
        cout<<"6.print()"<<endl;
        cout<<"7.Clear Screen."<<endl;
        cout<<"\nEnter Option:";
        cin>>option;
        node* n1=new node();
        switch(option)
        {
            case 0:
                break;

            case 1:
                cout<<"Append Operation \nEnter key and data of the node to be Appended"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                d.AppendNode(n1);
                break;

            case 2:
                cout<<"Prepand node operation \nEnter key and data of the Node to be prepanded"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                d.PrepandNode(n1);
                break;

            case 3:
                cout<<"Insert Node After operation\nEnter key of existing Node after which to insert this New Node:"<<endl;
                cin>>k1;
                cout<<"Enter key and data of the New Node first:"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                d.InsertNode(k1,n1);
                break;

            case 4:
                cout<<"Delete Node by key Operation \nEnter key of the Node to be deleted:"<<endl;
                cin>>k1;
                d.DeleteNode(k1);
                break;

            case 5:
                cout<<"Update Node By key Operation \nEnter key and new data to be updated"<<endl;
                cin>>key1;
                cin>>data1;
                d.updateNode(key1,data1);
                break;

            case 6:
                d.printList();
                break;

            case 7:
                system("cls");
                break;
            
            default:
                cout<<"Enter proper option number"<<endl;
        }
    } while (option!=0);
    

    return 0;
}
