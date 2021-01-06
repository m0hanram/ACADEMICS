#include <iostream>
#include <dos.h>

using namespace std;
class Node{
public:
    int data;
    Node *left,*right;
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
    void insert(int);
    Node* LL(Node*);
    Node* RR(Node*);
    Node* LR(Node*);
    Node* RL(Node*);
    void convert(Node*&,Node*&);
    void inorder(Node*);
    BST();
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
Node* BST::LL(Node *A){
    Node *k=A->left;
    A->left=k->right;
    k->right=A;
    return k;
}
Node* BST::RR(Node *A){
    Node *k=A->right;
    A->right=k->left;
    k->left=A;
    return k;
}
Node* BST::LR(Node *A){
    Node *k;
    A->left=RR(A->left);
    k=LL(A);
    return k;
}
Node* BST::RL(Node *A){
    Node *k;
    A->right=LL(A->right);
    k=RR(A);
    return k;
}
void BST::convert(Node *&a,Node *&b){
    if(a && b){
        while(a->data!=b->data){
            if(a->data<b->data){
                //perform right rotations
                if(a->right && a->right->left && a->right->left->data==b->data){
                    //RL Rotation
                    a=RL(a);
                }
                if(a->right || b->left){
                    //RR Rotation
                    a=RR(a);
                }
            }
            if(a->data>b->data){
                //perform left rotations
                if(a->left && a->left->right && a->left->right->data==b->data){
                    //LR Rotation
                    a=LR(a);
                }
                if(a->right || a->left){
                    //LL rotation
                    a=LL(a);
                }
            }
        }
        convert(a->left,b->left);
        convert(a->right,b->right);
    }
}
int main(){
    BST s,t;
    s.insert(60);
    s.insert(70);
    s.insert(80);
    s.insert(40);
    s.insert(50);
    s.insert(30);
    s.insert(20);

    t.insert(40);
    t.insert(50);
    t.insert(70);
    t.insert(60);
    t.insert(80);
    t.insert(30);
    t.insert(20);

    t.convert(t.root,s.root);
}
