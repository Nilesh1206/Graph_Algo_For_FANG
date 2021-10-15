
#include<bits/stdc++.h>
using namespace std;
int graph[100][100],n,m,dp[105][105],V;

int shortestPath(int v,int k)
{
    // base condition
    // If current node is destination node and path length is 0
    if(v==V && k==0)
    {
        return dp[v][k]=0;
    }

    // if current node is not destionation node but the path length is the 0
    else if(k==0)
    {
        return 100000000;
    }

    else if(dp[v][k]!=100000000)
    {
        return dp[v][k];
    }

    // otherwise
    else
    {
        int ans=100000000;
        int mn=0;
        // Find the shortest path children node with 
        // k-1 length and choose the minimum one
        for(int i=1;i<=n;i++)
        {
            if(graph[v][i]!=100000000)
            {
                int p=shortestPath(i,k-1);
                if(ans>p+graph[v][i])
                {
                    ans=graph[v][i]+p;
                }
            }
        }
        return dp[v][k]=ans;
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            graph[i][j]=100000000;
            dp[i][j]=100000000;
        }  
    }

    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        graph[a][b]=c;
    }
    int u,k;
    cin>>u>>V>>k;
    graph[0][u]=0;
    cout<<shortestPath(u,k)<<endl;
    return 0;

}
