#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void DFS(int x, vector<int> &visited, vector<int> adj[])
    {
        visited[x] = 1;
        for (auto a : adj[x])
        {
            if (!visited[a])
            {
                DFS(a, visited, adj);
            }
        }
        return;
    }
    void dfs(int x, vector<int> &visited, stack<int> &store, vector<int> adj[])
    {
        visited[x] = 1;

        for (auto i : adj[x])
        {
            if (!visited[i])
            {
                dfs(i, visited, store, adj);
            }
        }
        store.push(x);
        return;
    }
    void topo(int n, vector<int> adj[], stack<int> &store)
    {
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                dfs(i, visited, store, adj);
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<int> adj[])
    {
        // steps involved
        /*
            1->get the tropological sort, doesnt matter if its valid or not really
            2->get the transpose
            3->do dfs in tropogogical sort manner toget the components
        */
        stack<int> store;
        topo(n, adj, store);
        // now vector topological contains the elements and we now may go on with the transpose
        vector<int> transpose[n];
        for (int i = 0; i < n; i++)
        {
            for (auto neighbour : adj[i])
            {
                transpose[neighbour].push_back(i);
            }
        }
        vector<int> visited(n, 0);
        int count = 0;
        // now just apply dfs on the above transpose list
        while (!store.empty())
        {
            int node = store.top();
            store.pop();
            if (!visited[node])
            {
                DFS(node, visited, transpose);
                count++;
            }
        }
        return count;
    }
};
