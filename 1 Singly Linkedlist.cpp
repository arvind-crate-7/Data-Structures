#include<iostream>
using namespace std;
class node
{
    public:
        int key;
        int data;
        node* next;
        node()
        {
            key=0;
            data=0;
            next=NULL;
        }
        node(int k,int d)
        {
            key=k;
            data=d;
        }
};
class singlylinkedlist
{
    public:
        node* head;
        singlylinkedlist()
        {
            head=NULL;
        }
        singlylinkedlist(node* n)
        {
            head=n;
        }
        //cheacking node Exist or not
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
        //append node in linked list
        void appendNode(node* n)
        {
            if(nodeExist(n->key)!=NULL)
            {
                cout<<"Node Already Exist"<<endl;
            }
            else
            {
                if(head==NULL)
                {
                    head=n;
                    cout<<"Node Appended"<<endl;
                }
                else
                {
                    node* ptr=head;
                    while(ptr->next!=NULL)
                    {
                        ptr=ptr->next;
                    }
                    ptr->next=n;
                    cout<<"Node Appended"<<endl;
                }
            }
        }
        //prepand a node(adding a node at the starting)
        void prepandNode(node*n)
        {
            if(nodeExist(n->key)!=NULL)
            {
                cout<<"Node Already Exist with key value :"<<n->key<<".Append another Node with different Key value"<<endl;
            }
            else
            {
                n->next=head;
                head=n;
                cout<<"Node prepanded"<<endl;
            }
        }
        //insert a node After a particular node
        void insertNode(int k,node* n)
        {
            node* ptr=nodeExist(k);
            if(ptr==NULL)
            {
                cout<<"No Node exist with given key value:"<<k<<endl;
            }
            else
            {
                if(nodeExist(n->key)!=NULL)
                {
                    cout<<"Node Already Exist with key value:"<<n->key<<".Insert Another node with different key value"<<endl;
                }
                else
                {
                    n->next=ptr->next;
                    ptr->next=n;
                    cout<<"Node Inserted."<<endl;
                }
            }
        }
        //Delete Node by Unique key
        void deleteNodebykey(int k)
        {
            if(head==NULL)
            {
                cout<<"Singly linked list Already Empty can't delete"<<endl;
            }
            else if(head!=NULL)
            {
                if(head->key==k)
                {
                    head=head->next;
                    cout<<"Node is Deleted with key value:"<<k<<endl;
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
                    }
                    if(temp!=NULL)
                    {
                        prevptr->next=temp->next;
                        cout<<"Node Deleted with key value:"<<k<<endl;
                    }
                    else
                    {
                        cout<<"Node doesn't exist."<<endl;
                    }
                }
            }
        }
        //update Node
        void updateNodeByKey(int k,int d)
        {
            node* ptr=nodeExist(k);
            if(ptr!=NULL)
            {
                ptr->data=d;
                cout<<"Node data updated successfully"<<endl;
            }
            else
            {
                cout<<"Node doesn't exist with key value"<<k<<endl;
            }
        }
        //printing linked list
        void printlist()
        {
            if(head==NULL)
            {
                cout<<"Singly linked list is Empty.";
            }
            else
            {
                cout<<endl<<"Singly linked list values is:";
                node* temp=head;
                while(temp!=NULL)
                {
                    cout<<"("<<temp->key<<","<<temp->data<<") -->";
                    temp=temp->next;
                }
            }
        }
};
int main()
{
    singlylinkedlist s;
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
                s.appendNode(n1);
                break;

            case 2:
                cout<<"Prepand node operation \nEnter key and data of the Node to be prepanded"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                s.prepandNode(n1);
                break;

            case 3:
                cout<<"Insert Node After operation\nEnter key of existing Node after which to insert this New Node:"<<endl;
                cin>>k1;
                cout<<"Enter key and data of the New Node first:"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                s.insertNode(k1,n1);
                break;

            case 4:
                cout<<"Delete Node by key Operation \nEnter key of the Node to be deleted:"<<endl;
                cin>>k1;
                s.deleteNodebykey(k1);
                break;

            case 5:
                cout<<"Update Node By key Operation \nEnter key and new data to be updated"<<endl;
                cin>>key1;
                cin>>data1;
                s.updateNodeByKey(key1,data1);
                break;

            case 6:
                s.printlist();
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
