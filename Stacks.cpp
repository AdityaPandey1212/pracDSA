#include <iostream>
using namespace std;
class stack
{
    public:
    int top;
    int* arr;
    int size;
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    //function 1
    int size_of()
    {
        return size;
    }
    void peek()
    {
        if (top!=-1)
        {
            cout<< arr[top]<<endl;
            return;
        }
        cout<<"The stack is sempty";
    }
    //function 2
    void push(int x)
    {
        if (top == size-1)
        {
            cout<<"stack overflow"<<endl;
            return;
        } 
        arr[top+1] = x;
        top++;
        return;
    }
    //function2
    void pop()
    {
        if (top!=-1)
        {
            top--;
            return;
        }
        cout<<"The stack is empty"<<endl;
    }
    //function 3
    bool isempty()
    {
        if (top==-1)
            return true;
        return false;
    }
};

class Node
{
    public:
    int value;
    Node* next;
    Node()
    {

    }
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

class stackll
{
    public:
    int top;
    Node* head = NULL;
    Node* tail = NULL;
    int size;
    //function 1
    void push(int v)
    {
        Node* add = new Node(v);
        if (head==NULL)
        {
            head=add ;
            tail = head ;
            return;
        }
        tail->next = add ;
        tail = add;
    }

    void pop()
    {
        Node* temp = head;
        while (temp->next->next !=NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
    }
    void peek()
    {
        cout<<"Last element"<<tail->value<<endl;
    }
};


int main()
{
    stack s(5);
    int size = s.size_of();
    cout<<"The size of the stack is "<<size<<endl;
    s.push(5);
    s.push(4);
    s.push(6);
    s.push(2);
    s.push(3);
    s.push(69);
    cout<<"The last element in there before using pop"<<endl;
    s.peek();
    s.pop();
    cout << "The last element in there after using pop" << endl;
    s.peek();
    if (s.isempty())
    {
        cout<<"the given stack is empty"<<endl;
    }
    else
    {
        cout << "The stack is not empty" << endl;
    }
    int x = s.size_of();
    for (int i=0;i<x;i++)
    {
        s.pop();
    }
    
    if (s.isempty())
    {
        cout<<"The given stack is empty"<<endl;
    }
    else
    {
        cout << "The stack is not empty" << endl;
    }

    cout<<"*************************************"<<endl;
    cout<<"NOW IMPLEMENTING LL USING LINKED LIST" <<endl;
    stackll a;
    a.push(6);
    a.push(4);
    a.push(5);
    a.peek();
    a.pop();
    a.peek();
    return 0;

}