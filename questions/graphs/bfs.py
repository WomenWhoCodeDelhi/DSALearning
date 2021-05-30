#User function Template for python3
import collections

class Solution:
    
    #Function to return Breadth First Traversal of given graph.
    def bfsOfGraph(self, V, adj):
        # code here
        
        q = collections.deque([0])
        visited = [False]*V
        # print(V, adj)
        ans = []
        while q:
            p = q.popleft()
            # print(p)
            if not visited[p]:
                ans.append(p)
                visited[p] = True
                for child in adj[p]:
                    q.append(child)
            # print(q)
            
        # ans = adj
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
		ob = Solution()
		ans = ob.bfsOfGraph(V, adj)
		for i in range(len(ans)):
		    print(ans[i], end = " ")
		print()
        

# } Driver Code Ends
