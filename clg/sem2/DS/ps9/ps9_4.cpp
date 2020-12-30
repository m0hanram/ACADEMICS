#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *link;
}*head=NULL;

class list
{
    public:
    node *head;
    list()
    {
        head=NULL;
    }
    void insert(int);
    void display();
    void shuffle_merge(list &,list &);
};
void list::insert(int e)
{
    if(head==NULL)
    {
        node* new_node=new node;
        if(new_node==NULL)
            cout<<"buffer full";
        new_node->data=e;
        new_node->link=NULL;
        head=new_node;
    }
    else
    {
        node *new_node=new node;
        new_node->data=e;
        node *t=new node;
        t=head;
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=new_node;
        new_node->link=NULL;
    }
}
void list::display()
{
    node *t=new node;
    t=head;
    while(t!=NULL)
    {
        cout<< t->data<<" ";
        t=t->link;
    }
}
void list::shuffle_merge(list &l1,list &l2)
{
    node *temp1=new node;
    temp1=l1.head;
    node *temp2=new node;
    temp2=l2.head;
    while(temp1!=NULL && temp2!=NULL)
    {
        insert(temp1->data);
        insert(temp2->data);
        temp1=temp1->link;
        temp2=temp2->link;
    }
    if(temp1!=NULL)
    {
        while(temp1!=NULL)
        {
            insert(temp1->data);
            temp1=temp1->link;
        }
    }
    if(temp2!=NULL)
    {
        while(temp2!=NULL)
        {
            insert(temp2->data);
            temp2=temp2->link;
        }
    }
}
int main()
{
    int n1,n2,e,i;
    list Main,l1,l2;
    cout<<"\nEnter the size of l1:";
    cin>>n1;
    cout<<"\nEnter the size of l2:";
    cin>>n2;
    cout<<"\the input for list 1";
    for(i=0;i<n1;i++)
    {
        cout<<"\enter the element:";
        cin>>e;
        l1.insert(e);
    }
    cout<<"\nthe input for list 2";
    for(i=0;i<n2;i++)
    {
        cout<<"\enter the element:";
        cin>>e;
        l2.insert(e);
    }
    cout<<"\nthe elements of list 1:";
    l1.display();
    cout<<"\nthe elements of list 2:";
    l2.display();
    Main.shuffle_merge(l1,l2);
    cout<<"\nthe elements of Main list:";
    Main.display();
}

