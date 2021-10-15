// In this program we are going to  traverse the breadth first traversal of a graph

#include<bits/stdc++.h>
using namespace std;


const int N=1e5;
queue<int>q;
int dist[N];
bool visited[N];
vector<int>adj[N];

void addEdge(int u,int v)
{
    adj[u].push_back(v);
}

void bfs(int s,int edges)
{
    visited[s]=true;
    dist[s]=0;
    q.push(s);
    cout<<endl;
    cout<<"Distances of nodes from the source point (minimum number of edges source to destination): "<<endl;
    cout<<"Vertex  Distance "<<endl;
    while(!q.empty())
    {
        int it=q.front();q.pop();
        cout<<it<<"        "<<dist[it]<<endl;
        for(auto ele:adj[it])
        {
            if(visited[ele])
            {
                continue;
            }
            else
            {
                visited[ele]=true;
                dist[ele]=dist[it]+1;
                q.push(ele);
            }
        }
    }
}
int edges;

int32_t main()
{
    cin>>edges;
    for(int i=1;i<=edges;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
    }
    bfs(1,edges);
}

// Time complexity of bfs - O(v+e)  in adjacency list
// Time complexity of bfs - O(v^2) in adjacency matrix
/*
V * (O(1) + O(Eaj) + O(1))
V + V * Eaj + V
2V + E(total number of edges in graph)
V + E
*/