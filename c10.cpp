#include <bits/stdc++.h>
#include <algorithm>
#include <chrono> // this is the liberary that needs to be included to mesure time
using namespace std;
void getSwapped(string &x, string &y) // a finction to swap the strings as it was being used at multiple places
{
    string temp;
    temp = x;
    x = y;
    y = temp;
}
//ADITYA  KR  PANDEY   ------    21BCI0280


void selectionSort(vector<int> nums, vector<string> strings, int x)
{
    auto start = chrono::steady_clock::now();
    if (x == 1) // data type entered is one
    {
        // selection sort has to be performed using numbers
        int minInd, startInd, currInd, size = nums.size();
        if (size <= 1)
            return;
        for (startInd = 0; startInd < size - 1; startInd++)
        {
            for (currInd = startInd + 1, minInd = startInd; currInd < size; currInd++)
                if (nums[minInd] > nums[currInd])
                    minInd = currInd;
            if (minInd != startInd)
                swap(nums[startInd], nums[minInd]);
        }
        cout << "After sorting we get: ";
        // now printing
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
    }
    else
    {
        int size = strings.size();
        int lowestPosition;
        string lowestValue;

        for (int i = 0; i < size - 1; i++)
        {
            // first, find position of lowest element in positions i through size-1
            lowestValue = strings[i];
            lowestPosition = i;
            for (int j = i + 1; j < size; j++)
            {
                if (strings[j] < lowestValue)
                {
                    lowestPosition = j;
                    lowestValue = strings[j];
                }
            }
            // now, swap the lowest element we found with element at position I
            getSwapped(strings[i], strings[lowestPosition]);
        }
        cout << "After sorting we get strings: ";
        for (int i = 0; i < strings.size(); i++)
        {
            cout << strings[i] << " ";
        }
    }
    auto ending = chrono::steady_clock::now();
    double elapsed = double(chrono::duration_cast<chrono::nanoseconds>(ending - start).count());
    cout<<"\n The time take to perform this operation was " <<elapsed<<" ns" ;
}

void bubbleSort(vector<int> arr, vector<string> strings, int x)
{
    auto start = chrono::steady_clock::now();
    if (x == 1)
    {
        int i, j;
        for (i = 0; i < arr.size() - 1; i++)
        {
            for (j = 0; j < arr.size() - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
        cout << "After sorting we get: ";
        // now printing
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        for (int i = 1; i < strings.size(); ++i)
        {
            for (int j = 0; j < (strings.size() - 1); ++j)
            {
                if (strings[j] > strings[j + 1])
                {
                    string const temp = strings[j];
                    strings[j] = strings[j + 1];
                    strings[j + 1] = temp;
                }
            }
        }
        cout << "After sorting we get strings: ";
        for (int i = 0; i < strings.size(); i++)
        {
            cout << strings[i] << " ";
        }
    }
    auto ending = chrono::steady_clock::now();
    double elapsed = double(chrono::duration_cast<chrono::nanoseconds>(ending - start).count());
    cout << "\n The time take to perform this operation was " << elapsed << " ns";
}
void insertionSort(vector<int> arr, vector<string> strings, int x)
{
    auto start = chrono::steady_clock::now();
    if (x == 1)
    {
        // we need to sort a numeric array named arr
        for (int k = 1; k < arr.size(); k++)
        {
            int temp = arr[k];
            int j = k - 1;
            while (j >= 0 && temp <= arr[j])
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = temp;
        }
        cout << "After sorting we get array: ";
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        bool a = false;
        // we need to sort a string array
        if (a)
        {
            int i, j;
            string key;
            int n = strings.size();
            for (i = 1; i < n; i++)
            {
                key = strings[i];
                j = i - 1;
                while (j >= 0 && strings[j] > key)
                {
                    strings[j + 1] = arr[j];
                    j = j - 1;
                    strings[j + 1] = key;
                }
            }
        }
        sort(strings.begin(), strings.end());
        cout << "After sorting we get strings: ";
        for (int i = 0; i < strings.size(); i++)
        {
            cout << strings[i] << " ";
        }
    }
    auto ending = chrono::steady_clock::now();
    double elapsed = double(chrono::duration_cast<chrono::nanoseconds>(ending - start).count());
    cout << "\n The time take to perform this operation was " << elapsed << " ns";
}
int main()
{
    cout << "----->ADITYA KR PANDEY 21BCI0280<-----" << endl;
    cout << "<< What would you like to sort? >>" << endl;
    cout << "Press 1 ---> for sorting numbers!" << endl;
    cout << "Press 2 ----> for sorting strings!" << endl;
    int dataType = 0;
    cin >> dataType;

    vector<int> numericals;
    vector<string> strings;
    if (dataType == 2)
    {
        int x = 0;
        cout << "Enter the number of elements \n";
        cin >> x;
        // taking user input for the string array
        for (int i = 0; i < x; i++)
        {
            string s;
            getline(cin >> ws, s);
            strings.push_back(s);
        }
        strings.size();
    }
    else if (dataType == 1)
    {
        int x = 0;
        cout << "Enter the number of elements \n";
        cin >> x;
        // taking user input for the string array
        for (int i = 0; i < x; i++)
        {
            int s;
            cin >> s;
            numericals.push_back(s);
        }
    }
    else
    {
        cout << "Invalid user input" << endl;
    }
    cout << "Seletc the sorting technique you would like to use \n 1.Selection Sort \n 2.Bubble Sort \n 3.Insersion Sort" << endl;
    int sortingType = 0;
    cin >> sortingType;
    if (sortingType == 1)
    {
        selectionSort(numericals, strings, dataType);
    }
    else if (sortingType == 2)
    {
        bubbleSort(numericals, strings, dataType);
    }
    else
    {
        insertionSort(numericals, strings, dataType);
    }
    return 0;
}
