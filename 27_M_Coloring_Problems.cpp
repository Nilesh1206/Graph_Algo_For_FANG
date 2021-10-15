#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


bool isSafe(int node,int color[],bool graph[101][101],int N,int col)
{
    for(int k=0;k<N;k++)                             // Try for the color for every possible nodes 
    {
        if(k!=N && graph[k][node]==1 && color[k]==col)         // if the k is not equal to N and there is an edge between k to node and 
        {                                                      // color of the k is equal to color of the parent one , then return false
            return false;          
        }
    }
    return true;                                   // Otherwise return true;
}

bool solve(int src,int color[],bool graph[101][101],int m,int N)
{
    if(src==N)                      // We check if the current node is equal to the last node or not
    {
        return true;
    }
    for(int i=1;i<=m;i++)           // Try for every possible color from 1 to m
    {
        if(isSafe(src,color,graph,N,i))                  // if the color for the adjacent node is possible , then
        {
            color[src]=i;                                // mark the color of the respective node is as i
            if(solve(src+1,color,graph,m,N)) return true; // recursively check the color for other nodes by 
            color[src]=0;          // backtracking
        }
    }
    return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int color[V]={0};
    if(solve(0,color,graph,m,V)) return true;
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
/*
Time complexity: O(m^n)
where m-color
      n- number of vertices
*/


// Resursive Solution with same time complexity*/

#include<bits/stdc++.h>
using namespace std;



bool isSafe1(vector<vector<int>>arr,vector<int>color,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j] && color[j]==color[i])
            {
                return false;
            }
        }
    }
    return true;
}


void printSol(vector<int>color)
{
    for(int i=0;i<color.size();i++)
    {
        cout<<" "<<color[i]<<" ";
    }
    cout<<endl;
    return;
}

bool GraphColor(vector<vector<int>>arr,int n,int m,vector<int>color,int src)
{
    if(src==n)
    {
        if(isSafe1(arr,color,n))
        {
            printSol(color);
            return true;
        }
        return false;
    }

    // Try for  every possible next color
    for(int i=1;i<=m;i++)
    {
        color[src]=i;

        if(GraphColor(arr,n,m,color,src+1)==true)
        {
            return true;
        }

        //backtrack
        color[src]=0;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            arr[i][j]=a;
            arr[j][i]=a;
        }
    }
    int m;
    cin>>m;
    vector<int>color(n);
    for(int i=0;i<n;i++)
    {
        color[i]=0;
    }
    if(!GraphColor(arr,n,m,color,0))
    {
        cout<<"Solution doesn't exist..!!"<<endl;
    }
    return 0;
}


/*
Complexity Analysis: 
Time Complexity: O(m^V). 
    There is a total O(m^V) combination of colors. So the time complexity is O(m^V).
Space Complexity: O(V). 
    Recursive Stack of graphColoring(…) function will require O(V) space.
*/



// Effiecient Solution by using bfs


#include<bits/stdc++.h>
using namespace std;

int main()
{
    
}