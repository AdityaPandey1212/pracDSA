#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*void insertsorted (stack<int> &s, int x)
{
    //base case
    if (s.empty() || s.top() <= x)
    {
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();
    insertsorted(s,x);
    s.push(num);
}
int main()
{
    stack <int> s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(5);
    s.push(6);
    s.push(7);
    int x = 4;
    insertsorted(s,x);

    int a = s.size();
    for (int i= 0 ;i<a ;i++)
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}



//MINIMUM COST FOR VALID PARENTHESIS
int findMinimumCost(string str)
{
    // Write your code here
    if (str.length() % 2 != 0)
        return -1;
    // every closed should have open before it
    stack<char> stack;
    for (int i = 0; i < str.length(); i++)
    {
        if (stack.empty())
        {
            stack.push(str[i]);
        }
        if (str[i] == '}' && stack.top() == '{')
        {
            stack.pop();
        }
        else
        {
            stack.push(str[i]);
        }
    }
    if (stack.size() == 0)
    {
        return 0;
    }
    int closed = 0;
    int open = 0;
    int size = stack.size();
    for (int i = 0; i < size; i++)
    {
        if (stack.top() == '{')
        {
            open++;
            stack.pop();
        }
            
        else
        {
            closed++;
            stack.pop();
        }
    }
    cout<<open<<endl;
    cout<<closed<<endl;
    // if (open == closed)
    // {
    //     return open;
    // }
    // if (open == 0)
    // {
    //     return (closed / 2);
    // }
    // if (closed == 0)
    // {
    //     return (open / 2);
    // }
    // else
    // {
    //     if (open > closed)
    //     {
    //         return open - closed;
    //     }
    //     else
    //     {
    //         return closed - open;
    //     }
    // }
    return 0;
}*/

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (j==n-1)
            {
                if (arr[j]>arr[i]){
                    ans.push_back(-1);
                    break;
                }
                else if (arr[j] < arr[i])
                {
                    ans.push_back(arr[arr.size()-1]);
                    break;
                }
            }
            else if (arr[j] < arr[i])
            {
                ans.push_back(arr[j]);
                break;
            }
        }
    }
    ans.push_back(-1);
    cout<<"Sisze of the array"<<ans.size()<<endl;
    return ans;
}

int main()
{
    vector<int> a = {6,1,3,4,2,6,1};
    vector<int> ans = nextSmallerElement(a , 6);
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" " ; 
    }
}