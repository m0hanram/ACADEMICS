#include <iostream>
using namespace std;
class node{
public:
    int data;
    node *left,*right;
    node(int=0);
};
node::node(int element){
    data=element;
    left=NULL;
    right=NULL;
}
class BST{
public:
    node *root;
    BST();
    void insert(int);
    void delete_smallest_node();
    void search(int);
    int search_max();
    void left_child(int);
    void right_child(int);
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
};
BST::BST(){
    root=NULL;
}
void BST::insert(int element){
    if(!root){
       root=new node(element);
    }
    else{
        node *n=root;
        while(n){
            if(element>n->data){
                if(n->right){
                    n=n->right;
                }
                else{
                    n->right=new node(element);
                    break;
                }
            }
            else{
                if(n->left){
                    n=n->left;
                }
                else{
                    n->left=new node(element);
                    break;
                }
            }
        }
    }
}
void BST::delete_smallest_node(){
    node *n=root;
    int d;
    while(n){
        if(n->left->left){
            n=n->left;
        }
        else{
            break;
        }
    }
    d=n->left->data;
    n->left=NULL;
    cout<<"Smallest element is : "<<d<<endl;
}
void BST::search(int element){
    bool flag=false;
    node *n=root;
    while(n){
        if(element>n->data){
            n=n->right;
        }
        else if(element<n->data){
            n=n->left;
        }
        else{
            flag=true;
            break;
        }
    }
    if(flag)
        cout<<"Element found."<<endl;
    else
        cout<<"Element not found."<<endl;
}
int BST::search_max(){
    node *n=root;
    int d;
    while(n){
        d=n->data;
        n=n->right;
    }
    cout<<"Maximum element in the BST : "<<d<<endl;
    return d;
}
void BST::left_child(int element){
    node *n=root;
    int d;
    bool flag1=false,flag2=false;
    while(n){
        if(element>n->data){
            n=n->right;
        }
        else if(element<n->data){
            n=n->left;
        }
        else{
            flag1=true;
            if(n->left){
                d=n->left->data;
                flag2=true;
            }
            break;
        }
    }
    if(flag1){
        if(flag2)
            cout<<"Left child of "<<element<<" is "<<d<<endl;
        else
            cout<<"Left child of this node does not exist"<<endl;
    }
    else
        cout<<"The given node does not exist"<<endl;
}
void BST::right_child(int element){
    node *n=root;
    int d;
    bool flag1=false,flag2=false;
    while(n){
        if(element>n->data){
            n=n->right;
        }
        else if(element<n->data){
            n=n->left;
        }
        else{
            flag1=true;
            if(n->right){
                d=n->right->data;
                flag2=true;
            }
            break;
        }
    }
    if(flag1){
        if(flag2)
            cout<<"Right child of "<<element<<" is "<<d<<endl;
        else
            cout<<"Right child of this node does not exist"<<endl;
    }
    else
        cout<<"The given node does not exist"<<endl;
}
void BST::inorder(node *root){
    if(root){
        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }
}
void BST::preorder(node *root){
    if(root){
        cout<<root->data<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}
void BST::postorder(node *root){
    if(root){
        preorder(root->left);
        preorder(root->right);
        cout<<root->data<<endl;
    }
}
int main(){
    BST a;
    a.insert(13);
    a.insert(11);
    a.insert(14);
    a.insert(10);
    a.insert(15);
    a.inorder(a.root);
    a.delete_smallest_node();
    a.inorder(a.root);
    a.search(11);
    a.search(20);
    a.search_max();
    a.left_child(13);
    a.left_child(11);
    a.left_child(10);
    a.right_child(13);
    a.right_child(15);
    a.right_child(25);
}
