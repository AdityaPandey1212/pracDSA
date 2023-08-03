#include <iostream>
#include <list>
#include <string>
#include <chrono>
using namespace std;

void MergeSortA(int low, int high); //DECLEARING THE FINCTION TO PARTITION
void MergeA(int low, int mid, int high); //DECLEARING THE MERGE FUNCTION TO MERGE TWO ARRAYS

string currentArray[5];
int main()
{
    cout<< "--> ADITYA KR PANDEY - 21BCI0280 <--"<<endl;
    cout<<"Enter the strings to be sorted "<<endl;
    for (int i = 0; i < 5; i++)
        cin >> currentArray[i];
    auto start = chrono::steady_clock::now();
    MergeSortA(0, 4);
    auto ending = chrono::steady_clock::now();
    double elapsed = double(chrono::duration_cast<chrono::nanoseconds>(ending - start).count());
    cout << "The time take to perform this operation was " << elapsed << " ns";

    cout<<endl;
    cout<<"The elements after sorted the string array is "<<endl;
    for (int i = 0; i < 5; i++)
        cout << currentArray[i] << endl;

    return 0;
}

void MergeSortA(int low, int high)
{
    
    int mid = 0;
    if (low < high)
    {
        mid = ((low + high) / 2);
        MergeSortA(low, mid);
        MergeSortA(mid + 1, high);
        MergeA(low, mid, high);
    }
    
}
void MergeA(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    string Temp[5];

    while (i <= mid && j <= high)
    {
        if (currentArray[i] < currentArray[j])
        {
            Temp[k].assign(currentArray[i]);
            i++;
        }
        else
        {
            Temp[k].assign(currentArray[j]);
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        for (int h = j; h <= high; h++)
        {
            Temp[k].assign(currentArray[h]);
            k++;
        }
    }
    else
        for (int h = i; h <= mid; h++)
        {
            Temp[k].assign(currentArray[h]);
            k++;
        }
    for (int i = low; i <= high; i++) // copy from low to high
    {
        currentArray[i].assign(Temp[i]);
    }
}