#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
//we can include the template thing which you definetly learned nicely to use any data structure not 
//just simple booring into 

//ans now after adding the templaye we got ourself a generic graph
template <typename T>
class Graph{
    public:
    unordered_map <T,list<T>> adjencyRepresentation;

    //function that adds edge
    void AddEdge(T a,T b,T direction)
    {
        //if direction == 1 -> directed graph such that direction is from a to b
        adjencyRepresentation[a].push_back(b);
        if (!direction)
        {
            adjencyRepresentation[b].push_back(a);
        }
        return;
    }
    //now a function to print the adjency list 
    void printGraph()
    {
        for (auto i : adjencyRepresentation)
        {
            cout<<i.first<<" -> ";
            
            for (auto j: i.second)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }  
};
int main()
{

    Graph<int> MyGraph;
    int n;
    cout<<"Enter the number of edges: ";
    cin>>n;
    while(n--)
    {
        int x,y;
        bool dir;
        cout<<"Enter the data: ";
        cin>>x>>y>>dir;
        MyGraph.AddEdge(x,y,dir);
        cout<<endl;
    }    
    MyGraph.printGraph();
    return 1;
}