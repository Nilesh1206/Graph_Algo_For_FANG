// In this problem we are going to apply topological sort on graph elements

#include<bits/stdc++.h>
using namespace std;


void topologicalSortDFS(vector<vector<int>> &graph,int src,vector<bool> &visited,vector<int>&ans)
{
    // if(!visited[src])
    // {
        visited[src]=true;
        for(auto it=graph[src].begin();it!=graph[src].end();it++)
        {
            if(!visited[*it])
                topologicalSortDFS(graph,*it,visited,ans);
        }
        //topologicalSortedList.push_front(src);
        ans.push_back(src);
    //}
}


vector<int> tSort(vector<vector<int>> &graph)
{
    //list<int>topologicalSortedList;
    vector<int>ans;
    vector<bool>visited(graph.size(),false);
    for(int src=0;src<graph.size();src++)
    {
        if(visited[src]==false)
            topologicalSortDFS(graph,src,visited,ans);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    //return topologicalSortedList;
}


int main()
{
    vector<vector<int>>graph; // similar to  vector<list<int>>graph
    int n,e;
    cin>>n>>e;
    graph.resize(n);
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        //graph[v].push_back(u);
    }
    vector<int>List=tSort(graph);
    for(auto it=List.begin();it!=List.end();++it)
    {
        cout<<*it<<" ";
    }
    return 0;
}

// Time complexity : O(v+e) , simply uses dfs
// Space complexity : O(v), All nodes are stores in the stack





// #include<iostream>
// #include<vector>
// #include<list>
// using namespace std;

// void topologicalSortDFS(vector<list<int>> graph,int src,vector<bool> &visited,list<int> &topologicalSortedList){
//     if(!visited[src]){
//         visited[src] = true;
//         for(list<int>::iterator itr = graph[src].begin();itr != graph[src].end();itr++){
//             topologicalSortDFS(graph,*itr,visited,topologicalSortedList);
//         }
//         topologicalSortedList.push_front(src);
//     }
// }

// list<int> topologicalSort(vector<list<int>> graph){
//     list<int> topologicalSortedList;
//     vector<bool> visited(graph.size(),false);
//     for(int src = 0; src < graph.size();src++){
//         topologicalSortDFS(graph,src,visited,topologicalSortedList);
//     }
//     return topologicalSortedList;
// }

// int main(){
//     vector<list<int>> graph;
//     int v,e,src,des;
//     cin >> v >> e;
//     graph.resize(v);
//     while(e--){
//         cin >> src >> des;
//         graph[src].push_back(des);
//     }
//     list<int> topologicalSortedList = topologicalSort(graph);
//     for(list<int>::iterator itr = topologicalSortedList.begin();itr!=topologicalSortedList.end();itr++){
//         cout << *itr << " ";
//     }
//     return 0;
// }