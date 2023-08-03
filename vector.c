#include <stdio.h>
#include <limits.h>
/*#include <bits/stdc++.h>
using namespace std;

class customVec{
    private:
        int size = 1;
        int count = 0;
        int data;
    public:
        int *arr = new int[size];
        bool isFull()
        {
            if (count == size)
                return true;
            return false;
        }
        void increaseSizeArray()
        {
            size = size+size;
            int* newArray = new int[size];
            for (int i = 0;i < size/2 ; i++)
            {
                newArray[i] = arr[i];
            }
            for (int i = size/2; i < size; i++ )
            {
                newArray[i] = 0;
            }
            arr = newArray;
        }
        void push_back(int value)
        {
            if (!isFull())
            {
                arr[count] = value;
                count++;
            }
            else
            {
                increaseSizeArray();
                push_back(value);
            }
        }
        void printVec()
        {
            for (int i=0; i<count; i++)
            {
                cout << arr[i] << " ";
            }
        }
};*/

struct datatype{
    int a;
    int b;
    char c;
};


int main()
{
    struct datatype lol;
    lol.a = 4;
    lol.b = 3;
    lol.c = 'h';
    int b = 3;
    printf(lol.c);
    return 0;
}