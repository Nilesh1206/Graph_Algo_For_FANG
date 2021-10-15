// // variation of bellman ford algorithm


// // Method 1:

// // In this program we are going to find the shotest distance between all nodes from the single soure of node

// #include<bits/stdc++.h>
// using namespace std;

// vector<tuple<int,int,int>>edges;
// const int n=100;
// int dist[n];

// void addEdge(int u,int v,int w)
// {
//     edges.push_back({u,v,w});
// }

// void BellmanFord(int s,int size,int nodes)
// {
//     // Initialises all the points as  -ve infinite 
//     for(int i=1;i<=size;i++)
//     {
//         dist[i]=INT_MIN;
//     }
//     dist[s]=0; // Source point at 0 distance


//     //In this graph each node visited n-1 times , so every iteration it calculate the maximum distance and update it
//     // aslo this graph can help us to find any negative cycle is present or not
//     for(int i=1;i<=size-1;i++)
//     {
//         // int u,v,w;
//         for(auto ele:edges)
//         {
//             int u,v,w;
//             tie(u,v,w)=ele;   // source , target , weight
//             dist[v]=max(dist[v],dist[u]+w);  // Update the distance of target from the source if it is greater 
//         }
//     }
//     cout<<"Below is the  shortest distance of a nodes from the single source of of a node "<<endl;
//     for(int i=0;i<nodes;i++)
//     {
//         // if(i!=s && dist[i]!=INT_MIN)
//         if(i==s) cout<<s<<"-->"<<i<<"="<<INFINITY<<endl;
//         else cout<<s<<"-->"<<i<<"="<<dist[i]<<endl;
//     }
// }


// int main()
// {
//     // int nodes=5;
//     // int edge=7;
//     int nodes;
//     int edge;
//     int src;
//     cin>>nodes>>edge>>src;
//     for(int i=1;i<=edge;i++)
//     {
//         int u,v,w;
//         cin>>u>>v>>w;
//         addEdge(u,v,w);
//     }
//     BellmanFord(src,edge,nodes);
// }


//Method 2:


// By using topological Sorting method


#include<bits/stdc++.h>
using namespace std;
 

vector<int> order;    //to store the ordder of visited vertex

void topo(int src,vector<int> &vis,vector<vector<pair<int,int> > > g){
    vis[src] = 1;       // Mark the current node as visited
    for(auto x:g[src]){  //Adjacent vertices of current node
        if(!vis[x.first])  // x.first is tha node value (vertex value)
            topo(x.first,vis,g);
    }
    order.push_back(src);  // After visiting all childs , push it in vector from back side
}


int32_t main() {
    
    int v,e;
    cin>>v>>e;

    int src;
    cin>>src;

    vector<vector<pair<int,int> > > g(v);
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
    }
    
    vector<int> vis(v,0);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            topo(i,vis,g);                    
        }                                  
    }
    vector<int> dist(v);  // To store the distances of the nodes 
    for(int i=0;i<v;i++) dist[i] = INT_MIN;   // Initialises all the distances as the -Infinite( coz we are finding the maximim distance)
    dist[src] = 0;                      //........ Always source vertex is zero distance from it self
    for(int i=v-1;i>=0;i--){                   // Bcoz of topological sort , vertex appended in vector according to the child i.e. last child goes to the 1st position of the vector
        if(dist[order[i]]!=INT_MIN){           // i.e  startin from source , coz source always on the top of stack
            for(auto x:g[order[i]]){           // adjacent of source
                int v = dist[x.first];   // x.first is tha node value (vertex value), previously store value of that node
                //cout<<"What is: "<<x.first<<endl;
                //cout<<"What is 1: "<<x.second<<endl;
                int w = x.second;        // x.second is the weight value of that vertex 
                int u = dist[order[i]];  // sorce distance 
                if(u + w > v)
                    dist[x.first] = u + w;    //Append new distance 
            }
        }
    }

    cout<<"Below is the maximum distance from the sorce vertex: "<<endl;
    for(int i=0;i<v;i++){
        if(i!=src and dist[i]!=INT_MIN){
            cout<<src<<" -> "<<i<<" = "<<dist[i]<<endl;
        }
        if(i!=src and dist[i]==INT_MIN){
            cout<<src<<" -> "<<i<<" = "<<INFINITY<<endl;
        }
        if(i==src)
        {
            cout<<src<<" -> "<<i<<" = "<<0<<endl;
        }
    }
    
    return 0;

}