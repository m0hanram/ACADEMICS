#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int=0);
};
Node::Node(int d){
    data=d;
    left=NULL;
    right=NULL;
}
class BST{
public:
    Node *root;
    BST();
    void insert(int);
    void print_given_level(Node*,int);
    int height(Node*);
    void traverse_level_order(Node*);
};
BST::BST(){
    root=NULL;
}
void BST::insert(int elt){
    if(!root){
       root=new Node(elt);
    }
    else{
        Node *node=root;
        while(node){
            if(elt>node->data){
                if(node->right){
                    node=node->right;
                }
                else{
                    node->right=new Node(elt);
                    break;
                }
            }
            else{
                if(node->left){
                    node=node->left;
                }
                else{
                    node->left=new Node(elt);
                    break;
                }
            }
        }
    }
}
void BST::print_given_level(Node *root,int level){
    if(!root)
        return;
    if(level==1)
        cout<<root->data<<" ";
    else if(level>1)
    {
        print_given_level(root->left,level-1);
        print_given_level(root->right,level-1);
    }
}
int BST::height(Node *node){
     if(!node)
        return 0;
    else
    {
        int lh=height(node->left);
        int rh=height(node->right);
        if(lh>rh)
            return(lh+1);
        else
            return(rh+1);
    }
}
void BST::traverse_level_order(Node *node){
    int h=height(node);
    int i;
    for(i=1; i<= h;i++)
    {
        cout<<endl;
        print_given_level(node,i);
    }
}
int main(){
    BST b;
    b.insert(4);
    b.insert(2);
    b.insert(3);
    b.insert(1);
    b.insert(5);
    b.traverse_level_order(b.root);
}
