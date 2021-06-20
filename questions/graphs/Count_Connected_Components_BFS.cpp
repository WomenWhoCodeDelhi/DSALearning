// Link to problem : https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

// Algorithm used : BFS

// Time Complexity = O(V + E)
// Space Complexity = O(V) - for visited array, queue data structure 

#include<bits/stdc++.h>
 
using namespace std;
 
void bfs(vector<vector<int> > &adj, vector<int> &vis, int startNode) {
	queue<int> q;
	q.push(startNode);
	vis[startNode] = 1;
	while(!q.empty()) {
		int frontNode = q.front();
		q.pop();
		for(auto nbr : adj[frontNode]) {
			if(vis[nbr] == 0) {
				vis[nbr] = 1;
				q.push(nbr);
			}
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
			bfs(adj, vis, node);
		}
	}
	cout<<components<<"\n";
 
	return 0;
}
