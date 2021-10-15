// In this program we are going to see the strongly connected graph components

// Kosarajus's Algorithm
















// #include<bits/stdc++.h>
// using namespace std;


// class Graph
// {
//     int V;    // No. of vertices
//     list<int> *adj;    // An array of adjacency lists
  
//     // Fills Stack with vertices (in increasing order of finishing
//     // times). The top element of stack has the maximum finishing 
//     // time
//     void fillOrder(int v, bool visited[], stack<int> &Stack);
  
//     // A recursive function to print DFS starting from v
//     void DFSUtil(int v, bool visited[]);
// public:
//     Graph(int V);
//     void addEdge(int v, int w);
  
//     // The main function that finds and prints strongly connected
//     // components
//     void printSCCs();
  
//     // Function that returns reverse (or transpose) of this graph
//     Graph getTranspose();
// };

// Graph::Graph(int V)
// {
//     this->V = V;
//     adj = new list<int>[V];
// }
  
// // A recursive function to print DFS starting from v
// void Graph::DFSUtil(int v, bool visited[])
// {
//     // Mark the current node as visited and print it
//     visited[v] = true;
//     cout << v << " ";
  
//     // Recur for all the vertices adjacent to this vertex
//     list<int>::iterator i;
//     for (i = adj[v].begin(); i != adj[v].end(); ++i)
//         if (!visited[*i])
//             DFSUtil(*i, visited);
// }

// Graph Graph::getTranspose()
// {
//     Graph g(V);
//     for(int v=0;v<V;v++)
//     {
//         list<int>::iterator it;
//         for(it=adj[v].begin();it!=adj[v].end();++it)
//         {
//             g.adj[*it].push_back(v);
//         }
//     }
//     return g;
// }

// void Graph::addEdge(int v, int w)
// {
//     adj[v].push_back(w); // Add w to v’s list.
// }

// void Graph::fillOrder(int v,bool  visited[],stack<int>&Stack)
// {
//     // Mark the current node as visited and print it
//     visited[v] = true;
  
//     // Recur for all the vertices adjacent to this vertex
//     list<int>::iterator i;
//     for(i = adj[v].begin(); i != adj[v].end(); ++i)
//         if(!visited[*i])
//             fillOrder(*i, visited, Stack);
  
//     // All vertices reachable from v are processed by now, push v 
//     Stack.push(v);
// }

// // The main function that finds and prints all strongly connected 
// // components
// void Graph::printSCCs()
// {
//     stack<int> Stack;
  
//     // Mark all the vertices as not visited (For first DFS)
//     bool *visited = new bool[V];
//     for(int i = 0; i < V; i++)
//         visited[i] = false;
  
//     // Fill vertices in stack according to their finishing times
//     for(int i = 0; i < V; i++)
//         if(visited[i] == false)
//             fillOrder(i, visited, Stack);
  
//     // Create a reversed graph
//     Graph gr = getTranspose();
  
//     // Mark all the vertices as not visited (For second DFS)
//     for(int i = 0; i < V; i++)
//         visited[i] = false;
  
//     // Now process all vertices in order defined by Stack
//     while (Stack.empty() == false)
//     {
//         // Pop a vertex from stack
//         int v = Stack.top();
//         Stack.pop();
  
//         // Print Strongly connected component of the popped vertex
//         if (visited[v] == false)
//         {
//             gr.DFSUtil(v, visited);
//             cout << endl;
//         }
//     }
// }



// int main()
// {
//     Graph g(5);
//     g.addEdge(1, 0);
//     g.addEdge(0, 2);
//     g.addEdge(2, 1);
//     g.addEdge(0, 3);
//     g.addEdge(3, 4);
  
//     cout << "Following are strongly connected components in "
//             "given graph \n";
//     g.printSCCs();
  
//     return 0;
// }





















#include<bits/stdc++.h>
using namespace std;

void topo(int src,vector<int>graph[],vector<int>&visited,stack<int>&st)
{
    visited[src]=1;
    for(auto it:graph[src])
    {
        if(!visited[it])
        {
            topo(it,graph,visited,st);
        }
    }
    st.push(src);
}
void dfs(int src,vector<int>&visited,vector<int>transpose[])
{
    if(visited[src]==1) return;
    visited[src]=1;
    cout<<src<<" ";
    for(auto ele=transpose[src].begin();ele!=transpose[src].end();++ele)
    {
        if(!visited[*ele])
        {
            dfs(*ele,visited,transpose);
        }
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>graph[n];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    

    // Step 1 & 2:  Sort all edges according to their finishing time and apply Topological Sort
    stack<int>st;
    vector<int>visited(n,0);
    for(int i=0;i<n;i++)
    {   
        if(visited[i]==0)
        {
            topo(i,graph,visited,st);
        }
    }

    // Step 3: Transpose the graph
    vector<int>transpose[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        for(auto it:graph[i])
        {
            transpose[it].push_back(i);
        }  
    }


    //Step 4: Do dfs on transpose graph i.e. dfs on original graph by reverse manner
    while(!st.empty())
    {
        int curr=st.top();
        st.pop();
        if(!visited[curr])
        {
            cout<<"SSC: ";
            dfs(curr,visited,transpose);
            cout<<endl;
        }
    }
    return 0;
}