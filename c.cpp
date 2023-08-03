
// using namespace std;

// int nthTermOfGP(int c, int a, int b) {
//     // Write your code here.

// 	int answer=a;
//     for (int j=1
// 	;j<c;j++){
// 		answer = answer + b;
//     }

// 	return answer;
// }
// int main(){
// 	int x;
// 	int a;int b; int c;
// 	int arr[x];
// 	cin>>x;
// 	for (int i=0; i<x; i++){
// 		cin>>a>>b>>c;
// 		arr[i]=nthTermOfGP(c,a,b);

// 	}
// 	for (int j=0 ; j<x ; j++){
// 		cout<<arr[j]<<endl;
// 	}
// 	return 0;
// }
/*#include <stdio.h>
void s(int n){
    int r,q,y,i;
    int count=1;
    int arr[100];
    while (q!=0){
        arr[i]=n%10;
        q=n/10;
        count++;
    }
    int p=1;
    int s=0;
    for (int i= 0; i<count; i++){
        p= p*arr[i];
        s=s+arr[i];
    }
    y=p-s;
    printf("%d", y);
}

int main(){
    int n;
    scanf("%d", &n);
    s(n);
    return 0;
}*/
// #include <iostream>
// using namespace std;

// int main() {
// 	// your code goes here
// 	int arr[4];
// 	int count=0;
// 	for (int i=0 ; i<4 ;i++){
// 	    cin>>arr[i];
// 	    if (arr[i]>=10){
// 	        count=count + 1;
// 	    }
// 	}
// 	cout<<count;
// 	return 0;
// }
// #include <iostream>
// using namespace std;

// int main() {
// 	// your code goes here
// 	int x,a,arr[a],y,i,j,k;
// 	cin>>x;
// 	for (i=0; i<x;i++){
// 	    cin>>a;
// 	    int count=0; //number of peoblems
// 	    for (j=0; j<a;j++){
// 	        cin>>arr[i];
// 	        if (arr[i]>=1000){
// 	            count=count+1;
// 	        }
// 	    }
// 	    cout<<count<<endl;

// 	}
// 	return 0;
// }
/*#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int r, i, j, count = 0;
    int arr[10];
    int q = 1;
    int ans=0;
    cout << "1" << endl;
    while (q != 0)
    {
        r = n % 10;
        q = n / 10;
        n = q;
        count = count + 1;
        ans=ans*10 + r;
    }
    cout<<ans<<endl;
    //cout<<count;
    // for (i == 0; i < count; i++)
    // {
    //     cout << arr[i] << endl;
    // }
    return 0;
}


#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t, a, b, c, d, i;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int arr[4];
        for (int k = 0; k < 4; k++)
        {
            cin >> arr[k];
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 1; j < 4; j++)
            {
                if (arr[i] > arr[j])
                {
                    a = arr[i];
                    b = i;
                }
            }
        }
        int array[3];
        for (int i = 0; i < 3; i++)
        {
            if (i != b)
                array[i] = arr[i];
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 1; j < 3; j++)
            {
                if (arr[i] > arr[j])
                {
                    c = arr[i];
                }
            }
        }
        cout << a + c << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t, a, b, c, d, i;
    cin >> t;
    int array[10];
    for (int i = 0; i < t; i++)
    {
        int arr[2];
        for (int k = 0; k < 2; k++)
        {
            cin >> arr[k];
        }
        int arrr[2];
        for (int k = 0; k < 2; k++)
        {
            cin >> arrr[k];
        }
        if (arr[0] > arr[1])
        {
            a = arr[0];
        }
        else
        {
            a = arr[1];
        }
        if (arrr[0] > arrr[1])
        {
            c = arrr[0];
        }
        else
        {
            c = arrr[1];
        }
        array[i]=a+c;

    }
    for (int i=0 ; i<t ; i++){
        cout<<array[i]<<endl;
    }
    return 0;

}

#include <iostream>
using namespace std;

int main()
{
    int max;
    int a, i, b;
    cin >> a;
    int arr[a];

    for (int i = 0; i < a; i++)
    {
        cin >> arr[i];
    }
    /*for (int i = 0; i < a; i++)
    {
        for (int j = 1; j < a; j++)
        {
            if (arr[i] > arr[j])
            {
                max = i;
            }
        }
    }
    int min;
    for (int i=0 ; i<a ; i++)
    {
        for (int j=1 ; j<a ; j++){
            if (arr[i]<arr[j]){
                min=i;
            }
        }
    }
    cout<< arr[min]<<endl;
    cout << arr[max];
    int sum=0;
    for (int j=0 ; j<a ; j++){
        sum = sum + arr[j];
    }
    cout << sum ; 
    return 0;

}
#include <iostream>
using namespace std;
int main()
{   
    int a, key , flag=0 ;
    cout << "Enter the number of elements in array"<< endl;
    cin >> a;
    int array[a];
    for (int i=0 ; i<a ; i++){
        cin>>array[i];
    }
    
    cout << "Enter the element to be seatched for "<< endl;
    cin>>key;
    int start;
    int end = a-1;
    while (start<=end){
        int mid;
        mid = start + (end - start)/2 ;
        if (key == array[mid]){
            cout<<"The element was found at the index: "<< mid << endl;
            flag =1;
            break;
        } 
        else if (key > array[mid]){
            start = mid+1;

        }
        else if (key <array[mid]){
            end = mid -1;
        }
w    }
    if (flag = 0){
        cout << "the element wasnt found" <<endl;
    }


    return 0;
}

#include <iostream>
using namespace std;
int thefirstoccurence(int arr[] , int n , int key){
    int start = 0 ;
    int end  = n - 1 ;
    int ans = -1 ;
    int mid;
    mid = start + ((end -start)/2);
    while (start<=end){
        
        if (key == arr[mid]){
            ans = mid ;
            end = mid -1 ;
        }
        else if(key>arr[mid]){
            start = mid +1;
        }
        else if (key < arr[mid]){
            end = mid - 1;
        }

    mid = start + ((end -start)/2);   
        
    }
    return ans;
    
}
int thelastoccurence(int arr[] , int n , int key){
    int start = 0 ;
    int end  = n - 1 ;
    int ans = -1 ;
    int mid;
    mid = start + ((end -start)/2);
    while (start<=end){
        
        if (key == arr[mid]){
            ans = mid ;
            start = mid +1 ;
        }
        else if(key>arr[mid]){
            start = mid +1;
        }
        else if (key < arr[mid]){
            end = mid - 1;
        }

    mid = start + ((end -start)/2);   
        
    }
    return ans;
    
}

int totaloccurence(int arr[] ,int n , int key){
    int start = 0 ; 
    int start2;
    int end =n -1 ;
    int end2;
    int mid;
    int count = 0;
    mid =start + ((end -start)/2);
    while (start <=end){
        int start2 =mid+1;
        int end2=mid-1;
        if (arr[mid]== key){
            count = count +1 ;
            if (arr[mid-1]==key){
                
            }
            else (arr[mid+1]==key){

            }
        }
        else if (arr[mid] > key){
            end = mid -1 ;

        }
        else if (arr[mid]<key){
            start = mid +1;
        }
        mid = start + ((end - start )/2);
        
    }
    return count;
}

int mountain(int arr[]){

    //Mountain array kka inden using binary search and shit
    int a = 10;
    int x;
    
    int start = 0;
    int end = a-1;
    int mid = start +((end -start)/2);
    while (end >=start){
        
        if (arr[mid]>arr[mid - 1] && arr[mid]>arr[mid + 1]){
            x=mid;
            break;
        }
        else if (arr[mid]>arr[mid  - 1]){
            start = mid +1 ;
        }
        else if (arr[mid]> arr[mid +1]){
            end = mid ;
        }
        mid = start +((end -start)/2);
    }
    return x;
}*/
