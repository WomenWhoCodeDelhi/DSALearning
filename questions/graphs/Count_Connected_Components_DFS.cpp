// Link to the question : https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

// Algorithm used : DFS

// Time Complexity = O(V + E)
// Space Complexity = O(V) - for visited array , and dfs recursive stack  

#include<bits/stdc++.h>
 
using namespace std;
 
void dfs(vector<vector<int> > &adj, vector<int> &vis, int node) {
	vis[node] = 1;
	for(auto nextNode : adj[node]) {
		if(vis[nextNode] == 0) {
			dfs(adj, vis, nextNode);
		}
	}
}
// 1 - 2
 
int main() {
	int n, e;
	cin>>n>>e;
	vector<vector<int> > adj(n+1);
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	vector<int> vis(n+1,0); // nodes : 1 to n
	int components = 0;
	for(int node=1;node<=n;node++){
		if(vis[node] == 0) { // not visited
			components++;
			dfs(adj, vis, node);
		}
	}
	cout<<components<<"\n";
 
	return 0;
}
