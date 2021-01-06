#include <iostream>
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
class AVLNode{
public:
    int data;
    AVLNode *left,*right;
    int height;
    AVLNode(int=0);
};
AVLNode::AVLNode(int d){
    data=d;
    left=NULL;
    right=NULL;
    height=1;
}
class AVL{
public:
    AVLNode *root;
    int heightFun(AVLNode*);
    int max(int,int);
    int balanceFactor(AVLNode*);
    AVLNode* RR(AVLNode*);
    AVLNode* LL(AVLNode*);
    AVLNode* LR(AVLNode*);
    AVLNode* RL(AVLNode*);
    AVLNode* insert(AVLNode*,int);
    AVLNode* arrayToAVL(int[],int,int);
    void inorder(AVLNode*);
    AVL();
};
AVL::AVL(){
    root=NULL;
}
int AVL::max(int a,int b){
    return (a>b)?a:b;
}
int AVL::heightFun(AVLNode *node){
    if(node==NULL){
        return 0;
    }
    return node->height;
}
int AVL::balanceFactor(AVLNode *node){
    if(node==NULL){
        return 0;
    }
    return heightFun(node->left)-heightFun(node->right);
}
AVLNode* AVL::LL(AVLNode *A){
    AVLNode *k=A->left;
    A->left=k->right;
    k->right=A;

    A->height=max(heightFun(A->left),heightFun(A->right))+1;
    k->height=max(heightFun(k->left),heightFun(k->right))+1;
    return k;
}
AVLNode* AVL::RR(AVLNode *A){
    AVLNode *k=A->right;
    A->right=k->left;
    k->left=A;

    A->height=max(heightFun(A->left),heightFun(A->right))+1;
    k->height=max(heightFun(k->left),heightFun(k->right))+1;
    return k;
}
AVLNode* AVL::LR(AVLNode *A){
    AVLNode *k;
    A->left=RR(A->left);
    k=LL(A);
    return k;
}
AVLNode* AVL::RL(AVLNode *A){
    AVLNode *k;
    A->right=LL(A->right);
    k=RR(A);
    return k;
}
AVLNode* AVL::insert(AVLNode *node,int d){
    if(node==NULL){
        root=new AVLNode(d);
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
void AVL::inorder(AVLNode *root){
    if(root){
        //cout<<root->data<<endl;
        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }
}
class BST:AVL{
public:
    Node *root;
    void insert(int);
    AVLNode* mergeTrees(Node*,Node*,int,int);
    int* merge(int[],int[],int,int);
    void storeInorder(Node*,int[],int*);
    Node* arrayToBST(int[],int,int);
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

void BST::storeInorder(Node* node,int inorder[],int *index){
    if (node==NULL){
        return;
    }
    storeInorder(node->left,inorder,index);
    inorder[*index]=node->data;
    (*index)++;
    storeInorder(node->right,inorder,index);
}

AVLNode* AVL::arrayToAVL(int arr[],int start,int end){
    AVLNode *root=NULL;
    int i;
    for(i=start;i<=end;i++){
        root=insert(root,arr[i]);
    }
    return root;
}
int* BST::merge(int A[],int B[],int m,int n){
    int *merged=new int[m+n];
    int i=0,j=0,k=0;
    while (i<m && j<n){
        if (A[i]<B[j]){
            merged[k]=A[i];
            i++;
        }
        else{
            merged[k]=B[j];
            j++;
        }
        k++;
    }
    while(i<m){
        merged[k]=A[i];
        i++;
        k++;
    }
    while(j<n){
        merged[k]=B[j];
        j++;
        k++;
    }
    return merged;
}

AVLNode* BST::mergeTrees(Node *r1,Node *r2,int m,int n)
{
    int *A,*B;
    A=new int[m];
    B=new int[n];
    int i=0;
    storeInorder(r1,A,&i);
    int j=0;
    storeInorder(r2,B,&j);
    int *merged=merge(A,B,m,n);
    cout<<"Merged array : ";
    int x;
    for(x=0;x<m+n;x++){
        cout<<merged[x]<<" ";
    }
    cout<<endl<<endl;
    return arrayToAVL(merged,0,m+n-1);
}

void BST::inorder(Node *root){
    if(root){
        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }
}

int main(){
    BST b1,b2;
    AVL c;
    b1.insert(100);
    b1.insert(50);
    b1.insert(300);
    b1.insert(20);
    b1.insert(70);
    b2.insert(80);
    b2.insert(40);
    b2.insert(120);
    BST temp;
    c.root=temp.mergeTrees(b1.root,b2.root,5,3);
    c.inorder(c.root);
    cout<<endl<<endl;
}
