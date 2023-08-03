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
// 25 20 10 5 -1 -1 12 -1 -1 22 -1 -1 36 30 28 -1 -1 -1 40 38 -1 -1 48 -1 -1

Node *buildTree(Node* &root)
{
    int x;
    cin >> x;
    root = new Node(x);
    // like a base case and for leaf node
    if (x == -1)
        return NULL;
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

int leaves(Node *root)
{
    // basecase
    if (root == NULL)
        return 0;
    if (root->right == NULL && root->left == NULL)
        return 1;
    int left = leaves(root->left);
    int right = leaves(root->right);
    return (left + right);
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    int a = height(root->left);
    int b = height(root->right);
    return (max(a, b) + 1);
}

int main()
{
    cout<<"--->ADITYA KR PANDEY 21BCI0280<---"<<endl;
    Node *root;
    buildTree(root);
    cout << "The number of leaves present in the tree : " << leaves(root);
    cout << "\nThe height of the tree is : " << height(root)-1;
}
