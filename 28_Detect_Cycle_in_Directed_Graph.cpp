#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    bool dfs(int src,vector<int>&visited,vector<int>&order,vector<int>adj[])
    {
        visited[src]=1;
        order[src]=1;
        for(auto it:adj[src])
        {
            if(!visited[it])
            {
                bool t=dfs(it,visited,order,adj);
                if(t==true)
                {
                    return t;
                }
            }
            else if(order[it])
            {
                return true;
            }
        }
        order[src]=0;
        return false;
    }
    
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<int>visited(V,0);
	   	vector<int>order(V,0);
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(!visited[i])
	   	    {
	   	        bool c=dfs(i,visited,order,adj);
	   	        if(c==true)
	   	        {
	   	            return true;
	   	        }
	   	    }
	   	}
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends