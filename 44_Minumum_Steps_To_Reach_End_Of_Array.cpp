/*
Given an array containing one digit numbers only, assuming we are standing at first index,
we need to reach to end of array using minimum number of steps where in one step, we can 
jump to neighbor indices or can jump to a position with same value.
In other words, if we are at index i, then in one step you can reach to, arr[i-1] or arr[i+1] 
or arr[K] such that arr[K] = arr[i] (value of arr[K] is same as arr[i])
Examples: 
 

Input : arr[] = {5, 4, 2, 5, 0}
Output : 2
Explanation : Total 2 step required.
We start from 5(0), in first step jump to next 5 
and in second step we move to value 0 (End of arr[]).

Input  : arr[] = [0, 1, 2, 3, 4, 5, 6, 7, 5, 4,
                 3, 6, 0, 1, 2, 3, 4, 5, 7]
Output : 5
Explanation : Total 5 step required.
0(0) -> 0(12) -> 6(11) -> 6(6) -> 7(7) ->
(18)                                                          
(inside parenthesis indices are shown)
*/

#include<bits/stdc++.h>
using namespace std;

int Solve(vector<int>&res,int n)
{
    // To store the distance of each visited nodes
    int dist[n];

    // To keep track of visited nodes , so no visiting nodes again
    vector<bool>visited(n,false);

    // to create graph 
    // where each node has edge previous , next and the position with same occurance
    vector<int>graph[n];

    // Adding edges
    for(int i=1;i<n;i++)
    {
        graph[res[i]].push_back(i);
    }

    // 0th indes has 0 distance
    dist[0]=0;

    // Mark the 0th index as true
    visited[0]=true;


    // Creating a queue starting with 0 index
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        auto ele=q.front();
        q.pop();


        // if we reach the last index
        if(ele==n-1)
        {
            break;
        }

        // finding the value of dequed index
        int d=res[ele];


        // looping for all indices with value as d
        for(auto it:graph[d])
        {
            // If not visited then explore it
            if(!visited[it])
            {
                visited[it]=true;
                dist[it]=dist[ele]+1;
                q.push(it);
            }
        }

        // clear all indices for digit d, because all
        // of them are processed 
        graph[d].clear();


        // Checking condition for previous index
        if(ele-1>=0 && !visited[ele-1])
        {
            visited[ele-1]=true;
            q.push(ele-1);
            dist[ele-1]=dist[ele]+1;
        }


        // Checking condition for next index
        if(ele+1<n && !visited[ele+1])
        {
            visited[ele+1]=true;
            q.push(ele+1);
            dist[ele+1]=dist[ele]+1;
        }
    }


    // N-1 the position has final result
    return dist[n-1];
}

int main()
{
    vector<int>res;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        res.push_back(a);
    }
    cout<<"Minimum Steps to reach the end of array: "<<Solve(res,n)<<endl;
    return 0;
}