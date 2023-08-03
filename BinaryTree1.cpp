//implementation or creation of binary tree
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*class Node
{
    public:

    int value;
    Node* left;
    Node* right;
    Node()
    {

    }
    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int x;
    
    cout<<"Enter the data "<<endl;
    cin>>x;
    root = new Node(x);
    //like a base case and for leaf node 
    if (x == -1)
        return NULL;
    
    //entering left recurssively
    cout<<"Enter the data for the left of "<<x<<endl;
    root->left = buildTree(root->left);

    //entering right part
    cout << "Enter the data for the right of " << x << endl;
    root->right = buildTree(root->right);
    return root;
}
//we are going to add some kind of iteration in between , like here a NULL node
//whenever a NULL node comes we may break the line 
//we are using a queue for this operation


void levelOrderBuild(Node* &root)
{
    queue<Node*> q;
    cout<<"Enter root: ";
    int x;
    cin>>x;
    root = new Node(x);
    q.push(root);
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        cout<<"Enter for left element ";
        int left;
        cin>>left;
        if (left!=-1)
        {
            temp->left = new Node(left);  
            q.push(temp->left);  
        }
        cout<<endl;
        cout<<"Enter right element ";
        int right;
        cin>>right;
        if (right!=-1)
        {
            temp->right = new Node(right);
            q.push(temp->right);
        }
    }
}   


void levelWise_print(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp==NULL)
        {
            cout<<endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->value << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return;
}

void InOrder(Node* root)
{
    //basecase
    if (root==NULL)
    {
        return;
    }

    InOrder(root->left);
    cout<<root->value<<" "; 
    InOrder(root->right);
}

void PreOrder(Node* root)
{
    //basecase is the smae
    if (root == NULL)
    {
        return;
    }
    cout<<root->value<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(Node* root)
{
    //baseCase
    if (root==NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->value<<" ";
}

int height(Node* root)
{
    //basecase
    if (root == NULL)
    {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    return max(l,r)+1;
}
void lefty(Node* root)
{
    // basecase
    if (root->left == NULL)
        return;
    cout<<root->value<<" ";
    lefty(root->left);
}
void leaves(Node*root)
{
    // basecase
    if (root->left == NULL || root->right == NULL)
    {
        cout<<root->value<<" ";
        return;
    }
    leaves(root->left);
    leaves(root->right);
}
void righty(Node* root)
{
    // basecase
    if (root == NULL)
        return;
    righty(root->right);
    cout<<root->value<<" ";
}
int main()
{

    Node* root = NULL;
    root = buildTree(root);

    Node* temp1 = root;
    // Node* temp2 = root;
    // Node* temp3 = root; 
    leaves(temp1);
    // leaves(temp2);
    // righty(temp3->right);
    // 10 5 3 -1 -1 8 7 -1 -1 -1 20 18 -1 -1 25 -1 -1
    //cout<<"printing level wise"<<endl;
    // levelWise_print(root);
    // cout<<"printing inorder"<<endl;
    // InOrder(root);
    // cout<<endl;
    // cout<<"printind preorder"<<endl;
    // PreOrder(root);
    // cout<<endl;
    // cout<<"print postorder"<<endl;
    // PostOrder(root);
    // cout<<endl;
    // levelOrderBuild(root);
    // levelWise_print(root);
    return 0;
}
*/
//the implementation and creation of the binary search tree
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

void search(Node *root, int target)
{
    // basecase
    if (root == NULL)
    {
        cout << "The element doesnt exist int the tree" << endl;
        return;
    }
    if (root->data == target)
    {
        cout << "The element was found!" << endl;
    }
    else if (root->data > target)
    {
        search(root->left, target);
    }
    else
    {
        search(root->right, target);
    }
    return;
}

Node *deletion(Node *root, int x)
{
    if (root == NULL)
    {
        cout << "The element wasnt found" << endl;
        return root;
    }
    if (root->data == x)
    {
        // if no child
        if (root->right == NULL && root->left == NULL)
        {
            return NULL;
        }
        // if two childern
        else if (root->right != NULL && root->left != NULL)
        {
            Node *left = root->left;
            Node *right = root->right;
            Node *temp = root->right;
            while (temp != NULL)
            {
                temp = temp->left;
            }
            temp->left = left;
            delete (root);
            return right;
        }
        // if only one child
        else if (root->left != NULL)
        {
            Node *temp = root->left;
            delete (root);
            return temp;
        }
        else if (root->right != NULL)
        {
            Node *temp = root->right;
            delete (root);
            return temp;
        }
    }
    if (root->data > x)
    {
        root->left = deletion(root->left, x);
        return root;
    }
    else
    {
        root->right = deletion(root->right, x);
        return root;
    }
    return root;
}

int findMin(Node *root)
{
    if (root->left == NULL)
        return root->data;
    return findMin(root->left);
}

int findMax(Node *root)
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
    cout << "-->ADITYA KR PANDEY 21BCI00280<--" << endl;
    // inorder(root);
    // cout << "(inorder traversal)" << endl;
    // preorder(root);
    // cout << "(preorder traversal)" << endl;
    // postorder(root);
    // cout << "(postorder traversal)" << endl;

    cout << "Performing the search operation" << endl;
    cout << "Enter the elemet to be searched for : ";
    int target = 0;
    cin >> target;
    search(root, target);

    cout << "Performing deletion of node" << endl;
    cout << "Enter the node to be deleted : ";
    int x = 0;
    cin >> x;
    Node *newTree = NULL;
    newTree = deletion(root, x);

    cout << "The node was successfully deleted, the inorder traversal of the tree now is ";
    inorder(newTree);
    cout << endl;
    cout << "Now the largest element present in the bst is : " << findMax(newTree);
    cout << endl;
    cout << "Where as the smallest element of present in the tree is : " << findMin(root);
}