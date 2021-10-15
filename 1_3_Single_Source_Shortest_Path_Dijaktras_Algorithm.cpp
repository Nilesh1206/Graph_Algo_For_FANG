// In this program we are going to find the shortest distances of each nodes form the source point

#include<bits/stdc++.h>
using namespace std;



const int N=100;
vector<pair<int,int>>adj[N];
int dist[N];
priority_queue<pair<int,int>>pq;
bool visited[N];

int nodes;
int edges;


void addEdge(int u,int v,int w)
{
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}


void Dijaktras(int s)
{
    for(int i=0;i<=nodes;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        int u=pq.top().second;pq.pop();
        if(visited[u]) continue;
        else
        {
        visited[u]=true;
        for(auto ele:adj[u])
        {
            int v=ele.first,w=ele.second;
            if(dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
                pq.push({-dist[v],v});
            }
            
        }
        }
    }


    cout<<"Distances of nodes from the source node are : "<<endl;
    cout<<"Source node is: "<<s<<endl;
    for(int i=0;i<=nodes;i++)
    {
        cout<<i<<"   "<<dist[i]<<endl;
    }
}

int main()
{
    // nodes=6;
    // edges=8;
    cout<<"Enter number of vertex and edges: ";
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(u,v,w);
    }
    Dijaktras(1);
}

/*
The time complexity of the above implementation is O(n+ mlogm), because
the algorithm goes through all nodes of the graph and adds for each edge at most
one distance to the priority queue
Here: mlogm for adding the each edge in to the priority_queue at most once
*/