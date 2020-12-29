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
    node *head=NULL;
public:
    void insert(int);
    void display();
    void alternate_split(list &,list &);
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
void list::alternate_split(list &l1,list &l2)
{
    int c=0;
    node *t=new node;
    t=head;
    while(t!=NULL)
    {
        c++;
        if(c%2!=0)
        {
            l1.insert(t->data);
        }
        else
        {
            l2.insert(t->data);
        }
        t=t->link;
    }
}
int main()
{
    int n,i,e;
    list Main,l1,l2;
    cout<<"\nenter the size of list :";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\nenter the element :";
        cin>>e;
        Main.insert(e);
    }
    cout<<"\nthe elements in main :";
    Main.display();
    Main.alternate_split(l1,l2);
    cout<<"\nthe first list :";
    l1.display();
    cout<<"\nthe second list :";
    l2.display();
}
