#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* link;
}*head=NULL;

class list
{
    node* head;
public:
    list()
    {
        head=NULL;
    }
    void insert(int e);
    void display();
    list merge_arrange(list&,list&);
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
list list::merge_arrange(list &l1,list &l2)
{
    list temp;
    node* t1=new node;
    node* t2=new node;
    t1=l1.head;
    t2=l2.head;
    while(t1!=NULL && t2!=NULL)
    {
        if(t1->data < t2->data)
        {
            temp.insert(t1->data);
            t1=t1->link;
        }
        else if(t1->data > t2->data)
        {
            temp.insert(t2->data);
            t2=t2->link;
        }
        else
        {
            temp.insert(t1->data);
            t2=t2->link;
            t1=t1->link;
        }
    }
    while(t1!=NULL)
    {
        temp.insert(t1->data);
        t1=t1->link;
    }
    while(t2!=NULL)
    {
        temp.insert(t2->data);
        t2=t2->link;
    }
    return temp;
}
int main()
{
    list main,l1,l2;
    int i,n1,n2,e1,e2;
    cout<<"\nEnter the size of list 1";
    cin>>n1;
    cout<<"\nEnter the size of list 2";
    cin>>n2;
    for(i=0;i<n1;i++)
    {
        cout<<"\nEnter the element: ";
        cin>>e1;
        l1.insert(e1);
    }
    for(i=0;i<n2;i++)
    {
        cout<<"\nEnter the element: ";
        cin>>e2;
        l2.insert(e2);
    }
    cout<<"\nthe list 1:";
    l1.display();
    cout<<"\nthe list 2:";
    l2.display();
    main=main.merge_arrange(l1,l2);
    cout<<"\nthe merged array is :";
    main.display();
}
