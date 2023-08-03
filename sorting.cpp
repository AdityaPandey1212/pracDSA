#include <iostream>
using namespace std;
//SEARCHING

void linear(int* arr ,int n ,int target) 
{
    for (int i=0;i<n;i++)
    {
        if (arr[i]==target)
        {
            cout<<"Found at the index: "<<i<<endl;
            return;
        }
    }
    cout<<"Not Found"<<endl;

    /*
        best case is O(1) , when the element being searched for is the very first element
        worst case is O(n) , when element doesnt exist or even the last element
    */
}

void BinarySearch(int* arr, int n , int target)   //THE ARRAY NEEDS TO BE SORTED!
{
    int s = 0;
    int e = n-1;
    int mid;
    while (s<=e)
    {
        mid = s+(e-s)/2; //eleminates the exceding of the INT_MAX limit
        if (arr[mid] == target)
        {
            cout<<"Found at the index: "<<mid<<endl;
            return;
        }
        if (arr[mid]>target)
            e = mid-1;
        else
            s = mid+1;
    }
    cout<<"Not Found"<<endl;
    return;

    /*
        best case is O(1) . this is when arr[mid] == target
        else O(log(n)) 
    */
}
/****************************************************************************
// SORTING ALGORITHMS AND THEIR ANALYSIS
****************************************************************************/
//selection sort
void selectionSort(int* arr,int n)
{
    for (int i=0;i<n-1;i++)
    {
        int minIndex = i;
        for (int j=i;j<n;j++)
        {
            if (arr[j]<arr[minIndex])
                minIndex = j;
        }
        
    //worst case and best both is n^2 it is what it is 
    //implace sorting algorithm and is unstable
}

//bubble sort
void BubbleSort(int* arr ,int n)
{
    //the optimised version
    
    for (int i=0;i<n-1;i++) //KITNE TIME CHALEGA LOOP , ie number of rounds
    {
        bool swaped = false;
        for (int j = 0 ; j< n - i -1 ; j++) //main kaam yaha ho raha , i.e. 0 se iteration
        {
            if (arr[j+1]<arr[j])
            {
                swap(arr[j],arr[j+1]);
                swaped = true;
            }
        }
        if (swaped == false)
            return;
    }

    //After optimisation we end up with O(N) time complexity as best case
    //we hav worst case as O(n^2)

}

void insersionSort(int* arr , int n)
{
    for (int i=1;i<n;i++)
    {
        int temp = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp; 
    }   
    return;
    //best case insersion is o(n) 
    //average case or worst both o(n^2)
}

void mergefunction(int* arr , int s ,int e)
{
    int mid = (s+e)/2;
    int x = mid - s + 1; //size1

    int y = e - mid ; //size2
    //create secondary arrays
    int* arr1 = new int[x];
    int* arr2 = new int[y];

    //copy them elemnts
    int mainarrIndex = s;
    for (int i=0;i<x;i++)
    {
        arr1[i] = arr[mainarrIndex++];
    }
    mainarrIndex = mid + 1;
    for (int i=0;i<y;i++)
    {
        arr2[i] = arr[mainarrIndex++];
    }
    // now merger them bitches 
    int i = 0;
    int j = 0;
    mainarrIndex = s;
    while (i<x && j<y)
    {
        if (arr1[i] < arr2[j])
        {
            arr[mainarrIndex++] = arr1[i++];
        }
        else 
        {
            arr[mainarrIndex++] = arr2[j++];
        }
    }
    while (i<x)
    {
        arr[mainarrIndex++]=arr1[i++];
    }
    while (j<y)
    {
        arr[mainarrIndex++]=arr2[j++];
    }
}


void mergeSort(int* arr,int s,int e)
{
    //works on divide and conqure
    //basecase
    if(s>=e)
    {
        return;
    }
    int mid = (s+e)/2; 

    //recurssion magic
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    //merge the two
    
    mergefunction(arr,s,e); 
    //best worst bith O(LOGN)
}


int Partition(int* arr , int s ,int e)
{
    int p = arr[s];
    int i = s;
    int j = e;
    while (i<j)
    {
        while (arr[i]<p)
        {
            i++;
        }
        while (arr[j]>p)
        {
            j--;
        }
        if (i<j)
            swap(arr[i],arr[j]);
    }
    return j;
}

void quickSort(int* arr ,int s ,int e) //partitioning logic n(logn)
{
    //ek element utha lo and usko uske sahi jagah ghusa do, left wael less than that element, right wale larger. its called partition
    if (s>=e)
    {
        return;
    }
    
    int piviot = Partition(arr,s,e);
    quickSort(arr,s,piviot-1);
    quickSort(arr,piviot+1,e);
    
}
//****************************************


int main()
{
    int arr[] = {4,6,2,21,7,55,11};

    quickSort(arr,0,6);
    for (int i=0;i<6;i++)
    {   
        cout<<arr[i]<<" ";
    }   
    return 0;
}
