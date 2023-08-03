#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<int> ans = {10,10,8,7,5,5,7,2,9,9,8,0,9,9,2,4};
    // int left = 0;
    // for (int right=0; right<ans.size();right++)
    // {
    //     if (ans[right] != ans[left])
    //     {
    //         left++;
    //     }
    //     ans[left] = ans[right];
    // }
    map<int,bool> m;
    vector<int> returnme;
    for (int i = 0;i<ans.size();i++)
    {
        if (m[ans[i]] == true)
        {
            continue;
        }
        returnme.push_back(ans[i]);
        m[ans[i]] = true;
    }

    for (int i =0;i<returnme.size();i++)
    {
        cout<<returnme[i]<<" ";
    }
}
/*int canCompleteCircui
t(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int fuel = 0;
        if (gas[i] >= cost[i])
        {
            bool doneOnce = false;
            int a = n;
            for (int j = i; j < a;j++)
            {
                fuel = fuel + gas[j];
                fuel = fuel - cost[j];
                count++;
                if (fuel < 0)
                    break;
                // now ending to return i;
                if (doneOnce && j == i - 1)
                {
                    fuel = fuel + gas[j];
                    fuel = fuel - cost[j];
                    if (fuel >= 0)
                    {

                    }
                }

                if (j == n - 1)
                {
                    doneOnce = true;
                    j = 0;
                    a = i;
                }
            }
        }
    }
    return -1;
}


vector<int> asteroidCollision(vector<int> &ast)
{
    int n = ast.size();
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (ast[i] > 0 || s.empty())
        {
            s.push(ast[i]);
        }
        else
        {
            while (!s.empty() and s.top() > 0 and s.top() < abs(ast[i]))
            {
                s.pop();
            }
            if (!s.empty() and s.top() == abs(ast[i]))
            {
                s.pop();
            }
            else
            {
                if (s.empty() || s.top() < 0)
                {
                    s.push(ast[i]);
                }
            }
        }
    }
    vector<int> res(s.size());
    for (int i = (int)s.size() - 1; i >= 0; i--)
    {
        res[i] = s.top();
        s.pop();
    }
    return res;
}

int main()
{
    vector<int> arr = {2, 3, 5, -7};
    vector<int> a = asteroidCollision(arr);
    for (int i = 0;i<a.size();i++)
    {
        cout << a[i] << " ";
    
    }
}
*/


