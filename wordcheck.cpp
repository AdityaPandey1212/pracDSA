#include <iostream>
#include <vector>
#include <algorithm>
#include<map>

using namespace std;
int main()
{
    int x;
    //+97
    vector<int> arr(26);
    cout<<"Enter the number of sessions"<<endl;
    cin>>x;
    while (x--)
    {
        string a ="";
        cout<<"Enter the mistakes"<<endl;
        cin>>a;
        int n = a.length();
        for (int i=0;i<n;i++)
        {
            arr[int(a[i]) - 97]++;
        }
    }
    map<char,int> m;
    for (int i=arr.size()-1;i>=0;i--)
    {
        if (arr[i]!=0)
        {
            m[i+97] = arr[i];
        }
    }
    vector<char> ans;
    for (char i = 'a' ; i<= 'z' ;i++)
    {
        if (m[i]!=0)
        {
            cout << i << " " << m[i] << endl;
        }
    }
    return 0;
}