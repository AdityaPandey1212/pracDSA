#include <iostream>
#include <vector>
using namespace std;
/*
class Node
{
    public:
    char data;
    Node* children[26];
    bool isTerminal;
    Node(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class trie{
    public:
    Node* root;
    trie()
    {
        root = new Node('\0');
    }
    void insertUtil(Node* root,string str)
    {
        //basecase
        if (str.length()==0)
        {
            //iska mtlb basically ye hai ki sare elements inserted ahi 
            root->isTerminal = true;
            return;
        }   
        //assumming all words are small letterd
        int index = str[0] - 'a';
        Node* child;
        if (root->children[index]!=NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new Node(str[0]);
            root->children[index] = child;
        }
        //recurssion call
        insertUtil(child,str.substr(1));

    }
    void insert(string word)
    {
        insertUtil(root,word); 
        //calling it since we need recurssion and we only had input as string in this case
    }

    bool searchUtil(Node* root,string x)
    {
        // basecase
        if (x.length() == 0)
        {
            if (root->isTerminal)
                return true;
            return false;
        }
        // assuming all the elments in the string are small letters
        int index = x[0] - 'a';
        Node *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
            return false;
        return searchUtil(child, x.substr(1));
    }

    void searchWord(string searchMe)
    {
        if (searchUtil(root,searchMe))
            cout<<"The word was found in the trie"<<endl;
        else
            cout<<"The word wasnt found in the trie"<<endl;
    }
};

int main()
{
    trie* t = new trie();

    t->insert("qwe");

    t->insert("asd");
    
    t->insert("zxc");

    t->searchWord("qwe");

    t->searchWord("wsx");
}

*/
bool inBound(int a, int b, int m)
{
    if ((a >= 0 && a < m) && (b >= 0 && b < m))
    {
        return true;
    }
    return false;
}
int maxSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int rs = 0;
    int re = 2;
    int cs = 0;
    int ce = 2;
    int ans = INT_MIN;
    while (inBound(rs, re, n))
    {
        while (inBound(cs, ce, m))
        {
            int sum = 0
            for (int i = rs; i <= re; i++)
            {
                for (int j = cs; j < ce; j++)
                {
                    if (i != rs + 1 && (j != cs || j != ce))
                        sum += grid[i][j];
                }
            }
            ans = max(sum, ans);
            cs++;
            ce++;
        }
        rs++;
        re++;
    }
    return ans;
}