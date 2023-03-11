#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        int key;
        node* next;
        node()
        {
            data=0;
            key=0;
            next=NULL;
        }
        node(int k,int d)
        {
            data=d;
            key=k;
        }
};

class CircularLinkedlist
{
        public:
        node* head;
        CircularLinkedlist()
        {
            head=NULL;
        }
        CircularLinkedlist(node* h)
        {
            head=h;
        }

        //Check if node exist using key value
        node* nodeExist(int k)
        {
            node* temp=NULL;
            node* ptr=head;
            if(ptr==NULL)
            {
                return temp;
            }
            else
            {
                do
                {
                    if(ptr->key==k)
                    {
                        temp=ptr;
                    }
                    else
                    {
                        ptr=ptr->next;
                    }
                }while(ptr!=head);
                return temp;
            }
        }

        //Appending node in Circular linkedlist
        void AppendNode(node* n)
        {
            if (nodeExist(n->key)!=NULL)
            {
                cout<<"Node Already Exist Append another node with different key value;"<<endl;   
            }
            else
            {
                if(head==NULL)
                {
                    head=n;
                    n->next=head;
                    cout<<"Node Appended Sucessfully."<<endl;
                }
                else
                {
                    node* ptr=head;
                    while(ptr->next!=head)
                    {
                        ptr=ptr->next;   
                    }
                    ptr->next=n;
                    n->next=head;
                    cout<<"Node Appended Sucessfully"<<endl;
                }
            }
        }
        
        //Prepanding node at the starting of the linkedlist
        void PrepandNode(node* n)
        {
            if (nodeExist(n->key)!=NULL)
            {
                cout<<"Node Already Exist with key vlaue"<<n->key<<"Prepand another node with different key value."<<endl;
            }
            else
            {
                if(head==NULL)
                {
                    head=n;
                    n->next=head;
                    cout<<"Node prepanded Sucessfully"<<endl;
                }
                else
                {
                    node* ptr=head;
                    while(ptr->next!=head)
                    {
                        ptr=ptr->next;
                    }
                    ptr->next=n;
                    n->next=head;
                    head=n;
                    cout<<"Node Prepanded Sucessfully."<<endl;
                }
            }
        }
        
        //Inserting Node after a particular node in the linkedlist
        void InsertNode(int k,node* n)
        {
            node* ptr=nodeExist(k);
            if (ptr==NULL)
            {
                cout<<"No Node exist with key vlaue"<<k<<endl;
            }
            else
            {
                if(nodeExist(n->key)!=NULL)
                {
                    cout<<"Node Already exist with key value"<<n->key<<"Insert another node with different key value."<<endl;
                }
                else
                {
                    if(ptr->next==head)
                    {
                        n->next=head;
                        ptr->next=n;
                        cout<<"Node Inserted Sucessfully."<<endl;
                    }
                    else
                    {
                        n->next=ptr->next;
                        ptr->next=n;
                        cout<<"Node Inserted Sucessfully."<<endl;
                    }
                    
                }
            }
        }
        
        //Delete Node by unique key
        void DeleteNode(int k)
        {
            node* ptr=nodeExist(k);
            if(ptr==NULL)
            {
                cout<<"node not exist with key value"<<k<<endl;
            }
            else
            {
                if(head==NULL)
                {
                    cout<<"Linkedlist is empty."<<endl;
                }
                else if(ptr==head)
                {
                    if(head->next==NULL)
                    {
                        head=NULL;
                        cout<<"Node is deleted"<<endl;
                    }
                    else
                    {
                        node* ptr=head;
                        while(ptr->next!=head)
                        {
                            ptr=ptr->next;
                        }
                        ptr->next=head->next;
                        head=head->next;
                        cout<<"Node is deleted Sucessfully."<<endl;
                    }
                }
                else
                {
                    node* temp=NULL;
                    node* prevptr=head;
                    node* currentptr=head->next;
                    while(currentptr!=NULL)
                    {
                        if(currentptr->key==k)
                        {
                            temp=currentptr;
                            currentptr=NULL;
                        }
                        else
                        {
                            prevptr=prevptr->next;
                            currentptr=currentptr->next;
                        }
                        prevptr->next=temp->next;
                        cout<<"Node is Deleted Sucessfully."<<endl;
                    }
                }
            }
        }
        
        //Update Node 
        void UpdateNode(int k,int d)
        {
            node* ptr=nodeExist(k);
            if(ptr==NULL)
            {
                cout<<"No Node exist with key value"<<k<<endl;
            }
            else
            {
                ptr->data=d;
                cout<<"Node data updated Sucessfully."<<endl;
            }
        }
        
        //printing linkedlist
        void PrintList()
        {
            if(head==NULL)
            {
                cout<<"Linkedlist is empty."<<endl;
            }
            else
            {
                cout<<endl<<"Linkedlist values is:";
                node* temp=head;
                do
                {
                    cout<<"("<<temp->key<<","<<temp->data<<","<<temp->next<<")-->";
                    temp=temp->next;
                }while(temp!=head);
            }
        }
};



int main()
{
    CircularLinkedlist s;
    int option;
    int key1,data1,k1;
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
                s.AppendNode(n1);
                break;

            case 2:
                cout<<"Prepand node operation \nEnter key and data of the Node to be prepanded"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                s.PrepandNode(n1);
                break;

            case 3:
                cout<<"Insert Node After operation\nEnter key of existing Node after which to insert this New Node:"<<endl;
                cin>>k1;
                cout<<"Enter key and data of the New Node first:"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                s.InsertNode(k1,n1);
                break;

            case 4:
                cout<<"Delete Node by key Operation \nEnter key of the Node to be deleted:"<<endl;
                cin>>k1;
                s.DeleteNode(k1);
                break;

            case 5:
                cout<<"Update Node By key Operation \nEnter key and new data to be updated"<<endl;
                cin>>key1;
                cin>>data1;
                s.UpdateNode(key1,data1);
                break;

            case 6:
                s.PrintList();
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
