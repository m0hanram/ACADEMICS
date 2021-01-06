#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left,*right;
    Node(int =0);
};
Node::Node(int d){
    data=d;
    left=NULL;
    right=NULL;
}
class BST{
public:
    Node *root;
    int *BT,*in,N;
    BST();
    void getBinaryTree();
    void inorder(int);
    void insert(int);
    int min_num_swap();
    void printArray();
};
BST::BST(){
    root=NULL;
}
void BST::getBinaryTree(){
    cout<<"Enter the no.of elements in the Binary Tree : ";
    cin>>N;
    cout<<endl<<endl<<"Enter the elements of the Binary Tree in array Format."<<endl<<endl;
    cout<<"Note : Left child of node at array position k will be at position 2*k and right child of node at array position k will be at position 2*k+1."<<endl<<endl;
    BT=new int[N];
    in=new int[N];
    int i;
    for(i=0;i<N;i++){
        cin>>BT[i];
    }
}
void BST::inorder(int k){
    static int x=0;
    if(k<=N){
        if(2*k<=N){
            inorder(2*k);
        }
        in[x]=BT[k-1];
        x++;
        if(2*k+1<=N){
            inorder(2*k+1);
        }
    }
}
int BST::min_num_swap(){

    int B[N][2],i;
    bool vis[N];
    for(i=0;i<N;i++){
        vis[i]=false;
        B[i][0]=in[i];
        B[i][1]=i;
    }
    int j,small;
    for(i=0;i<N;i++){
        small=i;
        for(int j=i+1;j<N;j++){
            if(B[j][0]<B[small][0]){
                small=j;
            }
        }
        int temp=B[small][0];
        B[small][0]=B[i][0];
        B[i][0]=temp;
        temp=B[small][1];
        B[small][1]=B[i][1];
        B[i][1]=temp;
    }
    int count=0;
    for(i=0;i<N;i++){
        if(vis[i] || B[i][1]==i){
            continue;
        }
        int cycle_size=0;
        int j=i;
        while(!vis[j]){
            vis[j]=true;
            j=B[j][1];
            cycle_size++;
        }
        if(cycle_size>0){
            count+=(cycle_size-1);
        }
    }
    return count/2;
}
void BST::printArray(){
    int i;
    for(i=0;i<N;i++){
        cout<<in[i]<<endl;
    }
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
int main(){
    BST b;
    b.getBinaryTree();
    b.inorder(1);
   ;
    cout<<endl<<"The minimum number of swaps = "<<b.min_num_swap()<<endl;

}

