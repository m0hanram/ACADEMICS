#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node* left;
	node* right;
};
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	return(Node);
}
node* Insert(node* node, int data)
{
	if (node == NULL)
        return newNode(data);
	if (data < node->data)
		node->left = Insert(node->left, data);
	else if (data > node->data)
		node->right = Insert(node->right, data);
	return node;
}
int TreeCount(node* root)
{
	if (root == NULL)
		return 0;
	return TreeCount(root->left) + TreeCount(root->right) + 1;
}
void storeInorder(node* node, int inorder[], int *index_ptr)
{
	if (node == NULL)
		return;
	storeInorder(node->left, inorder, index_ptr);
	inorder[*index_ptr] = node->data;
	(*index_ptr)++;
	storeInorder(node->right, inorder, index_ptr);
}
int *merge(int arr1[], int arr2[], int m, int n)
{
	int *mergedArr = new int[m + n];
	int i = 0, j = 0, k = 0;
	while (i < m && j < n)
	{
		if (arr1[i] < arr2[j])
		{
			mergedArr[k] = arr1[i];
			i++;
		}
		else
		{
			mergedArr[k] = arr2[j];
			j++;
		}
		k++;
	}
	while (i < m)
	{
		mergedArr[k] = arr1[i];
		i++; k++;
	}
	while (j < n)
	{
		mergedArr[k] = arr2[j];
		j++; k++;
	}

	return mergedArr;
}
node* sortedArrayToBST(int arr[], int start, int end)
{
	if (start > end)
	return NULL;
	int mid = (start + end)/2;
	node *root = newNode(arr[mid]);
	root->left = sortedArrayToBST(arr, start, mid-1);
	root->right = sortedArrayToBST(arr, mid+1, end);
	return root;
}
node* mergeTrees(node *root1, node *root2, int m, int n)
{
	int *arr1 = new int[m];
	int i = 0;
	storeInorder(root1, arr1, &i);

	int *arr2 = new int[n];
	int j = 0;
	storeInorder(root2, arr2, &j);

	int *mergedArr = merge(arr1, arr2, m, n);

	return sortedArrayToBST (mergedArr, 0, m + n - 1);
}
void inorder(node* node)
{
	if (node == NULL)
		return;
	inorder(node->left);
	cout << node->data << " ";
	inorder(node->right);
}
int main()
{
	int i,n,key;
	node *root1 = NULL;
	cout<<"Enter number of nodes for first tree.....";
	cin>>n;
	for(i=0;i<n;i++)
    {
        cout<<"Enter the key for the "<<i+1<<" node....";
        cin>>key;
        root1 = Insert(root1,key);
        inorder(root1);
        cout<<endl;
    }
    node *root2 = NULL;
	cout<<"Enter number of nodes for second tree.....";
	cin>>n;
	for(i=0;i<n;i++)
    {
        cout<<"Enter the key for the "<<i+1<<" node....";
        cin>>key;
        root2 = Insert(root2,key);
        inorder(root2);
        cout<<endl;
    }
	node *mergedTree = mergeTrees( root1, root2,TreeCount(root1),TreeCount(root2) );

	cout << "Inorder traversal of the merged tree \n";
	inorder(mergedTree);
}
