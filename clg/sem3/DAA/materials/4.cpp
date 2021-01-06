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
	return x;
}
Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	y->left = x;
	x->right = T2;
	return y;
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
	return node;
}
int main()
{
	int i,n,key;
	Node *root1 = NULL;
	cout<<"Enter number of nodes for first tree.....";
	cin>>n;
	for(i=0;i<n;i++)
    {
        cout<<"Enter the key for the "<<i+1<<" node....";
        cin>>key;
        root1 = insert(root1,key);
        inOrder(root1);
        cout<<endl;
    }
    Node *root2 = NULL;
	cout<<"Enter "<<n<<" nodes for second tree\n";
	for(i=0;i<n;i++)
    {
        cout<<"Enter the key for the "<<i+1<<" node....";
        cin>>key;
        root2 = insert(root2,key);
        inOrder(root2);
        cout<<endl;
    }
    cout<<"root of first tree:"<<root1->key<<endl;
    cout<<"root of second tree:"<<root2->key<<endl;
    while(root1->key!=root2->key)
    {
        if(root1->key<root2->key)
        {
            root1=leftRotate(root1);
        }
        else
        {
            root2=rightRotate(root2);
        }
    }
    cout<<"After Rotations:-"<<endl;
    cout<<"root of first tree:"<<root1->key<<endl;
    cout<<"root of second tree:"<<root2->key<<endl;
}
