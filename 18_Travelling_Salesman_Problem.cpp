// In this program we are going to find the minimum weight of hamiltonian cycle ..means travelling
// salesman probelem


// See Second Solution


#include<bits/stdc++.h>
using namespace std;
int dp[101][101];

class Solution
{
    int visited_all;         // total number of cities i.e. mask 1111...n;
public:
    void set(int n)
    {
        visited_all=(1<<n)-1;
    }
    int tsp(vector<vector<int>>&graph,int n,int mask,int pos)
    {
        if(mask==visited_all)
        {
            return graph[pos][0];
        }
        if(dp[mask][pos]!=-1)
        {
            return dp[mask][pos];
        }

        // now from the current node we trying to visited all the possible nodes and take the min weight
        // from visited nodes
        int ans=INT_MAX;                // because we want minimum weight
        
        // Iterate to all possible cities
        for(int city=0;city<n;city++)
        {
            if((mask&(1<<city))==0)              // means we are visiting those cities , which are not visited
            {                                   // means 001&(1<<0) == (001&010) == 000 i.e 1st city is not visited
                
                int newDist=graph[pos][city]+tsp(graph,n,(mask|(1<<city)),city);
                // here if city is not visited , then we are storing the current branch weight in one variable
                // and we recursively iterate to the next city by using bitmask
                // like mask|(1<<city)== 001|(1<<0) ==(001|010) == 011 
                // and again we checking 2nd city is visited or not  and so on...

                ans=min(ans,newDist);        //strong the minimum distance of current branch
            }
        }
        return dp[mask][pos]=ans;               // storing the ans and returning it.

    }
};

/*
Time complexity is O(n^2 * 2 ^ n) as we are filling each value in the dp table and to 
compute the optimal value for each cell in dp table we are traversing to all 
possible next cities which are n.
*/

int main()
{
    memset(dp,-1,sizeof(dp));
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>graph[i][j];
            //graph[j][i]=graph[i][j];
        }
    }
    Solution obj;
    obj.set(n);
    cout<<"Minimum distance visited to all cities is: ";
    cout<<obj.tsp(graph,n,1,0);
    return 0;

}



















#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long

int dp[501][501];
class Solution1
{
    int visited_all;
public:
    // void makeset(int n)
    // {
    //     this->visited_all=(1<<n)-1;
    // }
    Solution1(int n)
    {
        this->visited_all=(1<<n)-1;
    }
    int tsp(vector<vector<int>>&graph,int n,int mask,int pos)
    {
        if(mask==visited_all)
        {
            return graph[pos][0];
        }

        if(dp[mask][pos]!=-1)
        {
            return dp[mask][pos];
        }

        // We are going to find the minimum weight
        int ans=INT_MAX;

        // Iterate each city
        for(int city=0;city<n;city++)
        {
            // If city is not visited
            if((mask&(1<<city))==0)
            {
                int newDist=graph[pos][city]+tsp(graph,n,(mask|(1<<city)),city);

                ans=min(ans,newDist);
            }

        }
        return dp[mask][pos]=ans;
    }
};

  
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n,vector<int>(n,0));
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        graph[u][v]=w;
        graph[v][u]=w;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }


    Solution1 obj(n);
    // memset(dp,-1,sizeof(dp));
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<obj.tsp(graph,n,1,0)<<endl;
    return 0;
}


