// #include <bits/stdc++.h>
// using namespace std;
// int dp[11][1<<11];
// bool solve(vector<vector<int>> &graph,int node,int visited,int allVisited)
// {
//     if(visited==allVisited)
//     {
//         // if we want to check for hamiltonian cycle then we add one more condition to check if there exist a path between node and source
//         return true;
//     }
//     if(dp[node][visited]!=-1)
//         return dp[node][visited];
    
//     int v = graph.size();
    
    
//     for(int i=0;i<v;i++)
//     {
//         if((visited&(1<<i)) == 0 && graph[node][i])
//         {
//             if(solve(graph,i,(visited|(1<<i)),allVisited))
//                 return dp[node][visited]=true;
//         }
        
//     }
    
//     return dp[node][visited] = false;

    
// }

// int main() {
    
//     memset(dp,-1,sizeof dp);
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> graph(n,vector<int>(n));
//     for(int i=0;i<m;i++)
//     {
//         int from,to;
//         cin>>from>>to;
//         graph[from-1][to-1] = 1;
//         graph[to-1][from-1] = 1;
//     }
//     int allvisited = (1<<n)-1;

    
//     bool flag = false;
//     for(int i=0;i<n;i++)
//     {
//         // marking node i as visited and cheking if hamiltonian path starts from i
//         if(solve(graph,i,1<<i,allvisited))
//         {
//             flag = true;
//             break;

//         }

//     }

//     if(flag==true)
//         cout<<true<<endl;
//     else
//         cout<<false<<endl;

// 	return 0;
// }

#include<bits/stdc++.h>
using namespace std;
bool flag=false;

void nextVertex(int src,vector<vector<int>>&graph,int n,int visited[])
{
    do
    {
        visited[src]=(visited[src]+1)%(n+1);              // Update the source value in visited array by incrementing 1 , so it means
                                                          // there is no any pre index/vertex which have already visited/store this value
                                                          // if such case happen then return and check for next value which is not included in visited array
        if(visited[src]==0) return;       
        // means this value is for starting vertex , check for next one

        // if we add source to the aaray then, it must have edge between them                
        if(graph[visited[src]-1][visited[src-1]-1]==1)
        {
            int j=0;
            for(j=0;j<src;j++)
            {
                if(visited[j]==visited[src])
                {
                    break;
                }
            }
            if(j==src)
            {
                //if source becomes last nodes , then check if there is edge between last node and starting node
                if(src+1<n || src+1==n && graph[visited[n-1]-1][visited[0]-1]==1)
                {
                    return;
                }
            }
        }
    }while(true);
}


// Utility function to find the hamiltonian cycle
void hamCycle(vector<vector<int>>&graph,int src,int visited[],int n)
{
    // We iterate every vertex , and checking is there is any cycle present or not 
    do
    {
        nextVertex(src,graph,n,visited);            // To check the if cycle is present or not for every next vetex of graph, simultaneously 
                                                    // we update the values in visited array
        if(visited[src]==0) return;                 // if there is not such path exist
        if(src+1==n)                                // If we visited  all the nodes , with all the conditions , then there is hamiltonian cycle
        {                                           // and we can print it
            for(int i=0;i<n;i++)
            {
                cout<<visited[i]-1<<" ";
            }
            cout<<visited[0]-1;
            cout<<endl;
            flag=true;
        }
        else                                        // else then check for the next vertex
        {
            hamCycle(graph,src+1,visited,n);
        }
    }while(true);
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n+1,vector<int>(m+1,0));           // Created a adjacency matrix
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    int *visited = new int[sizeof(graph)];                 // Create one array to store the hamiltonian cycle path
    visited[0]=1;                                          // mark the starting vertex as 1 
    hamCycle(graph,1,visited,n);
    cout<<flag<<endl;
    if(flag==false)
    {
        cout<<"there is no halmitiation cycle exist..!!"<<endl;
    }
}

/*
Time cimplexity of the above solution is: O(n!)
It try all the possible combination , hence if the no of vertexes are n the the no of possible combination are n!

n! = O( n ^ n )
*/