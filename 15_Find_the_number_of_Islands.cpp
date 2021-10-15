#include<bits/stdc++.h>
using namespace std;


class Solution
{
    void dfs(int i,int j,int visited[][501],vector<vector<char>>&arr,int n,int m)
    {
        if(i>=n || j>=m || i<0 || j<0 )
        {
            return;
        }
        if(arr[i][j]=='0')
        {
            return;
        }
        if(!visited[i][j])
        {
            visited[i][j]=1;
            dfs(i,j+1,visited,arr,n,m);
            dfs(i,j-1,visited,arr,n,m);
            dfs(i-1,j,visited,arr,n,m);
            dfs(i+1,j,visited,arr,n,m);
            dfs(i-1,j-1,visited,arr,n,m);
            dfs(i-1,j+1,visited,arr,n,m);
            dfs(i+1,j-1,visited,arr,n,m);
            dfs(i+1,j+1,visited,arr,n,m);
        }
    }
    public:
    int numIslands(vector<vector<char>>&arr) 
    {
        // Code here
        int n=arr.size();
        int m=arr[0].size();
        int visited[501][501];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                visited[i][j]=0;
            }
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && arr[i][j]=='1')
                {
                    dfs(i,j,visited,arr,n,m);
                    c++;
                }
            }
        }
        return c;
        
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  