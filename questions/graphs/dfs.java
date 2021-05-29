class Solution
{
    //Function to return a list containing the DFS traversal of the graph.
    public ArrayList<Integer> dfs(int curr, ArrayList<ArrayList<Integer>> adj, boolean visited[], ArrayList<Integer> res)
    {
        // Code here
        if(!visited[curr]){
            res.add(curr);
            visited[curr] = true;
            // return res;
        }
        //adj.get(curr) --> list of adj nodes
        //adj.get(curr).get(i) --> adj node
        
        for(int i=0; i<adj.get(curr).size(); i++){
            int adjNode = adj.get(curr).get(i);
            if(!visited[adjNode]){
                dfs(adjNode, adj, visited, res);
            }
        }
        return res;
    }
    
    //Function to return a list containing the DFS traversal of the graph.
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj)
    {
        // Code here
        boolean visited[] = new boolean[V];
        ArrayList<Integer> res = new ArrayList<>();
        dfs(0, adj, visited, res);
        return res;
    }
}
