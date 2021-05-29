class Solution
{
    public ArrayList<Integer> bfsOfGraph(int V,ArrayList<ArrayList<Integer>> adj, boolean visited)
    {
        // Code here
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        while(!q.isEmpty()){
            int front= q.remove();
            if( !visited[front] ){
                result.add(front);
            }
            visited[front] = true;
            //adj.get(Front) --> the list of nodes adj to front
            //adj.get(front).get(i) --> node which is adj to front
            
            for(int i=0; i<adj.get(front).size(); i++){
                int adjNode = adj.get(front).get(i);
                if (!visited[adjNode]){
                    q.add(adjNode);
                }
            }
            return result;
        }
        
    }

    //Function to return Breadth First Traversal of given graph.
    public ArrayList<Integer> bfsOfGraph(int V,ArrayList<ArrayList<Integer>> adj)
    {
        // Code here
        boolean visited[] = new boolean [V];
        for(int i=0; i<V; i++){
            
        }
        
    }
}
