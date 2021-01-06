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
class BST{
public:
    Node *root;
    void insert(int);
    Node* mergeTrees(Node*,Node*,int,int);
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

Node* BST::arrayToBST(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    Node *root=new Node(arr[mid]);
    root->left=arrayToBST(arr,start,mid-1);
    root->right=arrayToBST(arr, mid+1, end);
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

Node* BST::mergeTrees(Node *r1,Node *r2,int m,int n)
{
    int *A,*B;
    A=new int[m];
    B=new int[n];
    int i=0;
    storeInorder(r1,A,&i);
    int j=0;
    storeInorder(r2,B,&j);
    int *merged=merge(A,B,m,n);
    return arrayToBST(merged,0,m+n-1);
}

void BST::inorder(Node *root){
    if(root){
        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }
}

int main(){
    BST b1,b2,c;
    b1.insert(100);
    b1.insert(50);
    b1.insert(300);
    b1.insert(20);
    b1.insert(70);
    b2.insert(80);
    b2.insert(40);
    b2.insert(120);
    c.root=c.mergeTrees(b1.root,b2.root,5,3);
    c.inorder(c.root);
}
