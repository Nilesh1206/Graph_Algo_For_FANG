// In this problem we are going to find the all possible paths from the source vertex to the destination
// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1, 
//                 and return them in any order.
//The graph is given as follows: graph[i] is a list of all nodes you can visit from node i 
//(i.e., there is a directed edge from node i to node graph[i][j]).


//Remember one thing, it is a DAG(Directed Acyclic Graph) so there no worry about cycle formation, also TLE
#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>&graph,vector<vector<int>>&result,vector<int>&paths,int src,int destn)
{
    paths.push_back(src);                                 // Pushing the src into the temporary path , for checking path is possible or not
    if(src==destn) result.push_back(paths);      // If the current node becomes the last node of graph/destination i.e graph.size()-1 
                                                // Then push the path into the resultant path (valid path)
    else
        for(int ele:graph[src])
            dfs(graph,result,paths,ele,destn);        // Recursively checking the paths to the last node
    paths.pop_back();                           // If path  is not present from the current source to last node , then pop the element,
                                                //  (i.e lastly pushed element is not valid ) , so we can check other vertex.
}


vector<vector<int>> allPossiblePath(vector<vector<int>>&graph,int src,int destn)
{
    vector<vector<int>>result;
    vector<int>paths;
    dfs(graph,result,paths,src,destn);
    cout<<result.size()<<endl;
    return result;
}


int32_t main()
{
    int v,e,src,destn;
    cin>>v>>e>>src>>destn;
    vector<vector<int>>graph(v);
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    //destn=graph.size()-1;

    vector<vector<int>>path=allPossiblePath(graph,src,destn);
    cout<<"Resultant Paths From source to Destination are: "<<endl;
    for(auto ele:path)
    {
        for(auto it:ele)
        {
            if(it==destn)
            {
                cout<<it;
            }
            else cout<<it<<"-->";
        }
        cout<<endl;
    }

}















// Alternative 
//total path b/w the two vertix
//the graph will be acyclic
#include <bits/stdc++.h>
using namespace std;

void addedge(list<int>l[],int u,int v){
    l[u].push_back(v);
}

int ct=0;
int total_path(list<int>l[],vector<int>visit,int s,int e,int v){

    visit[s]=1;
    for(auto x: l[s]){
            if(x==e)
             ct+=1;
        if(visit[x]==0){
        total_path(l,visit,x,e,v);
        }
    }
}
// Time Complexity : Exponential

int main(){
     int v=5;
     list<int> l[v];
     vector<int>visit(v,0);
    addedge(l,0, 1);
    addedge(l,0, 4);
    addedge(l,0, 3);
    addedge(l,1, 3);
    addedge(l,1, 2);
    addedge(l,2, 3);
    addedge(l,3, 4);
    addedge(l,1, 4);
    addedge(l,2, 4);
    addedge(l,0, 2);
    total_path(l,visit,0,4,v);
    cout<<ct;
}