// // In this program we are going to find the brideges in the graph so that after removing them graph , should be disconnected

// #include<bits/stdc++.h>
// using namespace std;

// void dfs(int src,vector<vector<int>>graph , int *disc,int *low, int *parent,vector<pair<int,int>>&bridges)
// {
//     static int time=0 ; 
//     disc[src]=low[src]=time++;
//     vector<int>::iterator it;
//     for(it=graph[src].begin();it!=graph[src].end();it++)
//     {
//         if(disc[*it]==-1)                               // if not visited
//         {
//             parent[*it]=src;                           // mark the parent of it as src
//             dfs(*it,graph,disc,low,parent,bridges);
//             low[src]=min(low[src],low[*it]);          // update the low of src with help of child
//             if(low[*it]>disc[src])                    // means there is no any connectrvity between this node and any other node
//             {
//                 bridges.push_back(make_pair(src,*it));
//             }
//         }
//         else if(parent[src]!=*it)                      // check wheater parent of src if child or not means via in cycle, then update the low of src        
//         {
//             low[src]=min(low[src],disc[*it]);
//         }
//     }
// }

// void bridge(vector<vector<int>>graph)
// {
//     int n=graph.size();
//     int disc[n],low[n],parent[n];
//     for(int i=0;i<n;i++)
//     {
//         disc[i]=low[i]=parent[i]=-1;
//     }
//     vector<pair<int,int>>bridges;
//     for(int i=0;i<n;i++)
//     {
//         if(disc[i]==-1)
//         {
//             dfs(i,graph,disc,low,parent,bridges);
//         }
//     }
//     for(int i=0;i<bridges.size();i++)
//     {
//         cout<<bridges[i].first<<" - "<<bridges[i].second<<endl;
//     }
// }

// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>>graph(n);
//     for(int i=0;i<m;i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         graph[u].push_back(v);
//         graph[v].push_back(u);
//     }
//     bridge(graph);
//     return 0;
// }

















// Effiecient


#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[]) {
    vis[node] = 1; 
    tin[node] = low[node] = timer++; 
    for(auto it: adj[node]) {
        if(it == parent) continue;
        
        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj); 
            low[node] = min(low[node], low[it]); 
            if(low[it] > tin[node]) {
                cout << node << " " << it << endl;
            }
        } else {
            low[node] = min(low[node], tin[it]); 
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n+1]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n+1, -1);
	vector<int> low(n+1, -1); 
	vector<int> vis(n+1, 0); 
	int timer = 0; 
    cout<<endl;
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj); 
	    }
	}
	
	return 0;
}
































// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;

// void dfs_bridges(int src, vector<vector<int> > al, int *disc, int *low, int *parent,  vector<pair<int,int> > &bridges){
//     static int time=0;
//     disc[src]=low[src]=time++;
//     vector<int> :: iterator itr;
//     for(itr=al[src].begin();itr!=al[src].end();itr++){
//         if(disc[*itr]==-1){
//             parent[*itr]=src;
//             dfs_bridges(*itr, al, disc, low, parent,bridges);
//             low[src]=min(low[src],low[*itr]);
//             if(low[*itr]>disc[src]){
//                 bridges.push_back(make_pair(src, *itr));
//             }
//         }
//         else if(parent[src]!=*itr){
//             low[src]=min(low[src],disc[*itr]);
//         }
//     }
// }
// void bridges(vector<vector<int> > al){
//     int v = al.size(), i;
//     int disc[v], low[v] ,parent[v];
//     for(i=0;i<v;i++){
//         disc[i]=low[i]=parent[i]=-1;
//     }
//     vector<pair<int,int> > bridges;
//     for(i=0;i<v;i++){
//         if(disc[i]==-1)dfs_bridges(i, al, disc, low, parent,bridges);
//     }
//     for(i=0;i<bridges.size();i++){
//       cout<<bridges[i].first << " - "<<bridges[i].second<<endl;
//     }
// }

// int main(){
//     int v, e , i, src, dest;
//     cin >> v>>e;
//     vector<vector<int> > al(v);
//     for(i=0;i<e;i++){
//         cin >> src >> dest;
//         al[src].push_back(dest);
//         al[dest].push_back(src);
//     }
//     bridges(al);
//     return 0;
// }
