// bridge in graph, returns the edges whic are bridges in the grven graph
#include <bits/stdc++.h>
using namespace std;
void getAdjList(vector<int> adj[], vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void dfs(int x, int foundAt, vector<int> adj[], vector<bool> &visited, vector<int> &discoveredAt, vector<int> &parent, vector<int> &low, vector<vector<int>> &ans)
{
    visited[x] = true;
    discoveredAt[x] = foundAt;
    low[x] = foundAt;
    for (auto i : adj[x])
    {
        if (i == parent[x])
            continue;
        if (!visited[i])
        {
            parent[i] = x;
            dfs(i, foundAt + 1, adj, visited, discoveredAt, parent, low, ans);
            // when we return we must update the low of the node from the dfs so
            low[x] = min(low[x], low[i]);
            // main condition for the presece of the edge!
            if (low[i] > discoveredAt[x])
            {
                vector<int> temp;
                temp.push_back(x);
                temp.push_back(i);
                ans.push_back(temp);
            }
        }
        else
        {
            // visited bhi hai and parent bhi nai, ooo backEdge
            low[x] = min(low[x], discoveredAt[i]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // get the adjency  matrix
    vector<int> adj[v];
    getAdjList(adj, edges);
    // we have the usable adjency list in the hand now!
    vector<vector<int>> ans;
    int foundAt = 0;
    vector<int> low(v, -1);
    vector<int> discoveredAt(v, -1);
    vector<int> parent(v, -1); // not needed as of now but anyways
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, foundAt, adj, visited, discoveredAt, parent, low, ans); // sheeeeeesh
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> edges;
    int v;
    cout<<"Enter the number of vertices: ";
    cin>> v ;
    int e;
    cout<< "Enter the number of edges: ";
    cin>>e;
    for (int i=0;i<e;i++)
    {
        int e1;
        int e2;
        cin>>e1>>e2;
        vector<int> tempEdge;
        tempEdge.push_back(e1);
        tempEdge.push_back(e2);
        edges.push_back(tempEdge);
    }
    vector<vector<int>> ans = findBridges(edges,v,e);
    sort(ans.begin(),ans.end());
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i][0]<<"-----"<<ans[i][1]<<endl;
    }
}000