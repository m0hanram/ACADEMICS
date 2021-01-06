#include<iostream>
using namespace std;

class Node
{
	public:
	int key;
	Node *left;
	Node *right;
	int height;
};
int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}
int max(int a, int b)
{
	return (a > b)? a : b;
}
Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}
Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left),height(y->right)) + 1;
	x->height = max(height(x->left),height(x->right)) + 1;

	return x;
}
Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left),height(x->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;

	return y;
}
int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}
void inOrder(Node *root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		cout << root->key << " ";
		inOrder(root->right);
	}
}
Node* insert(Node* node, int key)
{
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	node->height = 1 + max(height(node->left),height(node->right));

	int balance = getBalance(node);

	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}
Node* MinValue(Node* node)
{
    Node *temp=node;
    while(temp!=NULL && temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
        return root;
    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            Node *temp = root->left ?  root->left :  root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            *root = *temp;
            free(temp);
        }
        else
        {
            Node* temp = MinValue(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right,temp->key);
        }
    }
    if (root == NULL)
    return root;

    root->height = 1 + max(height(root->left),height(root->right));
    int balance = getBalance(root);

    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
Node* OnlyLeftChild(Node* root)
{
    Node* current=root;
    if(current == NULL)
    {
        return NULL;
    }
    if(current->left != NULL && current->right == NULL)
    {
        cout<<current->key<<" is the node with only left child\n";
        deleteNode(current,current->key);
        return current;
    }
    current->left=OnlyLeftChild(current->left);
    current->right=OnlyLeftChild(current->right);
    return current;
}
Node* search(Node* root, int key)
{
	if (root == NULL || root->key == key)
	return root;
	if (root->key < key)
	return search(root->right, key);
	return search(root->left, key);
}
void search(Node* root,int a,int b)
{
	if(root != NULL)
	{
		search(root->left,a,b);
		if(root->key>a && root->key<b)
        {
            cout<<root->key<<"\t";
        }
		search(root->right,a,b);
	}
}
int getLeafCount(Node* node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    else
        return getLeafCount(node->left)+getLeafCount(node->right);
}
int main()
{
	Node *root = NULL;
	int i,n,key;
	cout<<"Enter number of nodes.....";
	cin>>n;
	for(i=0;i<n;i++)
    {
        cout<<"Enter the key for the "<<i+1<<" node....";
        cin>>key;
        root = insert(root,key);
        inOrder(root);
        cout<<endl;
    }
	//Delete node with minimum value
	cout<<MinValue(root)->key<<" is the minimum value node";
	deleteNode(root,MinValue(root)->key);
	cout<<endl;
	inOrder(root);
	cout<<endl;
	//delete node with only left child
	OnlyLeftChild(root);
    inOrder(root);
    cout<<endl;
    //delete the root node
    cout<<root->key<<" is the root node"<<endl;
    deleteNode(root,root->key);
    inOrder(root);
	cout<<endl;
	//find a element
	cout<<"Enter the element to be searched.....";
	cin>>key;
    cout<<search(root,key)->key<<endl;
    //height of the tree
    cout<<"height of tree:"<<height(root)<<endl;
    //nodes between a and b
    inOrder(root);
    cout<<"\nEnter values of a and b......";
    int a,b;
    cin>>a>>b;
    search(root,a,b);
    cout<<endl;
    //Count the number of leaves
    cout<<"Number of leaves:"<<getLeafCount(root);
}
