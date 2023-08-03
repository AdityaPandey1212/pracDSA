#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// matrix VI
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        this->val = 0;
        this->next = NULL;
    }
};

void rotate(ListNode *&head, ListNode *&previous, ListNode *&current)
{
    if (current == NULL)
    {
        head = previous;
        return;
    }
    ListNode *forward = current->next;
    current->next = previous;
    previous = current;
    current = forward;
    rotate(head, previous, current);
}

ListNode *givemid(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
int pairSum(ListNode *head)
{
    if (head->next->next == NULL)
    {
        return (head->next->val + head->val);
    }
    ListNode *mid = givemid(head);
    ListNode *previous = mid;
    ListNode *current = mid->next;
    rotate(mid->next, mid, current);
    int maxi = INT_MIN;
    ListNode *temp2 = mid;
    ListNode *temp = head;
    while (temp2 != NULL)
    {
        int sum = temp->val + temp2->val;
        maxi = max(sum, maxi);
        temp2 = temp2->next;
        temp = temp->next;
    }
    return maxi;
}

/*
using namespace std;
class Solution
{
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode *head)
    {
        // m and n are give here
        int numberOfElmenets = n * m;
        int inserted = 0;
        ListNode *temp = 0;
        vector<vector<int>> ans(n, vector<int>(m, -1)); // ini. matrix with all-1
        int srow = 0;
        int erow = n - 1;
        int scol = 0;
        int ecol = m - 1;
        while (temp != NULL)
        {
            for (int i = scol; i <= ecol; i++)
            {
                ans[srow][i] = temp->val;
                temp = temp->next;
            }
            srow++;
            if (temp != NULL)
            {
                for (int i = srow; i <= erow; i++)
                {
                    ans[i][ecol] = temp->val;
                    temp = temp->next;
                }
            }
            ecol--;
            if (temp != NULL)
            {
                for (int i = ecol; i >= scol; i--)
                {
                    ans[erow][i] = temp->val;
                    temp = temp->next;
                }
            }
            erow--;
            if (temp != NULL)
            {
                for (int i = erow; i >= srow; i--)
                {
                    ans[i][scol] = temp->val;
                    temp = temp->next;
                }
            }
            scol++;
        }
        return ans;
    }
};*/
// search in a rotated sorted array
/*
int BinarySearch(int *arr, int s, int e, int key)
{
    int mid = 0;
    while (s <= e)
    {
        mid = (s + (e - s) / 2);
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] > key)
        {
            e = mid - 1;
        }
        if (arr[mid] < key)
        {
            s = mid + 1;
        }
    }
    return -1;
}

int findPiviot(int* arr, int n)
{
    int s = 0;
    int e = n - 1;
    int mid;
    int firstElement = arr[0];
    while (s <= e)
    {
        mid = (s + (e - s) / 2);
        if (arr[mid] < arr[mid-1] && arr[mid] < arr[mid + 1])
        {
            return mid;
        }
        if (arr[mid] > firstElement)
        {
            s = mid + 1;
        }
        if (arr[mid] < firstElement)
        {
            e = mid;
        }
    }
    return -1; // nopiviot
}
int search(int *arr, int n, int key)
{
    int piviotIndex = findPiviot(arr, n);
    // now there may be a case where no index is say, piviot
    if (piviotIndex == -1)
    {
        return BinarySearch(arr, 0, n - 1, key);
    }
    int left = 0;
    int right = 0;
    int start1 = 0;
    int end1 = piviotIndex - 1;
    int start2 = piviotIndex;
    int end2 = n - 1;
    left = BinarySearch(arr, start1, end1, key);
    right = BinarySearch(arr, start2, end2, key);
    if (left==-1 && right==-1)
    {
        return -1;
    }
    else
    {
        if (left>right)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}

int main()
{
    int arr[] = {3,1};
    int c = findPiviot(arr,2);
    cout<<c ;
    return 1;
}*/
class Node
{
public:
    int value;
    Node *next;
    Node()
    {
    }
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};
class queue
{
public:
    Node *start = NULL;
    Node *end = NULL;
    queue()
    {
    }
    void enqueue(int x)
    {

        Node *add = new Node(x);
        if (start == NULL)
        {
            start = add;
            end = add;
            return;
        }
        end->next = add;
        end = add;
    }
    void dequeue()
    {
        start = start->next;
    }

    void print()
    {
        Node *temp = start;
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    bool searchs(int x)
    {
        Node *traverse = start;
        while (traverse != NULL)
        {
            if (traverse->value == x)
                return true;
            traverse = traverse->next;
        }
        return false;
    }
};
int main()
{
    queue q;
    q.enqueue(69);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(7);
    q.dequeue();

    q.print();
    if (q.searchs(69))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
struct node
{
    string value;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
struct node *p;
int n = 0;

int MaxSize = 10;
void insert(string data1)
{
    if (n == MaxSize)
    {
        cout << "Queue is full";
        exit(0);
    }
    else if (n == 0)
    {
        struct node *temp = new struct node;
        temp->value = data1;
        temp->next = NULL;
        front = rear = temp;
        n++;
    }
    else
    {
        struct node *temp = new struct node;
        temp->value = data1;
        temp->next = front;
        rear->next = temp;
        rear = temp;
        n++;
    }
}
void Delete()
{
    if (n == 0)
    {
        cout << "Queue is empty , underflow case";
        exit(0);
    }
    else
    {
        struct node *temp = front;
        front = front->next;
        delete temp;
        n--;
    }
}
void search(string data1)
{
    p = front;
    int count = 1;
    while (true)
    {
        if (p->value == data1)
        {
            cout << "this is Patient No. " << count;
            break;
        }
        p = p->next;
        count++;
    }
}
void update(string data1, string data2)
{
    p = front;
    while (p != NULL)
    {
        if (p->value == data1)
        {
            p->value = data2;
            break;
        }
        else
        {
            p = p->next;
        }
    }
}
void display()
{
    p = front;
    int x = 0;
    while (x < n)
    {
        cout << p->value << " ";
        p = p->next;
        x++;
    }
}
int main()
{
    while (true)
    {
        cout << endl
             << "\\/\\ADITYA KR PANDEY 21BCIO280 - Hostptal/\\/" << endl;
        cout << "\n1.Insert\n2.Delete\n3.Search\n4.Update\n5.Display\n6.Exit\n";
        int x;
        string data;
        string a, b;
        cout << "Select an option: ";
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "name : ";
            cin >> data;
            insert(data);
            cout << "\n";
            break;
        case 2:
            Delete();
            break;
        case 3:
            cout << "\nPatient search : ";
            cin >> data;
            search(data);
            break;
        case 4:
            cout << "\nUpdate Patient : ";
            cin >> a;
            cout << "Enter the update value : ";
            cin >> b;
            update(a, b);
            break;
        case 5:
            display();
            break;
        case 6:
            cout << "Program terminated";
            exit(0);
        }
    }
    cout << "\\//\\ADITYA KR PANDEY 21BCIO280//\\//" << endl;
    return 0;
}