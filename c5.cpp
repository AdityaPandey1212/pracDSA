#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*int search(vector<int> &arr, int target)
{
    int s = 0;
    int e = arr.size() - 1;
    int piviotindex;
    int f = arr[0];
    if (target == arr[0])
    {
        return 0;
    }
    while (s <= e)
    {

        int mid = (e + s) / 2;
        if (s == e)
        {
            piviotindex = s; // why without break ans not cumming
            break;
        }
        else if (arr[mid] > f)
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    int s1 = 0, s2 = piviotindex, e1 = piviotindex - 1, e2 = arr.size() - 1;
    int mid = 0;
    if (target < arr[0])
    {
        int search(vector<int> & arr, int target)
        {
            int s = 0;
            int e = arr.size() - 1;
            int piviotindex;
            int f = arr[0];
            if (target == f)
            {
                return 0;
            }
            if (e == 1)
            {
                if (arr[0] == target)
                    return 0;
                else if (arr[1] == target)
                    return 1;
                else
                    return -1;
            }
            if (arr[e] > arr[s])
            {
                s = 0;
                e = arr.size() - 1;
                while (s <= e)
                {
                    int mid = s + e / 2;
                    if (arr[mid] == target)
                    {
                        return mid;
                    }
                    else if (arr[mid] > target)
                    {
                        e = mid - 1;
                    }
                    else
                    {
                        s = mid + 1;
                    }
                }
            }
            while (s <= e)
            {

                int mid = (e + s) / 2;
                if (s == e)
                {
                    piviotindex = s; // why without break ans not cumming
                    break;
                }
                else if (arr[mid] > f)
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid;
                }
            }
            int s1 = 0, s2 = piviotindex, e1 = piviotindex - 1, e2 = arr.size() - 1;
            int mid = 0;
            if (target < f)
            {
                while (s2 <= e2)
                {
                    mid = s2 + (e2 - s2) / 2;
                    if (arr[mid] == target)
                    {
                        return mid;
                    }
                    if (arr[mid] > target)
                    {
                        e2 = mid - 1;
                    }
                    if (arr[mid] < target)
                    {
                        s2 = mid + 1;
                    }
                }
                return -1;
            }
            else if (target > f)
            {
                while (s1 <= e1)
                {
                    mid = s1 + (e1 - s1) / 2;
                    if (arr[mid] == target)
                    {
                        return mid;
                    }
                    if (arr[mid] > target)
                    {
                        e1 = mid - 1;
                    }
                    if (arr[mid] < target)
                    {
                        s1 = mid + 1;
                    }
                }
                return -1;
            }
            return 0;
        }
}

int main()
{
    vector<int> a = {3,4,5,1,2};
    int x = search(a,4);
    cout<<x ;
    return 0;
}*/
/*
int makeBeautiful(string str)
{
    int x = 0;
    int y = 0;
    int i = 0;
    while (i < str.length())
    {
        if (i % 2 == 0)
        {
            if (str[i] != '0')
            {
                x++;
            }
            else
            {
                y++;
            }
        }
        if (i % 2 == 1)
        {
            if (str[i] != '0')
            {
                y++;
            }
            else
            {
                x++;
            }
        }
        i++;
    }
    return x <= y ? x : y;
}*/

/*vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> temp;
    int a = -1, b = -1, c = -1;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++)
    {
        if (nums[i] > 0)
            break;
        if (nums[i] == nums[i - 1])
            continue;
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0)
            {
                ++left;
            }
            else if (sum > 0)
            {
                --right;
            }
            else
            {
                ans.push_back({nums[i], nums[left], nums[right]});
                left = i+1;
                right = n-1;
                break;
                // int last_left = nums[left], last_right = nums[right];
                // while (left < right && nums[left] == last_left)
                //     ++left;
                // while (left < right && nums[right] == last_right)
                //     --right;
            }
        }
    }
    return ans;
}
int main(){
    vector<int> a = { -1,-1,-2,0,1,1,2};
    vector<vector<int>> ans = threeSum(a);
    for (int i=0 ; i<ans.size() ; i++)
    {
        for (int j=0 ; j<3 ; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout<<endl;
    }

    return 0 ;
}
int countRepeatingDigits(int N)
{
    int res = 0;
    int cnt[10] = {0};
    while (N > 0)
    {
        int rem = N % 10;
        cnt[rem]++;
        N = N / 10;
    }
    for (int i = 0; i < 10; i++)
    {

        if (cnt[i] > 1)
        {
            res++;
        }
    }
    return res;
}

void countSpecialNumbers(int n)
{
    vector<int> check;
    int count = 10;
    if (n <= 10)
    {
        cout <<n ;
    }
    else
    {
        for (int i = 11; i <= n; i++)
        {
            if (countRepeatingDigits(i) != 0)
            {
                count++;
            }
        }
    }
    cout<< count ;
}
int main(){
    int n = 20;
    countSpecialNumbers(11);
}


void setZeroes(vector<vector<int>> &matrix)
{
    vector<int> x;
    vector<int> y;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                x.push_back(i);
                y.push_back(j);
                cout<<i<<" "<<j;
            }
        }
    }
    int i = 0;
    while (i > x.size())
    {
        for (int col = 0; col < matrix.size(); col++)
        {
            matrix[x[i]][col] = 0;
        }
        for (int row = 0; i < matrix.size(); row++)
        {
            matrix[row][y[i]] = 0;
        }
        i++;
    }
}*/
//where did alll the backtracking go bruh? you shit 
//couldve  revised everything in the last few days 

bool isValidSudoku(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '.')
                continue;
            else
            {
                int count = 0;
                int search = matrix[i][j];
                int s = 0;
                while (s < n)
                {
                    if (matrix[i][s] == '.' || matrix[s][j] == '.')
                        continue;
                    else if (matrix[i][s] == search || matrix[s][j] == search)
                    {
                        count++;
                    }
                }
                if (count > 2)
                    return false;
            }
        }
    }
    return true;
}
