#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
/*int idk(int n){
    vector<int> arr ;
    while (n!=0){
        int a = n%10 ;

        n = n / 10 ;
        arr.push_back(a);
    }
    //sort(arr.begin(), arr.end());
    for (int i=0 ; i<arr.size() - 1 ; i++){
        if (arr[i]==arr[i+1]){
            cout<<"No"<<endl;
            return 0 ; 
        }
    }
    for (int i=0 ; i<arr.size() - 1 ; i=i+2){
        if (arr[i+1] - arr[i] == 1 || arr[i+1] - arr[i] == -1){
            if (arr[0]==0 && arr[1]==arr[2]){
                return 0;
            }
            continue ;
        }
        else {
            cout<< "No" << endl;
            return 0;
        }
    }
    cout <<"Yes"<<endl; 
    return 1;
}

void jumpingNumbers(int n)
{
    int flag = 0;
    int a, b;
    vector<int> ans;
    vector<int> temp;
    if (n >= 10)
    {
        for (int s = 0; s < 11; s++)
        {
            ans.push_back(s);
        }


        for (int i = 12; i < n; i++)
        {
            int count = 0;
            int a = 0;

            while (i != 0)
            {

                a = i % 10;
                i = i / 10;
                temp.push_back(a);
                count++;
            }
            sort(temp.begin(), temp.end());
            if (temp[i - 11] != temp[i - 12] + 1)
            {
                flag = 1;
                temp.clear();
                
            }
            if (flag == 0)
            {
                ans.push_back(i);
            }
        }
    }
    else if (n <= 10)
    {
        for (int i = 0; i <= n; i++)
        {
            ans.push_back(i);
        }
    }

    for (int f = 0; f < ans.size(); f++)
    {
        cout << ans[f] << " ";
    }
}
int main()
{
    int x =110; 
    int y = idk(x);
    return 0 ;
    

}

**************************************************
// Insersion
int sort(int arr[] , int n){
    for (int i=0 ; i <n-1 ;i++){

        for (int j=i+1 ; j<n ; j++){
            int temp[n] ;
            
            if (arr[i]<arr[j]){
                temp[i+1] = arr[j] ;
            }
            else {
                int x = arr[i] ;
                arr[i] = arr[j] ;
                arr[j] = x ;
            }
        }
    }
    for (int k=0 ; k<n ;k++){
        cout << arr[k] << endl;
    }
    return 0;
}
int main(){
    int arr[] = {5,3,1,2,4};
    sort(arr , 5);
}*/




