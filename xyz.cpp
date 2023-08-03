#include <bits/stdc++.h>
using namespace std;
/* QUICK
int partition(vector<int> &arr, int start, int end)
{
    // for last element as piviot
    int piviot = arr[end];
    int index = start - 1;
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= piviot)
        {
            index++;
            swap(arr[index], arr[i]);
        }
    }
    swap(arr[index + 1], arr[end]);
    return index + 1;
}

void randomize(vector<int> &arr, int start, int end)
{
    int index = start + rand() % (end - start);
    cout << "index swap from: " << index << endl;
    swap(arr[index], arr[end]);
    return;
}

void quickSort(vector<int> &arr, int start, int end)
{
    // basecase
    if (start >= end)
    {
        return;
    }
    randomize(arr, start, end);
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}


void print(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void bubble(vector<int> &arr)
{
    int n = arr.size();
    bool swapped = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if (arr[j] < arr[j-1])
            {
                swapped = true;
                swap(arr[j],arr[j-1]);
            }
        }
        if (!swapped)
        {
            break;
        }
        swapped = false;
    }
    return;
}

void selection(vector<int> &arr)
{
    int n = arr.size();
    for (int i= 0 ;i<n;i++)
    {
        int min = INT_MAX;
        int index = -1;
        for (int j = i;j<n;j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                index = j;
            }
        }
        swap(arr[index],arr[i]);
    }
    return;
}

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i=1;i<n;i++)
    {
        int temp = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    return;
}
*/


void mergefunction(vector<int> &arr, int start, int end)
{
    int mid = (start + end) / 2;
    int x = mid - start + 1;
    int y = end - mid;
    int index = start;
    int *arr1 = new int[x];
    int *arr2 = new int[y];
    for (int i = 0; i < x; i++)
    {
        arr1[i] = arr[index++];
    } 
    index = mid + 1;
    for (int i = 0; i < y; i++)
    {
        arr2[i] = arr[index++];
    }
    //merge and overwrite
    index = start;
    int i = 0, j = 0;
    while(i < x && j < y)
    {
        if (arr1[i] < arr2[j])
        {
            arr[index++] = arr1[i++];
        }
        else 
        {
            arr[index++] = arr2[j++];
        }
    }
    while(i < x)
    {
        arr[index++] = arr1[i++];
    }
    while (j < y)
    {
        arr[index++] = arr2[j++];
    }
}

void mergeSort(vector<int> &arr, int start, int end)
{
    // basecase
    if (start >= end)
    {
        return;
    }
    int mid = (start + end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    mergefunction(arr,start,end);
}

int main()
{
    int x = -69;
    string a = to_string(x);
    cout << a;
    return 0;
}