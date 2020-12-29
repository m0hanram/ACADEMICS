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
    node *head=NULL;
public:
    void insert(int e);
    void display();
    void delete_duplicate();
};
void list::insert(int e)
{
    if(head==NULL)
    {
        node* new_node=new node;
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
void list::delete_duplicate()
{
    node *t=new node;
    node *post=new node;
    t=head;
    post=head->link;
    while(post!=NULL)
    {
        if(t->data==post->data)
        {
            node *temp=new node;
            temp=post;
            t->link=post->link;
            delete temp;
            post=post->link;
        }
        else
        {
            post=post->link;
            t=t->link;
        }
    }
}
int main()
{
    int n,i,e;
    list increasing;
    cout<<"\nEnter the size of list";
    cin>>n;
    cout<<"\nenter the elements of list in increasing order";
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter the element :";
        cin>>e;
        increasing.insert(e);
    }
    cout<<"\nthe list is:";
    increasing.display();
    increasing.delete_duplicate();
    cout<<"\nthe list after deleting duplicates is:";
    increasing.display();
}
