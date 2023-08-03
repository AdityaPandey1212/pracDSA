#include <iostream>
#include <vector>
using namespace std;
/*********************************************************************************************************************************

#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int>& arr, int x){


    for (int i = 0 ; i<x-1 ; i++)
    {
        for (int j=i ; j<x ; j++)
        {
            if (arr[i] > arr [j])
            {

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

            }
            else {
                continue;
            }
        }
    }

    for (int k=0 ; k<x ; k++){
        cout << arr[k] <<" ";
    }

}
int main(){
    vector<int> arr;
    int x;
    cin>>x;
    for (int i = 0; i<x ; i++){
        int temp;
        cin>> temp;
        arr.push_back(temp);
    }
    bubbleSort(arr , x);
    return 0;
}
*********************************************************************************************************************************
//NHK

#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& arr1 ,vector<int>& arr2, int n,int m){
    int i = 0;
    int j= 0;
    while(j<m){
        if(arr1[i] < arr2[j]){
            i = i + 1;
        }
        else if(arr1[i] > arr2[j]){
            for (int x = m ; x >=i ; x++ ){
                arr1[x]=arr1[x-1];

            }
            arr1[i] = arr2[j];
            m++;
            j++;
            i++;
        }


    }
    cout<<"B R U H "<<endl;

}
*********************************************************************************************************************************

//MERGE TWO SORTED ARRAYS;

*********************************************************************************************************************************
int main() {
    //Write your code here
    int n;
    cin>>n;

    int arr[n];
    for (int i=0; i<n;i++){
        cin>>arr[i];
    }
    int temp[n];
    int k;
    cin>>k;
    for (int i=0 ; i<n ;i++){
        if (i-k >= 0){
            temp[ (i-k) % n ] = arr[i];
        }
        if (i-k< 0){
            int h=(i-k) ;
            h = -h;

            temp[ n -1 -(h % n) ] = arr[i];

        }
    }
    for (int i=0 ; i<n ; i++){
        cout<< temp[i] <<" ";
    }
    return 0;
}

********************************************************************************************************************************
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    int sum = 0;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];
    }
    if (sum < 10)
    {
        cout << sum;
        return 0;
    }
    else
    {

        while (sum != 0)
        {
            int r = sum % 10;
            sum = sum / 10;
            count = count + r;
            if (sum == 0)
            {
                sum = count;
                if (count < 10)
                {
                    break;
                }
            }
        }
    }
    cout << count << endl;
}
********************************************************************************************************************************
//matrix se sum like in
// 1    2   3   4
// +    9   9   9
//_________________
// 2    2   3   3 ETC     
int main(){
    int n, m ;
    n = 4;
    m = 4;
    int arr1[n] = {9,4,7,0};
    int arr2[m] = { 4,4,5,5};
    int i = n-1;
    int j = m-1 ;
    int carry = 0 ;
    int arr3[4] ;
    int x = 0;
    while (i>=0 && j >= 0){
        if (arr1[i]+arr2[j]+carry<10){
            arr3[x] = arr1[i]+arr2[j]+carry;
            x = x+1;
            i--;
            j--;
            carry = 0;
        }
        else {
            arr3[x] = (arr1[i]+arr2[j]+carry)%10;
            carry = 1;
            x++;
            i--;
            j--;
        }
    }
    while (i>=0){
        arr3[x] = carry + arr1[i];
        if (carry + arr1[i]<10){
            carry = 0;
        }
        i--;
        x++;
    }
    while (j>=0){
        arr3[x] = carry + arr2[j];
        if (carry + arr2[j]<10){
            carry = 0;
        }
        j--;
        x++;
    }
    if (carry != 0){
        arr3[x]=1;
        x=x+1;
    }
    for (int i=x-1; i>=0 ;i--){
        cout << arr3[i];
    }

    return 0;
}
int main(){
    int count = 0;
    int i = 0;
    char name[50];
    cin>> name;

    while(name[i]!= '\0'){
        count++;
        i++;
    }
    cout<<count <<endl;
    int s = 0;
    int e = count -1;
    while(e>=s){
        swap(name[s] , name[e]);
        s++;
        e--;
    }
    cout<<name << endl;
}
********************************************************************************************************************************
// VALID PALINDROM

char lowercase(char s)
{
    if ((s >= 'a' && s <= 'z') || (s >= 0 && s <= 9))
    {
        return s;
    }
    else
    {
        s = s - 'A' + 'a';
    }
    return s;
}
bool valid(char s)
{
    if ((s >= 'a' && s <= 'z') || (s >= 0 && s <= 9))
    {
        return 1;
    }
    return 0;
}
bool checkpalindrom(string a)
{
    int s = 0;
    int e = a.length();
    int x = 0;
    while (s <= e)
    {
        if (a[s] != a[e])
        {
            return 0;
        }
        else
        {
            s++;
            e--;
        }
    }
    return 1;
}
********************************************************************************************************************************
bool isPalindrome(string s)
{
    string a = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (valid(s[i]))
        {
            a.push_back(s[i]);
        }
    }
    for (int i = 0; i < a.length(); i++)
    {
        a[i] = lowercase(a[i]);
    }
    return checkpalindrom(a);
}
*/

// bool issafe(int x, int y, vector<vector<int>> visited, int n, int m)
// {
//     if ((x >= 0 && x < n) && (y >= 0 && y < m) && (visited[x][y] == 0))
//     {
//         return true;
//     }
//     return false;
// }
// void solve(int n, int m, vector<vector<int>> visited, int x, int y, vector<string> &ans, string output)
// {
//     if (x == n-1 && y == m-1)
//     {
//         ans.push_back(output);
//         return;
//     }
//     visited[x][y] == 1;

//     // DOWN
//     int newx = x - 1;
//     int newy = y;
//     if (issafe(newx, newy, visited, n, m))
//     {
//         output.push_back('D');
//         solve(n, m, visited, newx, newy, ans, output);
//         output.pop_back();
//     }
//     // UP
//     newx = x + 1;
//     newy = y;
//     if (issafe(newx, newy, visited, n, m))
//     {
//         output.push_back('U');
//         solve(n, m, visited, newx, newy, ans, output);
//         output.pop_back();
//     }
//     // RIGHT
//     newx = x;
//     newy = y + 1;
//     if (issafe(newx, newy, visited, n, m))
//     {
//         output.push_back('R');
//         solve(n, m, visited, newx, newy, ans, output);
//         output.pop_back();
//     }
//     // LEFT
//     newx = x;
//     newy = y - 1;
//     if (issafe(newx, newy, visited, n, m))
//     {
//         output.push_back('L');
//         solve(n, m, visited, newx, newy, ans, output);
//         output.pop_back();
//     }

//     visited[x][y] == 0;
// }

// vector<string> uniquePaths(int n, int m)
// {
//     vector<string> ans;
//     vector<vector<int>> visited(n, vector<int>(m, 0));
//     int x = 0;
//     int y = 0;
//     string output = "";
//     solve(n, m, visited, x, y, ans, output);
//     return ans ;
// }


// int main()
// {
//     int n,m;
//     vector<string> ans;
//     ans = uniquePaths(3,7);
//     for (int i=0 ;i<ans.size() ; i++){
//         cout<<ans[i]<<" " ;
//     }
//     cout<<endl;
//     int x = ans.size();
//     cout<<x;
    

//     return 0;
// }

