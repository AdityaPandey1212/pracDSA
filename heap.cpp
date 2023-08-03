#include <iostream>
#include <vector>
using namespace std;
class heap
{
public:
    int arr[100];
    int size = 0;
    void insert(int val)
    {
        size = size + 1;
        arr[size] = val;
        int index = size;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                break;
        }
        return;
    }

    void deletion()
    {
        // deletion mtlb we are talking about deleting the root;
        // we have the array representiation, make last node as first,then delete last element;
        swap(arr[1], arr[size]); // can also go ahead wtih arr[1] = arr[size];
        size--;

        int index = 1;
        while (1 < size)
        {
            int leftIndex = index * 2;
            int rightIndex = index * 2 + 1;
            if (leftIndex <= size && arr[index] < arr[leftIndex]) // checking with size should not be out of bound
            {
                swap(arr[index], arr[leftIndex]);
            }
            else if (rightIndex <= size && arr[index] < arr[rightIndex]) // checking with size as it should not be out f bound
            {
                swap(arr[index], arr[rightIndex]);
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++) // from one kuki starting wala toh exclude krte hai naswap(arr[parent],arr[index]);
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
void heapify(vector<int> arr, int index)
{
    int temp = index;
    int leftIndex = index * 2;
    int rightIndex = index * 2 + 1;

    int n = arr.size();
    if (leftIndex < n && arr[leftIndex] > arr[index])
    {
        index = leftIndex;
    }
    if (rightIndex < n && arr[rightIndex] > arr[index])
    {
        index = rightIndex;
    }
    // check if index was updated
    if (index != temp)
    {
        swap(arr[index], arr[temp]); // ek iteration ho gayi
        // ab dekho ki kya aur ki sahi jagah pr pahuchaya ja sakta hai kya>
        heapify(arr, index);
    }
}
int main()
{
    heap h;
    h.insert(6);
    h.insert(9);
    h.insert(420);
    h.insert(3);
    h.insert(4);

    h.print();

    h.deletion();

    h.print();

    // now creating the array containing the heap elements
    cout << "the second heap which we are building from the vector" << endl;
    vector<int> arr = {-1, 40, 32, 44, 12, 33, 41, 39};
    int n = arr.size();
    for (int i = n / 2; i > 0; i--) 
    {
        heapify(arr, i);
    }

    heap p;
    for (int i = 1; i < n; i++)
    {
        p.insert(arr[i]);
    }
    p.print();
    return 0;
}