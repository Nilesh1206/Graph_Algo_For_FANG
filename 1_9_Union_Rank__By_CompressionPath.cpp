// In this problem we are going to find the rank of the nodes , taking the union of nodes, and doing the 
// path compression


// Tarjans Algorithm

#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int rankN[100000];

void makeset(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        rankN[i]=0;
    }
}

int FindParent(int node)
{
    // if node itself is parent 
    if(node==parent[node])
    {
        return node;
    }

    // else by using path compression find the parent
    // like 7-->6-->4-->3 ; so parent of 7 is 3 with the help of path compression
    // look like 7--->3
    // look like 6--->3;
    // look like 4--->3;
    // Update the parent of node and return
    return parent[node]=FindParent(parent[node]);

    // It will store the parent by using path compression
}


void Union(int u,int v)
{
    // Find the parent to union the nodes
    u=FindParent(u);
    v=FindParent(v);


    // If rank of u is less than rank of v, then we set the parent of node u is v
    if(rankN[u]<rankN[v])
    {
        parent[u]=v;
    }

    // If rank of node v is less than u , then we can set the parent of node v is u
    else if(rankN[v]<rankN[u])
    {
        parent[v]=u;
    }

    // else if the rank of both node are same , then we can eithe set the parent of node u is v
    // or we can set the parent of node v is u , and increasing the rank of parent 
    else
    {
        parent[v]=u;
        rankN[u]++;
    }
}

int main()
{
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    makeset(n);
    int m;
    cin>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    int q;
    cout<<"Enter number of queries: ";
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(FindParent(a)!=FindParent(b))
        {
            cout<<"Both nodes belongs to different component..!!"<<endl;
        }
        else
        {
            cout<<"Both nodes belongs to same components...!!!"<<endl;
        }
    }

    return 0;

}