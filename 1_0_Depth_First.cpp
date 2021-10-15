// In this program we are going to find the dfs of a grpah

#include<bits/stdc++.h>
using namespace std;

// class Graph
// {
// public:
//     map<int,bool>visited;
//     map<int,list<int>>adj;
//     void addEdge(int v,int w);
//     void dfs(int s);
// };

// void Graph::addEdge(int u,int v)
// {
//     adj[u].push_back(v);
// }

// void Graph::dfs(int s)
// {
//     if(visited[s]) return;
//     visited[s]=true;
//     cout<<s<<" ";
//     for(auto it=adj[s].begin();it!=adj[s].end();++it)
//     {
//         if(!visited[*it])
//         {
//             dfs(*it);
//         }
//     }
// }

// int main()
// {
//     Graph g;
//     g.addEdge(1,2);
//     g.addEdge(1,4);
//     g.addEdge(2,3);
//     g.addEdge(3,5);
//     g.addEdge(2,5);
//     g.dfs(3);

// }




//Another Method

#include<bits/stdc++.h>
using namespace std;
const int N=100;
vector<int>adj[N];
bool visited[N];

void addEdge(int u,int v)
{
    adj[u].push_back(v);
}



void dfs(int s)
{
    if(visited[s]) return;
    visited[s]=true;
    cout<<s<<" ";
    for(auto it=adj[s].begin();it!=adj[s].end();++it)
    {
        dfs(*it);
    }
}

void InterativeDFS(int s)
{
    vector<bool>visited(N,false);

    stack<int>st;
    st.push(s);
    while(!st.empty())
    {
        auto curr=st.top();
        st.pop();

        if(!visited[curr])
        {
            cout<<curr<<" ";
            visited[curr]=true;
        }
        for(auto it:adj[curr])
        {
            if(!visited[it])
            {
                st.push(it);
            }
        }
    }
}


int32_t main()
{
    int edges;
    cin>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
    }
    cout<<"DFS Traversal-->: ";
    dfs(1);
    cout<<endl;
    cout<<"DFS Interative Traversal--->: ";
    InterativeDFS(1);
    return 0;
}

//Time complexity of the graph dfs is O(v+e)
// Where v-vertices 
// e-edges