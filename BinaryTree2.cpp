#include <iostream>
#include<map>
#include<queue>
#include <vector>
#include<algorithm>
using namespace std;
class Node
{
    public:
    int value;
        Node *left;
        Node *right;
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
Node* insertInRoot(Node* root,int x)
{
    //basecase
    if (root == NULL)
    {
        root = new Node(x);
        return root;
    }
    if (x > root->value)
    {
        root->right = insertInRoot(root->right,x);
    }
    else 
    {
        root->left = insertInRoot(root->left,x);
    }
    return root;
}
void takeInput(Node* &root)
{
    int x;
    cin >> x;
    while (x!=-1)
    {
        root = insertInRoot(root,x);
        cin >> x;
    }
}
void printTree(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node* front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout<<endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout<<front->value<<" ";
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }
}
void inorder(Node* root)
{
    //base case 
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}

void findMin(Node* root)
{
    //basecase 
    if(root)
    
}
//10 8 21 7 27 5 4 3 -1
int main()
{
    Node* root = NULL;
    cout<< "Enter the data to be inserted into the BST"<<endl;
    takeInput(root);
    printTree(root);
    cout<<endl;
    cout<<"Inorder"<<endl;
    inorder(root);
    return 0;
}