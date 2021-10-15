#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    int x1=KnightPos[0];              //  x position of knight
	    int y1=KnightPos[1];              //  y position of knight
	    int x2=TargetPos[0];              //  x position of target
	    int y2=TargetPos[1];              //  y position of target
	    if(x1==x2 and y1==y2)             // If knight and target are on the same positoin
	    {
	        return 0;    // 0 position
	    }
	    
	    int arr[1001][1001];            
	    for(int i=0;i<n;i++)       // mark the nxn array as 0
	    {
	        for(int j=0;j<n;j++)
	        {
	            arr[i][j]=0;
	        }
	    }
	    queue<pair<int,int>>q;     // We use que because every possible position , we added it in queue 
        // and check the added position will we reached the target or not and so on
        
        // first push the knight position in queue
        // and start checking the every possible position
	    q.push(make_pair(x1-1,y1-1));       // for zero indexing 
	    while(!q.empty())
	    {
	        auto curr=q.front();
	        int i=curr.first;
	        int j=curr.second;
	        q.pop();

            // There are 8 max possible moves available if knight at the centre of 8x8 grid 
            // so we checking for every possible move 
            // also with condition of the position lies inside grid or not and the value of the position is zero or not
            // if zero then we can proceed otherwise we can ignore it .
	        if((i+1)>=0 and (i+1)<n and (j+2)>=0 and (j+2)<n  and arr[i+1][j+2]==0)
	        {
	            arr[i+1][j+2]=1+arr[i][j];
	            q.push(make_pair(i+1,j+2));
	        }
	        if((i-1)>=0 and (i-1)<n and (j+2)>=0 and (j+2)<n and arr[i-1][j+2]==0)
	        {
	            arr[i-1][j+2]=1+arr[i][j];
	            q.push(make_pair(i-1,j+2));
	        }
	        if((i-2)>=0 and (i-2)<n and (j+1)>=0 and (j+1)<n and arr[i-2][j+1]==0)
	        {
	            arr[i-2][j+1]=1+arr[i][j];
	            q.push(make_pair(i-2,j+1));
	        }
	        if((i+2)>=0 and (i+2)<n and (j+1)>=0 and (j+1)<n and arr[i+2][j+1]==0)
	        {
	            arr[i+2][j+1]=1+arr[i][j];
	            q.push(make_pair(i+2,j+1));
	        }
	        if((i-1)>=0 and (i-1)<n and (j-2)>=0 and (j-2)<n and arr[i-1][j-2]==0)
	        {
	            arr[i-1][j-2]=1+arr[i][j];
	            q.push(make_pair(i-1,j-2));
	        }
	        if((i+1)>=0 and (i+1)<n and (j-2)>=0 and (j-2)<n and arr[i+1][j-2]==0)
	        {
	            arr[i+1][j-2]=1+arr[i][j];
	            q.push(make_pair(i+1,j-2));
	        }
	        if((i-2)>=0 and (i-2)<n and (j-1)>=0 and (j-1)<n and arr[i-2][j-1]==0)
	        {
	            arr[i-2][j-1]=1+arr[i][j];
	            q.push(make_pair(i-2,j-1));
	        }
	        if((i+2)>=0 and (i+2)<n and (j-1)>=0 and (j-1)<n and arr[i+2][j-1]==0)
	        {
	            arr[i+2][j-1]=1+arr[i][j];
	            q.push(make_pair(i+2,j-1));
	        }
	        
	        
	    }
	    return arr[x2-1][y2-1];               // Returning the total number of moves i.e the value of that position
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
} 














//  Short code of above

// //4. Conference Schedule

// // C++ program to find maximum number of meetings
#include <bits/stdc++.h>
using namespace std;

bool isValid(int i,int j,int n)
{
    return (i>=0 && i<n && j>=0 && j<n);
}

int solve(int n,int x1,int y1,int x2,int y2)
{
    // base case , that is knight position is same as destination position
    if(x1==x2 && y1==y2)
    {
        return 0;
    }
    int dist[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dist[i][j]=0;
        }
    }
    queue<pair<int,int>>q;
    q.push({x1,y1});
    dist[x1][y1]=0;

    // Direction in which knight can move
    int dir_x[8]={-2, -1, 1, 2, -2, -1, 1, 2 };
    int dir_y[8]={ -1, -2, -2, -1, 1, 2, 2, 1 };
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        int x=it.first;
        int y=it.second;
        for(int i=0;i<8;i++)
        {
            int temp=x+dir_x[i];
            int temp1=y+dir_y[i];
            if(isValid(temp,temp1,n) && dist[temp][temp1]==0)
            {
                dist[temp][temp1]=dist[x][y]+1;
                q.push({temp,temp1});
            }
        }
    }
    return dist[x2][y2];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    int n;
    cin>>n;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<solve(n,x1,y1,x2,y2)<<endl;
	return 0;
}

/*
Time complexity: O(N^2). 
    At worst case, all the cells will be visited so time complexity is O(N^2).
Auxiliary Space: O(N^2). 
    The nodes are stored in queue. So the space Complexity is O(N^2).
*/
