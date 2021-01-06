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
    int noofleafnodes(node *);
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

int BST::noofleafnodes(node *n)
{
    if(n==NULL)
    {
        return 0;
    }
    else if(n->left==NULL && n->right==NULL)
    {
        return 1;
    }
    else
    {
        return noofleafnodes(n->left)+noofleafnodes(n->right);
    }
}

int main(){
    BST b;
    b.insert(4);
    b.insert(2);
    b.insert(3);
    b.insert(1);
    b.insert(5);
    cout<<"Leaf Nodes Count : "<<b.noofleafnodes(b.root);
}


