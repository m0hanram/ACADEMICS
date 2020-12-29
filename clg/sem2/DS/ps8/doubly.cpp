#include<iostream>
using namespace std;
class doubly
{
    public:
    int data;
    doubly* pre;
    doubly* next;
}*head=NULL;

class list
{
    doubly* head;
public:
    list()
    {
        head=NULL;
    }
    void insert(int);
    void display();
};
void list::insert(int e)
{
    doubly* new_node=new doubly;
    new_node->data=e;
    if(head==NULL)
    {
        new_node->next=NULL;
        new_node->pre=NULL;
        head=new_node;
    }
    else
    {
        doubly* t=new doubly;
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=new_node;
        new_node->pre=t;
        new_node->next=NULL;
    }
}
void list::display()
{
    doubly* t=new doubly;
    t=head;
    while(t!=NULL)
    {
        cout<< t->data<<" ";
        t=t->next;
    }
}
int main()
{
    list l;
    int n,e;
    cout<<"/nenter the no. of elements";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nenter the elements:";
        cin>>e;
        l.insert(e);
    }
    cout<<"\nthe list is:";
    l.display();
}
