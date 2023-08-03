#include <bits/stdc++.h>
using namespace std;

int heapSize;
//This is a function to swap using pointers pointers 
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
//heapify fucntion : TC log(N) ADITYA KR PANDEY 21BCI0280
void maxHeapify(int arr[], int i)
{
    int l = 2 * i;
    int r = 2 * i + 1;//using zero based indexing
    int great = 0;
    if (l <= heapSize && arr[l] > arr[i])
        great = l;
    else
        great = i;
    if (r <= heapSize && arr[r] > arr[great])
        great = r;
    if (great != i)
    {
        int aux = arr[i];
        arr[i] = arr[great];
        arr[great] = aux;
        maxHeapify(arr, great);
    }
}
//built heap function , Overall complexity O(N)
void buildMaxHeap(int arr[], int n)
{
    heapSize = n;
    if (n == 1)
        maxHeapify(arr, 0);
    else if (n == 0)
        maxHeapify(arr, 0);
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, i);
}

void heapsort(int arr[], int n)
{
    for (int j = n - 1; j >= 0; j--)
    {
        buildMaxHeap(arr, j);
        swap(&arr[0], &arr[j]);
    }
    cout << "result of heap sort applied: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
//This is the topdown approach
void topdown(int arr[], int n)
{
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr[i];
        for (int j = i / 2 - 1; j >= 0; j--)
        {
            heapSize = i;
            maxHeapify(arr1, j);
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    cout<<endl;
    heapsort(arr1, n);
}
int main()
{
    //Aditya Kr Pandey 21BCI0280
    int arr[] = {2,4,1,5,9,8,7,12,34,0,8};
    int n = 11;
    int arr2[] = {2,4,1,5,9,8,7,12,34,0,8};
    buildMaxHeap(arr, n);
    cout << "Bottom up: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout<<endl;
    heapsort(arr, n);
    cout << endl;
    cout<< "Top Down: ";
    topdown(arr2, n);
    return 0;
}