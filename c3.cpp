#include <iostream>
#include <vector>

using namespace std;

*********************************************************************************************************************************
/*bool findelement(int arr[][3], int f)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == f)
            {
                return 1;
            }
        }
    }
    return 0;
}
void sumoftherows(int arr[3][3])
{
    int i = 0;
    int ans[3];
    while (i < 3)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum = arr[i][j] + sum;
            ans[j] = sum;
        }

        i++;
    }
    int x, y;
    for (int i = 0; i < 2; i++)
    {
        if (ans[i] > ans[i + 1])
        {
            x = ans[i];
            y = i;
        }
    }
    cout << "The largest row sum is " << x << " of row " << i + 1;
}

*********************************************************************************************************************************
void printlikewave(int arr[][3]);
int main()
{
    int arr[3][3];
    int x = 3;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {

            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int f;
    cout << "Enter the elemenet to be found: " << endl;
    cin >> f;
    if (findelement(arr, f))
    {
        cout << "found" << endl;
    }
    else
        cout << "not found" << endl;

    sumoftherows(arr);
    cout << "Printing like wave now" << endl;
    return 0;
}
int main(){
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    int ans[9];
    int row = 3;
    int col = 3;
    int count = 0;
    int total = 9 ;
    int x =0;
    while (count < total){
        for (int i = 0 ; i<3 ; i++){
            for (int j = 2 ; j>=0 ; j--){
                ans[x] = arr[j][i];
                x++;
                count++ ;
            }
        }
    }
    for (int i=0 ; i<9 ; i++){
        cout << ans[i] << " " ;
    }

*********************************************************************************************************************************
//3SUM
void threeSum(vector<int>& nums){
        vector<int> ans;
        int n = 7;
        int x=0;
        for (int i=0 ; i<n-2 ; i++)
        {
            for (int j = i+1 ; j<n ; j++)
            {
                if (j!=i)
                {
                    for (int k = j+1 ; k<n ;k++)
                    {
                            if (nums[i]+nums[j]+nums[k] == 0){
                                ans.push_back(nums[i]) ;
                                x++;
                                ans.push_back(nums[j]) ;
                                x++;
                                ans.push_back(nums[k]) ;
                                x++;
                                
                            }
                        
                    }
                }
                
            }
        }
        for (int i=0 ; i<x ; i++){
            cout<<ans[i] << " " ;
        }
        
    }
int main(){
    vector<int> a = {-2,0,2,7,-9,8,3};
    threeSum(a);
}

*********************************************************************************************************************************
int secondsmallest(vector<int> arr){
    int x=INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0 && arr[i]<x)
        {
            x = arr[i];
        }
    }
    return x;
}
bool checkifallzero(vector<int> arr ,int n){
    for (int i = 0; i<n  ;i ++){
        if (arr[i]!=0)
            return false;
    }
    return true;
}
int minimumOperations(vector<int>& arr)
{   
    int v = 0 ;
    static int count = 0 ;
    if (checkifallzero(arr,arr.size()))
    {
        return count;
    }    
    int x = secondsmallest(arr) ;
    
    for (int i = 0 ; i<arr.size() ; i++)
    {   
        
        if (arr[i]==0){
            continue;
        }
        else {
            arr[i]-=x ;
        }
    }
    count++;
    minimumOperations(arr) ;
    return count ;
}

*/

