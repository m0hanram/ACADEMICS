#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    int height;
    Node(int=0);
};
Node::Node(int d){
    data=d;
    left=NULL;
    right=NULL;
    height=1;
}
class AVL{
public:
    Node *root;
    int heightFun(Node*);
    int max(int,int);
    int balanceFactor(Node*);
    Node* RR(Node*);
    Node* LL(Node*);
    Node* LR(Node*);
    Node* RL(Node*);
    Node* insert(Node*,int);
    void inorder(Node*);
    AVL();
};
AVL::AVL(){
    root=NULL;
}
int AVL::max(int a,int b){
    return (a>b)?a:b;
}
int AVL::heightFun(Node *node){
    if(node==NULL){
        return 0;
    }
    return node->height;
}
int AVL::balanceFactor(Node *node){
    if(node==NULL){
        return 0;
    }
    return heightFun(node->left)-heightFun(node->right);
}
Node* AVL::LL(Node *A){
    Node *k=A->left;
    A->left=k->right;
    k->right=A;

    A->height=max(heightFun(A->left),heightFun(A->right))+1;
    k->height=max(heightFun(k->left),heightFun(k->right))+1;
    return k;
}
Node* AVL::RR(Node *A){
    Node *k=A->right;
    A->right=k->left;
    k->left=A;

    A->height=max(heightFun(A->left),heightFun(A->right))+1;
    k->height=max(heightFun(k->left),heightFun(k->right))+1;
    return k;
}
Node* AVL::LR(Node *A){
    Node *k;
    A->left=RR(A->left);
    k=LL(A);
    return k;
}
Node* AVL::RL(Node *A){
    Node *k;
    A->right=LL(A->right);
    k=RR(A);
    return k;
}
Node* AVL::insert(Node *node,int d){
    if(node==NULL){
        root=new Node(d);
        return root;
    }
    if(d<node->data){
        node->left=insert(node->left,d);
    }
    else if(d>node->data){
        node->right=insert(node->right,d);
    }
    else{
        return node;
    }
    node->height=1+max(heightFun(node->left),heightFun(node->right));
    int bf=balanceFactor(node);

    if(bf>1 && d<node->left->data){
        return LL(node);
    }
    if(bf<-1 && d>node->right->data){
        return RR(node);
    }
    if(bf>1 && d>node->left->data){
        return LR(node);
    }
    if(bf<-1 && d<node->right->data){
        return RL(node);
    }
    return node;
}
void AVL::inorder(Node *root){
    if(root){
        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }
}
int main(){
    AVL tree;
    tree.root=tree.insert(tree.root,1);
    tree.root=tree.insert(tree.root,2);
    tree.root=tree.insert(tree.root,18);
    tree.root=tree.insert(tree.root,3);
    tree.root=tree.insert(tree.root,17);
    tree.root=tree.insert(tree.root,8);
    tree.root=tree.insert(tree.root,10);
    tree.root=tree.insert(tree.root,12);
    tree.root=tree.insert(tree.root,14);

    tree.inorder(tree.root);
}
