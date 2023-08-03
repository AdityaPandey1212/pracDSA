#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int x)
    {
        this->data = x;
        this->right = NULL;
        this->left = NULL;
    }
};
void print(vector<int> temp)
{
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}
void levelorder(vector<vector<int>> &store, Node *root)
{
    queue<Node *> queue;
    queue.push(root);
    queue.push(NULL);
    vector<int> temp;
    int count = 0;
    while (!queue.empty())
    {
        Node *front = queue.front();
        queue.pop();
        if (front == NULL)
        {
            store.push_back(temp);
            if (!store.empty())
            {
                queue.push(NULL);
            }
            else
            {
                return;
            }
            temp.clear();
        }
        else
        {
            if (front->left)
                queue.push(front->left);
            if (front->right)
                queue.push(front->right);
        }
    }
}
vector<int> maximumValue(Node *node)
{
    vector<vector<int>> store;
    levelorder(store, node);
    vector<int> ans;
    for (int i = 0; i < store.size(); i++)
    {
        vector<int> a = store[i];
        ans.push_back(*max_element(a.begin(), a.end()));
    }
    return ans;
}
void levelOrder(vector<vector<int>> &level, Node *root)
{
    queue<Node *> queue;
    queue.push(root);
    queue.push(NULL);
    vector<int> temp;
    while (!queue.empty())
    {
        Node *front = queue.front();
        queue.pop();
        if (front == NULL)
        {
            level.push_back(temp);
            temp.clear();
            if (!queue.empty())
                queue.push(NULL);
        }
        else
        {
            temp.push_back(front->data);
            if (front->left)
            {
                queue.push(front->left);
            }
            if (front->right)
            {
                queue.push(front->right);
            }
        }
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<vector<int>> level;
    levelOrder(level, root);
    vector<int> ans;
    for (int i = 0; i < level.size(); i++)
    {
        vector<int> a = level[i];
        ans.push_back(*max_element(a.begin(), a.end()));
    }
    print(ans);
    return 0;
}