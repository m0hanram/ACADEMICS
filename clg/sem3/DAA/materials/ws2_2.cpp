#include <iostream>
#include <queue>
#include <stack>
using namespace std;


class Node{
public:
    int data;
    int height;
    Node* leftChild;
    Node* rightChild;
    Node(int);
};

Node:: Node(int value){
    data = value;
    height = 0;
    leftChild = NULL;
    rightChild = NULL;
}

class Tree{

public:
    Node* root;
    Tree() { root = NULL; }
    void insert(Node*&,int);
    void deleteNode(Node*&,int);
    void deleteMin(Node*&);
    void deleteRoot(Node*&);
    void deleteNodeLeftChild(Node*&);
    Node* LLRotation(Node*&);
    Node* RRRotation(Node*&);
    Node* LRRotation(Node*&);
    Node* RLRotation(Node*&);
    int getMinValue(Node*&);
    int getBalanceFactor(Node*& node);
    int getNodeHeight(Node*&);
    int getHeight(Node*&);
    int countLeaf(Node*&);
    void returnKeysBet(Node*&,int,int);
    void traverseInOrder(Node*&);
    vector<int> returnInOrder(Node*&);
    bool findElement(Node*&,int);
};

void Tree:: insert(Node*& node, int value){

    if(node == NULL){
        node = new Node(value);
        node->height = 1;
        return;
    }

    if(node->data == value){
        return;
    }

    else if(value < node->data){
        insert(node->leftChild, value);
    }
    else{
        insert(node->rightChild,value);
    }

    node->height = getNodeHeight(node);

    int balanceFactor = getBalanceFactor(node);

    if(balanceFactor > 1 && value < node->leftChild->data){
        node = LLRotation(node);


        cout << "LL ROTATION -->  ";
        traverseInOrder(root);
        cout << endl;
    }
    if(balanceFactor < -1 && value > node->rightChild->data){
        node = RRRotation(node);


        cout << "RR ROTATION -->  ";
        traverseInOrder(root);
        cout << endl;
    }
    if(balanceFactor > 1 && value > node->leftChild->data){
        node = LRRotation(node);

        cout << "LR ROTATION -->  ";
        traverseInOrder(node);
        cout << endl;
    }
    if(balanceFactor < -1 && value < node->rightChild->data){
        node = RLRotation(node);


        cout << "RL ROTATION -->  ";
        traverseInOrder(node);
        cout << endl;
    }

}

void Tree::deleteMin(Node*& node){
    if(node == NULL){
        return;
    }

    int min = getMinValue(node);
    deleteNode(node,min);
}

void Tree::deleteRoot(Node*& node){
    if(node == root){
        int value = node->data;
        deleteNode(node,value);
    }
}

void Tree::deleteNodeLeftChild(Node*& node){
    queue<Node*> Q;
    Q.push(node);

    while (!Q.empty())
    {
        Node* current = Q.front();
        cout << current->data << " ";
        if(current->leftChild != NULL && current->rightChild == NULL){
            deleteNode(node,current->data);
            return;
        }
        if(current->leftChild != NULL)
            Q.push(current->leftChild);
        if(current->rightChild != NULL)
            Q.push(current->rightChild);
        Q.pop();
    }


}

void Tree::deleteNode(Node*& node,int value){

    if(node == NULL)
        return;
    else{
        if(value < node->data)
            deleteNode(node->leftChild,value);
        else if(value > node->data)
            deleteNode(node->rightChild,value);
        else{
            if(node->leftChild == NULL && node->rightChild == NULL){
                Node* temp = node;
                node = NULL;
                delete temp;
            }
            else if(node->leftChild == NULL && node->rightChild != NULL ){
                Node* temp = node;
                node = node->rightChild;
                delete temp;
            }
            else if(node->leftChild != NULL && node->rightChild == NULL){
                Node* temp = node;
                node = node->leftChild;
                delete temp;
            }
            else{
                //implement delete
                int min = getMinValue(node->rightChild);
                node->data = min;
                deleteNode(node->rightChild,min);
            }
        }
    }

    if(node == NULL) return;

    node->height = getNodeHeight(node);
    int balance = getBalanceFactor(node);

    //perform AVL Rotations
    if(node != NULL && (balance != 1 && balance != -1 && balance != 0)){
        if(node->data < value && (getBalanceFactor(node->leftChild) == 0 || getBalanceFactor(node->leftChild) == 1)){

            node = LLRotation(node);
        }
        if(node->data < value && (getBalanceFactor(node->leftChild) == -1)){

            node = LRRotation(node);
        }
        if(node->data > value && node->rightChild == NULL){

            node = LLRotation(node);
        }
        if(node->data > value && (getBalanceFactor(node->rightChild) == 0 || getBalanceFactor(node->rightChild) == -1)){

            node = RRRotation(node);
        }
        if(node->data < value && getBalanceFactor(node->leftChild) == 1){

            node = RLRotation(node);
        }
    }

}

Node* Tree::LLRotation(Node*& node){
    Node* temp = node->leftChild;
    node->leftChild = temp->rightChild;
    temp->rightChild = node;

    node->height = getNodeHeight(node);
    temp->height = getNodeHeight(temp);

    return temp;

}

Node* Tree::RRRotation(Node*& node){

    Node* temp = node->rightChild;
    node->rightChild = temp->leftChild;
    temp->leftChild = node;

    node->height = getNodeHeight(node);
    temp->height = getNodeHeight(temp);

    return temp;
}

Node* Tree::LRRotation(Node*& node){
    Node* temp = node->leftChild;
    node->leftChild = RRRotation(temp);
    return LLRotation(node);
}

Node* Tree::RLRotation(Node*& node){
    Node* temp = node->rightChild;
    node->rightChild = LLRotation(temp);
    return RRRotation(node);
}

void Tree:: traverseInOrder(Node*& node){
    if(node != NULL){
        traverseInOrder(node->leftChild);
        cout << node->data << " ";
        traverseInOrder(node->rightChild);
    }

}

int Tree::getNodeHeight(Node*& node){
    int left,right;

    left = node && node->leftChild ? node->leftChild->height : 0;
    right = node && node->rightChild ? node->rightChild->height : 0;

    return left > right ? left + 1 : right + 1;
}

int Tree::getBalanceFactor(Node*& node){
    int left,right;

    left = node && node->leftChild ? node->leftChild->height : 0;
    right = node && node->rightChild ? node->rightChild->height : 0;

    return left - right;

}

int Tree::getMinValue(Node*& node){
    if(node != NULL){
        if(node->leftChild == NULL){
            return node->data;
        }
        else
        {
            return getMinValue(node->leftChild);
        }

    }

    return 0;
}

bool Tree::findElement(Node*& node,int value){

    if(node->data == value)
        return true;
    else if(value < node->data){
        return findElement(node->leftChild,value);
    }
    else if(value > node->data)
    {
        return findElement(node->rightChild,value);
    }
        return false;
}

int Tree::getHeight(Node*& node){

    if(node == NULL) return 0;

    else{
        int left = getHeight(node->leftChild);
        int right = getHeight(node->rightChild);

        return left > right ? left + 1 : right + 1;
    }
}

int Tree::countLeaf(Node*& node){
    if(node != NULL){
        if(!node)
            return 0;
        if(node->leftChild == NULL && node->rightChild == NULL){
            return 1;
        }
        return countLeaf(node->leftChild) + countLeaf(node->rightChild);
    }
    else{
        return 0;
    }
}

void Tree::returnKeysBet(Node*& node,int key1,int key2){
    vector<int> vect = returnInOrder(node);
    vector<int> temp;
    for(int i = 0; i < vect.size(); i++){
        if(vect[i] >= key1 && vect[i] <= key2){
            temp.push_back(vect[i]);
        }
    }

    for(int i = 0; i < temp.size(); i++){
        cout << temp[i] << " ";
    }

    cout << endl;
}

vector<int> Tree:: returnInOrder(Node*& node){
    stack<Node*> S;
    vector<int> vect;

    Node* current = node;

    while(current != NULL || S.empty() == false){

        while(current != NULL){
            S.push(current);
            current = current->leftChild;
        }

        current = S.top();
        S.pop();


        vect.push_back(current->data);

        current = current->rightChild;
    }

    return vect;

}


int main(){

    Tree tree;
    tree.insert(tree.root,5);
    tree.insert(tree.root,3);
    tree.insert(tree.root,7);
    tree.insert(tree.root,2);
    tree.insert(tree.root,4);
    tree.insert(tree.root,6);
    //tree.insert(tree.root,7);
    //tree.insert(tree.root,8);
    //tree.insert(tree.root,9);
    //tree.insert(tree.root,10);
    //tree.insert(tree.root,11);

    //tree.traverseInOrder(tree.root);
    cout << endl;

    tree.deleteNodeLeftChild(tree.root);
    cout<<endl;

    tree.traverseInOrder(tree.root);
    cout<<endl;

    tree.deleteMin(tree.root);
    tree.traverseInOrder(tree.root);
    cout<<endl;

    tree.deleteRoot(tree.root);
    tree.traverseInOrder(tree.root);
    cout<<endl;



    tree.findElement(tree.root,6) ? cout << "Found!!" << endl : cout << "Not Found!!" << endl ;

    cout << tree.getHeight(tree.root) << endl;

    cout << tree.countLeaf(tree.root) << endl;

    tree.returnKeysBet(tree.root,3,9);

    return 0;
}
