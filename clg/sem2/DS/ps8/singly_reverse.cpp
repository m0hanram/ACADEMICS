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
    void reverse();
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
void list::reverse()
{
    node* t;
    t=head;
    node* pre=NULL;
    node* next=NULL;
    while(t!=NULL)
    {
        next=t->link;
        t->link=pre;
        pre=t;
        t=next;
    }
    head=pre;
}
int main()
{
    list l;
    int n,i,e;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\nenter the element";
        cin>>e;
        l.insert(e);
    }
    l.reverse();
    l.display();
}
