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
    int *arr;
    int N;
    BST();
    void insert(int);
    void get_array();
    void array_to_tree();
    int height(Node*);
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
void BST::get_array(){
    cout<<"Enter the size of the array : ";
    cin>>N;
    arr=new int[N];
    cout<<endl<<"Enter the elements of the array : "<<endl<<endl;
    int i;
    for(i=0;i<N;i++){
        cin>>arr[i];
    }
}
void BST::array_to_tree(){
    int i;
    for(i=0;i<N;i++){
        insert(arr[i]);
    }
}
int BST::height(Node *node){
     if(!node)
        return 0;
    else
    {
        int lh=height(node->left);
        int rh=height(node->right);
        if (lh>rh)
            return(lh+1);
        else
            return(rh+1);
    }
}
int main(){
    BST b;
    b.get_array();
    b.array_to_tree();
    cout<<"The height of the tree is : "<<b.height(b.root)<<endl;
}

