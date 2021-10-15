// In this program we are going to find the cut-vertex point so that graph becomes disconnected

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mxsize=1e6+6;


int parent[mxsize];
int child[mxsize];
int tym[mxsize];
int low[mxsize];
bool seen[mxsize];
bool is_cut[mxsize];

//vector<vector<int>>vertex;
void dfs(int src,vector<vector<int>>&graph)
{
    /* static variable gets declared only  
    once till the program runs */
    static int time=0;
    seen[src]=true;          // mark the source as visited

    low[src]=tym[src]=time++;            // irst assigns and then increment time.

    for(int i=0;i<graph[src].size();i++)
    {
        int it=graph[src][i];
        if(it==parent[src])
        {
            continue;                    //do nothing if adjacent  is its parent
        }
        if(!seen[it])
        {
            child[src]++;                  // one more independent child of source
            parent[it]=src;               // make the parent src for  adjacent  element
            dfs(it,graph);


            /*
            if the low time of oldest ancestor reachable from the both , then  
            */
           low[src]=min(low[src],low[it]);
           /* if it has greater or equal  
            low time than visited time of src then if we cut src then 
            curr will get disconnected from the graph*/
            if(low[it]>=tym[src])
            {
                is_cut[src]=true;
            }
            
        }
        else
        {
            low[src]=min(low[src],tym[it]);
        }

    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n+1,vector<int>(m+1));
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    parent[1]=-1;
    dfs(0,graph);

    /* the vertex from where we started dfs 
         must have atleast two independent children  
         otherwise it is not a cut vertex  */ 
      is_cut[0]= child[0]>1 ? true : false;  
 
 
      for(int i=0;i<n;i++) 
      { 
        if(is_cut[i]) 
          cout<<i<<" is cut vertex"<<endl; 
      } 
      return 0;
}