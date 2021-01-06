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
    BST();
    void insert(int);
    void getInitialValues();
    void checkForNext();
    bool searchFor(int);
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
void BST::getInitialValues(){
    int N;
    cout<<"How many students are there in the class currently : ";
    cin>>N;
    cout<<endl<<endl<<"Enter the no.of candies each of these students have."<<endl<<endl;
    int i,x;
    for(i=0;i<N;i++){
        cin>>x;
        insert(x);
    }
}
bool BST::searchFor(int x){
    Node *node=root;
    while(node){
        if(x<node->data){
            node=node->left;
        }
        else if(x>node->data){
            node=node->right;
        }
        else{
            return true;
        }
    }
    return false;
}
void BST::checkForNext(){
    int M;
    cout<<"How many students are yet to come?"<<endl;
    cin>>M;
    cout<<"Enter the no.of candies each of these students have."<<endl<<endl;
    int i,x;
    for(i=0;i<M;i++){
        cin>>x;
        if(searchFor(x)){
            cout<<"Yes"<<endl<<endl;
        }
        else{
            cout<<"No"<<endl<<endl;
        }
    }
}
int main(){
    BST b;
    b.getInitialValues();
    b.checkForNext();
}
