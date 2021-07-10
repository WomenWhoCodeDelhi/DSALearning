// 1. Intially, we get all the rotten ones in Queue
// 2. Mark their adj as rotten and remove them
// 3. Same process with their adj
// 4. Continue till all the nodes are visited
// TC : O (m x n)
// SC : O( m x n)
class Node {
   int time;
   int x;
   int y;   
 public Node (int time, int x, int y){
     this.time=time;
     this.x=x;
     this.y=y;
     
 }
}
class Solution {
    public int orangesRotting(int[][] grid) {
        
        Queue<Node> q=new LinkedList<>();
        for( int i=0;i<grid.length;i++){
           for(int j=0;j<grid[0].length;j++){
               if(grid[i][j]==2){
                   q.add(new Node (0,i,j));
               }
           } 
             
        }
        int res=0;
        while (!q.isEmpty()){
             Node front=q.remove();
             res=Math.max(res,front.time);
             int[] dirx={0,0,-1,1};
             int[] diry={1,-1,0,0};
             for(int k=0;k<4;k++){
                 int newX=dirx[k]+front.x;
                 int newY=diry[k]+front.y;
                 if(newX>=0 && newX<grid.length && newY>=0 && newY<grid[0].length && grid[newX][newY]==1){
                     grid[newX][newY]=2;
                     q.add(new Node (front.time+1,newX, newY));
                 }
             }    
        }
       for( int i=0;i<grid.length;i++){
           for(int j=0;j<grid[0].length;j++){
               if(grid[i][j]==1){
                   return -1;
               }
        
    }
}
        return res;
        
    }
}
