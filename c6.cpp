#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    int x = 0;
    if (nums[0] > target)
        return 0;
    if (nums[n - 1] < target)
        return n;
    else
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] < target && nums[i + 1] > target)
            {
                x = i + 1;
                break;
            }
        }
    }
    return x;
}
int main(){
    vector<int> a ={1,2,4,5};
    int target = 3;
    int x =searchInsert(a,target);
    cout<<x ;
    return 0;
}
***************************************************
*/

/*
bool binarySearch(vector<int> nums, int s, int e, int target)
{
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        mid = s+(e-s)/2 ;
        if (nums[mid] == target)
        {
            return true;
        }
        if (nums[mid] > target)
        {
            e = mid - 1;
        }
        if (nums[mid] < target)
        {
            s = mid + 1;
        }
    }
    return false ;
}
int findpiviot(vector<int> nums)
{
    int s = 0;
    int x = nums[0];
    int e = nums.size() - 1;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] < nums[mid + 1] && nums[mid] < nums[mid - 1])
        {
            return mid;
        }
        if (nums[mid] > x)
        {
            s = mid + 1;
        }
        if (nums[mid] < x)
        {
            e = mid;
        }
    }
    return -2;
}
bool search(vector<int> &nums, int target)
{
    int x = findpiviot(nums);
    if (x == -2)
    {
        // implies the array is sorted
        if (binarySearch(nums, 0, nums.size()-1, target))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (binarySearch(nums, 0, x - 1, target) || binarySearch(nums, x, nums.size() - 1, target))
        {
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> arr = {1,2,3,4,5,5,7};
    bool x = search(arr,5);
    if (x)
    {
        cout<<"Found"<<endl;
        return 0;
    }
    else 
    {
        cout<< "Not found"<<endl;
        
    }
    return 0;
} 
//*********************************

//Sum of two numbers...LEETCODE 1
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};
class Solution
{
    

public:

    // a function to reverse the list
    ListNode *reverse(ListNode *&head)
    {
        ListNode *previous = NULL;
        ListNode *current = head;
        ListNode *forward = NULL;
        while (current != NULL)
        {
            forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;
        }
        return previous;
    }

    void insertattail(ListNode *&head, ListNode *&tail, int val)
    {
        ListNode *temp = new ListNode(val);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }

    // now we may create a fiunction to add it..sahi hai
    ListNode *add(ListNode *first, ListNode *second)
    {
        int carry = 0;
        int sum = 0;
        ListNode *anshead = NULL;
        ListNode *anstail = NULL;
        while (first != NULL && second != NULL)
        {
            sum = carry + first->val + second->val;
            int digit = sum % 10;
            insertattail(anshead, anstail, digit);
            carry = sum / 10;
            first = first->next;
            second = second->next;
        }
        while (first != NULL)
        {
            sum = carry + first->val;
            int digit = sum % 10;
            insertattail(anshead, anstail, digit);
            carry = sum / 10;
            first = first->next;
        }
        while (second != NULL)
        {
            sum = carry + second->val;
            int digit = sum % 10;
            insertattail(anshead, anstail, digit);
            carry = sum / 10;
            second = second->next;
        }
        while (carry != 0)
        {
            sum = carry;
            int digit = sum % 10;
            insertattail(anshead, anstail, digit);
            carry = sum / 10;
        }
        return anshead;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // reverse so its convineant to add simply
        l1 = reverse(l1);
        l2 = reverse(l2);
        // now we may add
        ListNode *ans = add(l1, l2);
        return ans;
    }
};


//MAXIMUM SUBARRAY BRUTE
int main()
{
    vector<int> arr = {-1, 4, 6, -3, 4, -6};
    int maxsum = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum = sum + arr[k];
            }
            maxsum = max(maxsum, sum);
        }
    }
    cout << maxsum << endl;
    return 0;
}


//Celebraty problem

class Solution
{
public:
    bool know(int a, int b, vector<vector<int>> M)
    {
        if (M[a][b] == 1)
            return true;

        return false;
    }
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }
        while (s.size() != 1)
        {
            int a, b;
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();

            if (know(a, b , M))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        int potential = s.top();
        bool row = false;
        bool col = false;

        int zero = 0;
        int ones = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[potential][i] == 0)
                zero++;
            if (M[i][potential] == 1)
                ones++;
        }
        if (ones == n - 1)
        {
            col = true;
        }
        if (zero = true)
        {
            row = true;
        }
        if (row == true && col == true)
        {
            return potential;
        }
        return -1;
    }
};
vector<int> greatestright(vector<int> arr)
{
    stack<int> s;
    s.push(-1);
    int n = arr.size();
    vector<int> x(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int current = arr[i];
        int count = 0;
        while (s.top() != -1 && current > arr[s.top()])
        {
            s.pop();
            count++;
        }
        if (i != n - 1 && count == 0)
        {
            x[i] = s.top();
        }
        else
        {
            x[i] = s.top();
            s.push(i);
        }
    }
    return x;
}
int main()
{
    vector<int> a = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    vector<int> ans = greatestright(a);
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}

int maxArea(vector<int> &height)
{
    int i = 0;
    int area = INT_MIN;

    for (int i = 0; i < height.size(); i++)
    {
        int j = height.size() - 1;

        while (j != i)
        {
            int h = min(height[i], height[j]);
            int b = j - i;

            int temp = h * b;
            area = max(area, temp);
            j--;
        }
    }
    return area;
}

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int max_area = 0;

        while (l < r)
        {
            int lh = height[l];
            int rh = height[r];

            max_area = max(max_area, (r - l) * min(lh, rh));

            if (lh < rh)
                ++l;
            else
                --r;
        }

        return max_area;
    }
};*/


