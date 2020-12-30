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
int main()
{
    list l[4];
    int n0,n1,n2,n3,e,i;
    cout<<"\nenter the no. of elements in 0";
    cin>>n0;
    cout<<"\nenter the no. of elements in 1";
    cin>>n1;
    cout<<"\nenter the no. of elements in 2";
    cin>>n2;
    cout<<"\nenter the no. of elements in 3";
    cin>>n3;
    cout<<"\nenter the elements in 0";
    for(i=0;i<n0;i++)
    {
        cout<<"enter the element:";
        cin>>e;
        l[0].insert(e);
    }
    cout<<"\nenter the elements in 1";
    for(i=0;i<n1;i++)
    {
        cout<<"enter the element:";
        cin>>e;
        l[1].insert(e);
    }
    cout<<"\nenter the elements in 2";
    for(i=0;i<n2;i++)
    {
        cout<<"enter the element:";
        cin>>e;
        l[2].insert(e);
    }
    cout<<"\nenter the elements in 3";
    for(i=0;i<n3;i++)
    {
        cout<<"enter the element:";
        cin>>e;
        l[3].insert(e);
    }
    cout<<"\nthe elements in 0:";
    l[0].display();
    cout<<"\nthe elements in 1:";
    l[1].display();
    cout<<"\nthe elements in 2:";
    l[2].display();
    cout<<"\nthe elements in 3:";
    l[3].display();
}
