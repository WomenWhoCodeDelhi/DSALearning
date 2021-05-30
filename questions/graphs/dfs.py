#User function Template for python3

class Solution:

    
    #Function to return a list containing the DFS traversal of the graph.
    def dfsOfGraph(self, V, adj):
        # code here
        
        visited = [False]*V
        stack = [0]
        
        def dfs(p, visited, ans):
            
            if visited[p]:
                return
            
            ans.append(p)
            visited[p] = True
            
            for child in adj[p]:
                dfs(child, visited, ans)
        
        ans = []
        while stack:
            p = stack.pop()
            
            dfs(p, visited, ans)
            
        return ans
        

#{ 
#  Driver Code Starts
if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		V, E = map(int, input().split())
		adj = [[] for i in range(V)]
		for _ in range(E):
			u, v = map(int, input().split())
			adj[u].append(v)
			adj[v].append(u)
        ob = Solution()
		ans = ob.dfsOfGraph(V, adj)
		for i in range(len(ans)):
			print(ans[i], end = " ")
		print()
        

# } Driver Code Ends
