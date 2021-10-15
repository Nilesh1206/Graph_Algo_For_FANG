
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll m,n,d;
queue<pair<ll,ll>>q;
map<pair<ll,ll>,ll>visited;
vector<pair<ll,ll>>res;

void BFS(pair<ll,ll> p,ll goal)
{
    ll x=p.first;
    ll y=p.second;

    q.pop();
    res.push_back({x,y});
    if(x==d || y==d)
    {
        pair<ll,ll>p;
        if(x==d)
        {
            p={d,0ll};
            res.push_back({d,0ll});
        }
        else if(y==d)
        {
            p={0ll,d};
            res.push_back({0ll,d});
        }
        visited[p]=1;
        q.push(p);
        return;
    }
    if(!visited[{x,0}])
    {
        q.push({x,0});
        visited[{x,0}]=1;
    }

    if(!visited[{0,y}])
    {
        q.push({0,y});
        visited[{0,y}]=1;
    }

    if(!visited[{x,n}])
    {
        q.push({x,n});
        visited[{x,n}]=1;
    }

    if(!visited[{m,y}])
    {
        q.push({m,y});
        visited[{m,y}]=1;
    }

    for(ll i=0;i<=max(m,n);i++)
    {
        int temp1=x+i;
        int temp2=y-i;

        if(temp1<=m && temp2>=0 && !visited[{temp1,temp2}])
        {
            q.push({temp1,temp2});
            visited[{temp1,temp2}]=1;
        }

        int temp3=x-i;
        int temp4=y+i;

        if(temp3>=0 && temp4<=n && !visited[{temp3,temp4}])
        {
            q.push({temp3,temp4});
            visited[{temp3,temp4}];
        }
    }
    BFS(q.front(),d);
}
// Time Complexity :Exponential


int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    cin>>n>>m>>d;
    q.push(make_pair(0,0));
    visited[{0,0}]=1;
    BFS({0,0},d);

    cout<<"-------------Path to Pour water -------------"<<endl;
    for(auto it:res)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }

    return 0;
}