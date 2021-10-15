// In this problem we are going to find the given graph is either eulerian circuit or eulerian path

// Intuition behind this problem is,
//1. First we check the connectivity of all nodes present in the graph
//.....a) Means we apply dfs on graph and check wheather it is connected or not means if any list of node is not 
//      visited then this graph is not eulerian graph
//.....b) After that we count the degree of each node  ..i.e odd gegree means nodes which have odd number of incoming and outgoing edges
//      if odd==0---> Graph is Eulerian Graph (Eulerian Circuit)
//      if odd==1---> Graph is Semi-Eulerain  (Eulerain Path)
//      if odd>2 ---> Not Eulerain Graph


// Eulerian Algorithm

#include<bits/stdc++.h>
using namespace std;


// Simply dfs to check connectivity
void DFS(int src,vector<bool>&visited,vector<int>adj[])
{
    visited[src]=true;
    for(auto it:adj[src])
    {
        if(!visited[it])
        {
            DFS(it,visited,adj);
        }
    }
}



bool Connected_Graph(int n,vector<int>adj[])
{
    vector<bool>visited(n+1,false);
    int node=-1;        //Node to start DFS
    for(int i=0;i<n;i++)
    {
        if(adj[i].size()>0)
        {
            node=i;            //Found a node to start DFS
            break;
        }
    }


    DFS(node,visited,adj);          // Apply dfs to check connectivity


    // Now check all nodes are connected or not 
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && adj[i].size()>0)      // seperate component not visited
        {
            return false;
        }
    }


    return true;                      // all components are connected

}

int find_Euler(int n,vector<int>adj[])
{
    if(!Connected_Graph(n,adj))  //multi-component edged graph
    {                          //All non-zero degree vertices should be connected                	
        return 0;
    }


    //Count odd-degree vertices
	int odd = 0;
	for(int i=0;i<n;++i)
		if(adj[i].size() & 1)
			odd += 1;

	if(odd > 2)	//Only start and end node can have odd degree
		return 0;

	return (odd==0)?2:1;	// 2->Eulerian.......1->Semi-Eulerian.
}

void find_Euler_Path(int n,vector<int>adj[])
{
    int ret=find_Euler(n,adj);
    if(ret==0)               // odd degree>2  or graph is not connected
		cout<<"Graph is NOT a Euler graph\n";
	else if(ret==1)          // Odd degree=1
		cout<<"Graph is Semi-Eulerian (Eulerian Path)\n";
	else                     // Odd degree=0
		cout<<"Graph is Eulerian (Euler circuit)\n";
}

int32_t main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_Euler_Path(n,adj);
    return 0;
}