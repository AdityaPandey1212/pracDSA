#include <iostream>
#include <queue>
using namespace std;

class que
{
private:
    int *arr;
    int qfront;
    int qrear;
    int size;
    

public:
    //intitalising the queue 
    que()
    {
        int size = 5;
        arr = new int[size]; //creates an array of size 10;
        qfront = 0;
        qrear = 0;
    }
    void push(int x)
    {
        //check if full 
        if (qrear == size-1)
        {
            cout<< "the queue is full bruh" <<endl;
            return;
        }
        else 
        {
            arr[qrear] = x ;
            qrear++;
        }

    }

    void pop()
    {
        //check empty 
        if (qrear == 0)
        {
            cout<<"tHE QUEUE IS EMPTY"<<endl;
            return;
        }        
        else
        {
            qfront++;
        }
    }
    void front()
    {
        if (qfront!=qrear)
        {
            cout<<arr[qfront]<<endl;
        }
    }
};
int main()
{
    que q;
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(78);
    q.pop();
    q.front();
    return 0;
}


//implementing dequeue usig STL 
int main()
{
    deque<int> a;
    a.push_front(221);
    a.push_front(1122);
    a.push_front(22);
    a.push_front(12);
    a.push_front(12);
    a.push_front(23);
    a.push_front(22);
    a.push_front(1);
    cout<<a.front()<<endl;
    a.pop_front();
    cout<<a.front()<<endl;
    cout<<a.back()<<endl;
    cout<<a.size()<<endl;
    a.pop_front();
    cout << a.size() << endl;
    return 0;
}
 

    