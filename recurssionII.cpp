#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/******************************************************************************************************************************************************
//SUBSETS
/*class Solution
{
public:
    void gibSubset(vector<int> &nums, int s, vector<int> temp, vector<vector<int>> &ans)
    {
        int a = nums[s];
        if (s >= nums.size())
        {
            ans.push_back(temp);
            return;
        }

        gibSubset(nums, s + 1, temp, ans); // this is for excludeing
        // we simply increase the element by one ;

        // this will give us theat one empty element and them single element ans the doubles too ;

        // But now we must include the elements in order to get the doubles ans the tripples(all the elements atleast somewhere)

        int element = nums[s];   // we create an element
        temp.push_back(element); // we push it into temp , whose effect will be visible during the recurssion ;

        gibSubset(nums, s + 1, temp, ans);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int s = 0;
        gibSubset(nums, s, temp, ans);
        return ans;
    }
};

******************************************************************************************************************************************************
//SUBSEQUENCES STRING
void solve(string str, string output, int index, vector<string>& ans)
{
    if (index >= str.length())
    {
        if (output.length() > 0)
        {
            ans.push_back(output);

        }
        return;
    }

    // excluding
    solve(str, output, index+1 , ans);

    // including
    char element = str[index];
    output.push_back(element);
    solve(str, output, index + 1, ans);
}

vector<string> subsequences(string str)
{
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}

int main(){
    string str = "hello" ;
    subsequences(str);
    return 0;

******************************************************************************************************************************************************
//Phone keypad

class Solution {
public:
    void solve(string digits,string output,int index,vector<string> ans ,string mapping[])
    {
        //base condition
        if (index>=digits.length()){
            ans.push_back(output);
            return ;
        }

        //geting the digit out of the string in int format
        int x = digits[index] - '0' ;

        //now getting the mapped string values
        string value = mapping[x];

        //ab maaped sring travers karo and usko output me
        //daalo and also recurssion use hoga ab .
        for (int i = 0;i<value.length();i++)
        {
            output.push_back(value[i]);
            solve(digits,output,index+1,ans,mapping);
            //ab return krne pe taki output mebaar baar value[i] naa aaye
            output.pop_back(); //BACKTRACKING!!!!
        }

    }



    vector<string> phone(string digits)
    {
        vector<string> ans ;
        string output = "";
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxys"};
        int index = 0 ;
        solve(digits,output,index,ans,mapping);
        return ans;
    }
};
*********************************************************************************************************************************
//Rat in a maze


class Solution
{
public:
    bool issafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &m)
    {
        if ((x>0 && x < n)  && (y < n && y>0) && visited[x][y] == 0 && m[x][y]==1)
        {
            return true;
        }
        return false;
    }



    void solve(vector<vector<int>> &m, int n, vector<string>& ans, int x , int y, vector<vector<int>> visited ,string output)
    {
        if (x==n-1 && y ==n-1)
        {
            ans.push_back(output);
            return ;
        }
        visited[x][y] = 1 ;
        //DOWN;
        int newx = x+1 ;
        int newy = y ;
        if (issafe(newx,newy,n,visited,m))
        {
            output.push_back('D');
            solve(m,n,ans,newx,newy,visited,output);
            output.pop_back();
        }
        // UP;
        newx = x - 1;
        newy = y;
        if (issafe(newx, newy, n, visited, m))
        {
            output.push_back('U');
            solve(m, n, ans, newx, newy, visited, output);
            output.pop_back();
        }
        // LEFT;
        newx = x;
        newy = y - 1;
        if (issafe(newx, newy, n, visited, m))
        {
            output.push_back('L');
            solve(m, n, ans, newx, newy, visited, output);
            output.pop_back();
        }
        // RIGHT;
        newx = x ;
        newy = y + 1 ;
        if (issafe(newx, newy, n, visited, m))
        {
            output.push_back('R');
            solve(m, n, ans, newx, newy, visited, output);
            output.pop_back();
        }
        visited[x][y] = 0;
    }



    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans ;
        int x = 0;
        int y = 0;
        int destinationx = m.size();
        int destinationy = m[0].size();
        //initialising the vector with zero
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string output = "" ;
        solve(m,n,ans,x,y,visited,output);
        sort(ans.begin() , ans.end());
        return ans;
    }
};

*********************************************************************************************************************************************
//Find median of two sorted arrays!
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> a;
    int s1 = 0;
    int s2 = 0;
    double x;
    int m = nums1.size();
    int n = nums2.size();
    while (s1 < m && s2 < n)
    {
        if (nums1[s1] <= nums2[s2])
        {
            a.push_back(nums1[s1]);
            s1++;
        }
        else
        {
            a.push_back(nums2[s2]);
            s2++;
        }
    }
    while (s1 <= m-1)
    {
        a.push_back(nums1[s1]);
        s1++;
    }
    while (s2 <= n-1)
    {
        a.push_back(nums2[s2]);
        s2++;
    }
    sort(a.begin(), a.end());
    if ((m + n - 1) % 2 != 0)
    {
        x = nums1[(m + n - 1) / 2];
    }
    else
    {
        int m1 = a[(m + n - 1) / 2];
        int m2 = a[(m + n) / 2];
        x = (m1 + m2) / 2;
    }
    return x;
}
int main(){
    vector<int> arr={0,2,4,6,8};
    vector<int> arr2={1,3,5,7};
    int x =findMedianSortedArrays(arr,arr2);
    cout<< x <<" ";
}
************************************************************/


// LEETCODE DAILY PROBLEM ROBOT MADHA

/*
// class Solution {
// public:
//     bool issafe(int x, int y, int n, int m , vector<vector<int>> visited)
//     {
//         if ((x >= 0 && x < n) && (y < m && y >= 0) && (visited[x][y] == 0))
//         {
//             return true;
//         }
//     return false;
//     }

//     void solve(int n,int m, vector<int> &ans, int x, int y, vector<vector<int>> visited, string output)
//     {
//         int count;
//         if (x == n - 1 && y == m - 1)
//         {
//            ans.push_back(count);
//            return;
//         }
//         int newx = x + 1;
//         int newy = y;
//         if (issafe(newx, newy, n, m, visited))
//         {

//             solve(n,m, ans, newx, newy, visited, output);

//         }
//         newx = x;
//         newy = y + 1;
//         if (issafe(newx, newy, n,m, visited))
//         {

//             solve(n, m, ans, newx, newy, visited, output);

//         }
//         visited[x][y] = 0;
//     }

//     void mazak(int n,int m)
//     {
//         vector<int> ans;
//         vector<vector<int>> visited(n, vector<int>(n, 0));
//         string output = "";
//         solve(n, m, ans,0,0, visited, output);
//         int count = ans.size();
//     }

class Solution
{
public
    int uniquePaths(int m, int n)
    {
        return uniquePathsHelper(m - 1, n - 1, new int[n][m]);
    }

private
    int uniquePathsHelper(int m, int n, int[][] memo)
    {
        if (m < 0 || n < 0)
        {
            return 0;
        }
        else if (m == 0 || n == 0)
        {
            return 1;
        }
        else if (memo[n][m] > 0)
        {
            return memo[n][m];
        }
        else
        {
            memo[n][m] = uniquePathsHelper(m - 1, n, memo) + uniquePathsHelper(m, n - 1, memo);
            return memo[n][m];
        }
    }
}
*/
