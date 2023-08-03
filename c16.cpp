#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void insert(Node *&root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
        return;
    }
    if (root->data > x)
        insert(root->left, x);
    else
        insert(root->right, x);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void search(Node* root,int target)
{
    //basecase 
    if (root == NULL)
    {
        cout<<"The element doesnt exist int the tree"<<endl;
        return;
    }
    if (root->data == target)
    {
        cout<<"The element was found!"<<endl;
    }
    else if (root->data > target)
    {
        search(root->left,target);
    }
    else
    {
        search(root->right,target);
    }
    return;
}



Node* deletion(Node* root,int x)
{
    if (root == NULL)
    {
        cout<<"The element wasnt found"<<endl;
        return root;
    }
    if (root->data == x)
    {
        //if no child
        if (root->right == NULL && root->left == NULL)
        {
            return NULL;
        }
        //if two childern
        else if (root->right!=NULL && root->left != NULL)
        {
            Node* left = root->left;
            Node* right = root->right;
            Node* temp = root->right;
            while (temp!=NULL)
            {
                temp = temp->left;
            }
            temp->left = left;
            delete(root);
            return right;
        }
        //if only one child
        else if (root->left!=NULL)
        {
            Node* temp = root->left;
            delete(root);
            return temp;
        }
        else if(root->right!=NULL)
        {
            Node* temp = root->right;
            delete(root);
            return temp;
        }
    }
    if (root->data > x)
    {
        root->left = deletion(root->left,x);
        return root;
    }
    else
    {
        root->right = deletion(root->right,x);
        return root;
    }
    return root;
}

int findMin(Node* root)
{
    if (root->left == NULL)
        return root->data;
    return findMin(root->left);
}

int findMax(Node* root)
{
    if (root->right == NULL)
        return root->data;
    return findMax(root->right);
}

int main()
{
    vector<int> nodes = {3, 1, 4, 6, 9, 2, 5, 7};
    int n = nodes.size();
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        insert(root, nodes[i]);
    }
    cout<<"-->ADITYA KR PANDEY 21BCI00280<--"<<endl;
    /*inorder(root);
    cout << "(inorder traversal)" << endl;
    preorder(root);
    cout << "(preorder traversal)" << endl;
    postorder(root);
    cout << "(postorder traversal)" << endl;*/

    cout<<"Performing the search operation"<<endl;
    cout<<"Enter the elemet to be searched for : ";
    int target = 0;
    cin>>target;
    search(root,target);

    cout<<"Performing deletion of node"<<endl;
    cout<<"Enter the node to be deleted : ";
    int x = 0;
    cin>>x;
    Node* newTree = NULL;
    newTree = deletion(root,x);

    cout<<"The node was successfully deleted, the inorder traversal of the tree now is ";
    inorder(newTree);
    cout<<endl;
    cout<<"Now the largest element present in the bst is : "<<findMax(newTree);
    cout<<endl;
    cout<<"Where as the smallest element of present in the tree is : "<<findMin(root);
}