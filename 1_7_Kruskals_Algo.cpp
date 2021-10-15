#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){
	int N,m;
	cin >> N >> m;
	vector<node> edges; 
	for(int i = 0;i<m;i++) {
	    int u, v,wt;
	    cin >> u >> v>> wt; 
		//wt=vec[u-1];
	    edges.push_back(node(u, v, wt)); 
	}
	sort(edges.begin(), edges.end(), comp); 
	
	vector<int> parent(N+1);

	for(int i =0;i<=N;i++) 
	    parent[i] = i; 

	vector<int> rank(N+1, 0); 
	
	int cost = 0;
	vector<pair<int,int>> mst; 
	for(auto it : edges) {
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, parent, rank); 
	    }
	}
	cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second<< endl; 
	return 0;
}


//Another Simpler solution but not efficient

// Simple C++ implementation for Kruskal's
// algorithm
// #include <bits/stdc++.h>
// using namespace std;

// #define V 5
// int parent[V];

// // Find set of vertex i
// int find(int i)
// {
// 	while (parent[i] != i)
// 		i = parent[i];
// 	return i;
// }

// // Does union of i and j. It returns
// // false if i and j are already in same
// // set.
// void union1(int i, int j)
// {
// 	int a = find(i);
// 	int b = find(j);
// 	parent[a] = b;
// }

// // Finds MST using Kruskal's algorithm
// void kruskalMST(int cost[][V])
// {
// 	int mincost = 0; // Cost of min MST.

// 	// Initialize sets of disjoint sets.
// 	for (int i = 0; i < V; i++)
// 		parent[i] = i;

// 	// Include minimum weight edges one by one
// 	int edge_count = 0;
// 	while (edge_count < V - 1) {
// 		int min = INT_MAX, a = -1, b = -1;
// 		for (int i = 0; i < V; i++) {
// 			for (int j = 0; j < V; j++) {
// 				if (find(i) != find(j) && cost[i][j] < min) {
// 					min = cost[i][j];
// 					a = i;
// 					b = j;
// 				}
// 			}
// 		}

// 		union1(a, b);
// 		printf("Edge %d:(%d, %d) cost:%d \n",
// 			edge_count++, a, b, min);
// 		mincost += min;
// 	}
// 	printf("\n Minimum cost= %d \n", mincost);
// }

// // driver program to test above function
// int main()
// {
// 	/* Let us create the following graph
// 		2 3
// 	(0)--(1)--(2)
// 	| / \ |
// 	6| 8/ \5 |7
// 	| /	 \ |
// 	(3)-------(4)
// 			9		 */
// 	int cost[][V] = {
// 		{ INT_MAX, 2, INT_MAX, 6, INT_MAX },
// 		{ 2, INT_MAX, 3, 8, 5 },
// 		{ INT_MAX, 3, INT_MAX, INT_MAX, 7 },
// 		{ 6, 8, INT_MAX, INT_MAX, 9 },
// 		{ INT_MAX, 5, 7, 9, INT_MAX },
// 	};

// 	// Print the solution
// 	kruskalMST(cost);

// 	return 0;
// }
