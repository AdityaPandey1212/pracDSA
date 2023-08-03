// C++ program to print all the cycles
// in an undirected graph
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;


// variables to be used
// in both functions
vector<int> graph[N];
vector<vector<int>> cycles;

// Function to mark the vertex with
// different colors for different cycles
void dfs_cycle(int u, int p, int color[], int par[], int &cyclenumber)
{

    // already (completely) visited vertex.
    if (color[u] == 2)
    {
        return;
    }

    // seen vertex, but was not completely visited -> cycle detected.
    // backtrack based on parents to find the complete cycle.
    if (color[u] == 1)
    {
        vector<int> v;
        cyclenumber++;

        int cur = p;
        v.push_back(cur);

        // backtrack the vertex which are
        // in the current cycle thats found
        while (cur != u)
        {
            cur = par[cur];
            v.push_back(cur);
        }
        cycles.push_back(v);
        return;
    }
    par[u] = p;

    // partially visited.
    color[u] = 1;

    // simple dfs on graph
    for (int v : graph[u])
    {

        // if it has not been visited previously
        if (v == par[u])
        {
            continue;
        }
        dfs_cycle(v, u, color, par, cyclenumber);
    }

    // completely visited.
    color[u] = 2;
}

// add the edges to the graph
void addEdge(int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

// Function to print the cycles
void printCycles(int &cyclenumber)
{

    // print all the vertex with same cycle
    for (int i = 0; i < cyclenumber; i++)
    {
        // Print the i-th cycle
        cout << "Cycle Number " << i + 1 << ": ";
        for (int x : cycles[i])
            cout << x << " ";
        cout << endl;
    }
}

// C++ program to print all paths
// from a source to destination.
#include <iostream>
#include <list>
using namespace std;
 
// A directed graph using
// adjacency list representation
class Graph {
    int V; // No. of vertices in graph
    list<int>* adj; // Pointer to an array containing
                    // adjacency lists
 
    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int, int, bool[], int[], int&);
 
public:
    Graph(int V); // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add v to u’s list.
}
 
// Prints all paths from 's' to 'd'
void Graph::printAllPaths(int s, int d)
{
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
 
    // Create an array to store paths
    int* path = new int[V];
    int path_index = 0; // Initialize path[] as empty
 
    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index);
}
 
// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int& path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;
 
    // If current vertex is same as destination, then print
    // current path[]
    if (u == d) {
        for (int i = 0; i < path_index; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current
        // vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path,
                                  path_index);
    }
 
    // Remove current vertex from path[] and mark it as
    // unvisited
    path_index--;
    visited[u] = false;
}
 
// Driver Code
int main()
{

    // add edges
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 6);
    addEdge(4, 7);
    addEdge(5, 6);
    addEdge(3, 5);
    addEdge(7, 8);
    addEdge(6, 10);
    addEdge(5, 9);
    addEdge(10, 9);
    addEdge(10, 11);
    addEdge(11, 12);
    addEdge(11, 13);
    addEdge(12, 13);

    // arrays required to color the
    // graph, store the parent of node
    int color[N];
    int par[N];

    // store the numbers of cycle
    int cyclenumber = 0;
    int edges = 6;

    // call DFS to mark the cycles
    dfs_cycle(1, 0, color, par, cyclenumber);


    // function to print the cycles
    if (cyclenumber == 0)
    {
        cout << "The number of cycles present in the given graph: " << cyclenumber;
    }
   for (int i=1;i<13;i++)
    {
        g.printAllPaths(s, d);
    }
}