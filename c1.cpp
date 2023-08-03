#include <iostream>
#include <vector>
using namespace std;
/*int findPosition(int arr[], int a, int k)
{

    int x = 0;
    int start = 0;
    int end = a - 1;
    int mid = start + ((end - start) / 2);
    while (start <= end)
    {
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else if (arr[mid] < arr[mid + 1] && arr[mid] < arr[mid - 1])
        {
            x = mid;
            break;
        }
        else
        {
            end = mid;
        }
        mid = start + ((end - start) / 2);
    }

    int s1 = 0;
    int s2 = x;
    int e1 = x-1;
    int e2 = a - 1;
    int index1 = -1;
    int index2 = -1;
    int m1 = s1 + ((e1 - s1) / 2);
    while (s1 <= e1)
    {
        if (arr[m1] == k)
        {
            index1 = m1;
            break;
        }
        else if (arr[m1] > k)
        {
            e1 = m1 - 1;
        }
        else if (arr[m1] < k)
        {
            s1 = m1 + 1 ;
        }
        m1 = s1 + ((e1 - s1) / 2);
    }
    int m2 = s2 + ((e2 - s2) / 2);
    while (s2 <= e2)
    {
        if (arr[m2] == k)
        {
            index2 = m2;
            break;
        }
        else if (arr[m2] > k)
        {
            e2 = m2 - 1;

        }
        else if (arr[m2] < k)
        {
            s2 = m2 + 1;
        }
        m2 = s2 + ((e2 - s2) / 2);
    }

    if (index1 > index2)
    {
        return index1;
    }
    else if (index1==-1 && index2==-1){
        return -1;
    }
    else
    {
        return index2;
    }



}

int main()
{
    int t;

    cin >> t;

    int f[t];
    for (int i = 0; i < t; i++)
    {

        int a;
        int c;
        cin >> a >> c;
        int arr[a];
        for (int k = 0; k < a; k++)
        {
            cin >> arr[k];
        }


        f[i] = findPosition(arr, a, c);
    }

    for (int i = 0; i < t; i++)
    {
        cout << f[i] << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int findPosition(int arr[], int a, int k)
{


    int x = 0;
    int start = 0;
    int end = a - 1;
    int mid = start + ((end - start) / 2);
    while (start <= end)
    {
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else if (arr[mid] < arr[mid + 1] && arr[mid] < arr[mid - 1])
        {
            x = mid;
            break;
        }
        else
        {
            end = mid;
        }
        mid = start + ((end - start) / 2);
    }

    int s1 = 0;
    int s2 = x;
    int e1 = x - 1;
    int e2 = a - 1;
    int index1 = -1;
    int index2 = -1;
    int m1 = s1 + ((e1 - s1) / 2);
    while (s1 <= e1)
    {
        if (arr[m1] == k)
        {
            index1 = m1;
            break;
        }
        else if (arr[m1] > k)
        {
            e1 = m1 - 1;
        }
        else if (arr[m1] < k)
        {
            s1 = m1 + 1;
        }
        m1 = s1 + ((e1 - s1) / 2);
    }
    int m2 = s2 + ((e2 - s2) / 2);
    while (s2 <= e2)
    {
        if (arr[m2] == k)
        {
            index2 = m2;
            break;
        }
        else if (arr[m2] > k)
        {
            e2 = m2 - 1;
        }
        else if (arr[m2] < k)
        {
            s2 = m2 + 1;
        }
        m2 = s2 + ((e2 - s2) / 2);
    }

    if (index1 > index2)
    {
        return index1;
    }
    else if (index1 == -1 && index2 == -1)
    {
        return -1;
    }
    else
    {
        return index2;
    }
}

int main(){
    int t;
    cin>>t;
    int f[t];
    for (int i=0 ; i<t ;i++){
        int a,c;
        cin>>a>>c;
        int arr[a];
        for (int j=0 ; j<a ; j++){
            cin>>arr[j];
        }
        f[i]=findPosition(arr , a , c);
    }
    for (int i = 0 ; i<t ;i++ ){
        cout<<f[i]<<endl;
    }
}
#include <iostream>
#include <vector>
using namespace std;
bool ispossible(vector<int> arr, int n, int m , int mid){
    int student=1;
    int pages = 0;
    for (int i = 0 ; i < n ; i++){
        if (pages + arr[i] <= mid)
        {
            pages+=arr[i];
        }
        else {
            student++;
            if (student  > m || arr[i] > mid){
                return false;
            }
            else {
                pages = arr[i];
            }
        }
    }
    return true ;
}


int allocateBooks(vector<int> arr, int n, int m) {
    // Write your code here.
    int start = 0;
    int end;
    int sum = 0;
    for (int i = 0 ; i<n ; i++){
        sum = sum + arr[i];
    }
    int ans;
    int start = sum;
    int mid = start + ((end -start)/2);
    while (start<=end){
        if (ispossible(vector<int>& arr , n , m , mid)){
            ans = mid ;
            end = mid -1 ;
        }
        else{
            start = mid + 1;
        }
    }
    return ans ;
}
#include <iostream>
#include <vector>
using namespace std;

int min(vector<int> arr, int i)
{
    int min;
    int x = -1;
    int n = arr.size();
    for (int j = i; j < n - 1; j++)
    {
        if (x == -1)
        {
            if (arr[i] > arr[j + 1])
            {
                x = j + 1;
                min = j + 1;
            }
        }
        else
        {
            if (arr[i] > arr[j + 1] && arr[x] > arr[j + 1])
            {
                x = j + 1;
                min = j + 1;
            }
        }
        cout << min << endl;
        return min;
    }
    return 0;
}
void selectionSort(vector<int> arr, int n)
{

    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        int temp;
        temp = arr[i];
        int j = min(arr, i);
        arr[i] = arr[j];
        arr[j] = temp;
        temp = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{

    vector<int> arr = {22, 41, 12, 11, 0, 1, 123};
    selectionSort(arr, 7);
}
*******************************

// PATERN SWAPANAL
int main(){
    int x = 1;
    int r = 0,c = 0 ;
    int n;
    cin>>n;
    cout<<endl<<endl;
    int b = 1;
    while (r<n)
    {
        if (r%2==0)
        {
            x=0;
        }
        else {
            x=1;
        }
        c=0;
        while (c<b && c<n)
        {
            if (x==0)
            {
                x=1;
                cout<< 1 << " ";

            }
            else if (x==1)
            {
                x=0;
                cout<<"0"<<" ";
            }
            c++;
        }
        b++;
        cout<<endl;
        r++;
    }
    cout<<endl<<endl;
}*/

// void findDuplicates(vector<int>& nums) 
// {
//     vector<int> arr;
//     for (int i=0 ; i<nums.size()-1 ; i++)
//     {
//         if (nums[i]==nums[i+1]){
//             arr.push_back(nums[i]);
//             i++;
//         }
//     }
//     for (int i = 0 ;i<arr.size();i++)
//     {
//         cout<<arr[i] <<endl;
//     }
// }


// int main()
// {
//     vector<int> arr = {1,2,3,4,4,5,6,6,7};
//     findDuplicates(arr);
//     return 0;
// }