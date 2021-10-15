// In this probelm we are going to implement the efficient method of prims algo
#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    vector<pair<int,int>>adj[nodes];
    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    int src;
    cin>>src;
    int key[nodes];
    int parent[nodes];
    bool mstSet[nodes];
    for(int i=0;i<nodes;i++)
    {
        key[i]=INF; mstSet[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        mstSet[u]=true;
        for(auto it:adj[u])
        {
            int v=it.first;
            int weight=it.second;
            if(mstSet[v]==false && weight<key[v])
            {
                key[v]=weight;
                parent[v]=u;
                pq.push({key[v],v});
            }
        }
    }
    // cout<<"Veertex   Parent   Distance"<<endl;
    // for(int i=0;i<nodes;i++)
    // {
    //     cout<<i<<"         "<<parent[i]<<"          "<<key[i]<<endl;
    // }
    int sum=0;
    for(int i=0;i<nodes;i++)
    {
        if(key[i]!=INF)
        {
            sum+=key[i];
        }
    }
    cout<<sum<<endl;
    //cout<<"Minimum Spanning Weight is: "<<sum<<endl;
    return 0;
}

/*
Time complexity of the above graph is O(ElogV)  we have uses binary heap
other wise nieve algo gives O(n^2)
*/