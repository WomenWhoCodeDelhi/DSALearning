//TC : O (V+E)
//SC : O(V)
/*Complete the function below*/

// 1. Start dfs from all unvisited nodes
// 2. Check for cycle
   //  2.1 Iterate over adj nodes
// // 2.2 If cycle found, we return
// 3. Otherwise, we continue
class Solution 
{
    //Function to detect cycle in a directed graph.
     public boolean isCyclicUtil(int vertex, ArrayList<ArrayList<Integer>> adj, boolean visited[], boolean nodesInPath[])
    {
        // code here
        if(nodesInPath[vertex]){
            return true;
        }
        if (visited[vertex]){
            return false;
        }
        visited[vertex]=true;
        nodesInPath[vertex]=true;
        //adj.get(vertex) - adj nodes list
        for(int i=0;i<adj.get(vertex).size();i++){
            int adjNode=adj.get(vertex).get(i); // adj node
            if (isCyclicUtil(adjNode,adj,visited,nodesInPath))
                return true;
            
        }
        nodesInPath[vertex]=false;
        return false;  
      
        
    }
    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj)
    {
        boolean visited[]=new boolean [V];
        boolean nodesInPath[]=new boolean [V];
        for (int i=0;i<V;i++){
            if (isCyclicUtil(i,adj,visited,nodesInPath))
                return true;
        }
        return false;
    }
}
 
