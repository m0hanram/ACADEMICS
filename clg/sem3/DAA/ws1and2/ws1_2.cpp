#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int );
};
node::node(int e)
{
    data = e;
    left=right=NULL;
}

class BST
{
public:
    node *root;
    void insert(int );
    void search(int );
    BST()
    {
        root=NULL;
    }
};

void BST::insert(int e)
{
    if(root==NULL)
    {
        root = new node(e);
    }
    else
    {
    node *n=root;
    while(n)
    {
        if(e<n->data)
        {
            if(n->left)
            {
                n=n->left;
            }
            else
            {
                n->left=new node(e);
                break;
            }
        }
        else if(e > n->data)
        {
            if(n->right)
            {
                n=n->right;
            }
            else
            {
                n->right=new node(e);
                break;
            }
        }
        else
        {
            cout<<"element already exist"<<endl;
            break;
        }
    }
    }
}

void BST::search(int e)
{
    bool flag;
    node* n=root;
    int count = 0;
    while(n)
    {
        if(e > n->data)
        {
            n=n->right;
            count++;
        }
        else if(e < n->data)
        {
            n=n->left;
            count++;
        }
        else if(e == n->data)
        {
            flag=true;
            count ++;
            break;
        }
    }
    if(flag)
    {
        cout<<"the element is found"<<endl;
        cout<<"the number of comparisons is "<<count<<endl;
    }
}

int main()
{
    BST b;
    b.insert(1);
    b.insert(2);
    b.insert(3);
    b.insert(4);
    b.insert(5);
    b.insert(6);
    b.insert(7);
    b.insert(8);
    b.insert(9);
    b.insert(10);
    b.search(10);
}
