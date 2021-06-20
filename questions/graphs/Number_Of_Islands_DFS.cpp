// Link to question : https://leetcode.com/problems/number-of-islands/

// Algorithm used : DFS 

// Time Complexity : O(m * n) 
// How ?
// For DFS, Time complexity = O(V + E)
// here V = m * n, E ~ 4 * m * n
// therefore, Time Complexity = O(m * n)

// Space complexity : O(m * n) 
// How ?
// We are taking space for visited array [ = O(V) ] and dfs recursive stack [ = O(V) ]
// and V = m * n

class Solution {
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j){
        int m = grid.size(), n = grid[0].size();
        // node : grid[i][j]
        vis[i][j] = 1;
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};
        for(int k=0;k<4;k++){
            int i_nbr = i + dx[k], j_nbr = j + dy[k];
            if(i_nbr >= 0 && i_nbr < m && j_nbr >= 0 && j_nbr < n && grid[i_nbr][j_nbr] == '1' && vis[i_nbr][j_nbr] == 0){
                dfs(grid,vis,i_nbr,j_nbr);
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > vis(m,vector<int>(n,0));
        int components = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == '1' && vis[i][j] == 0) {
                    components++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return components;
    }
};

// every cell grid[i][j] is equivalent to a graph node
// if node value = 1 : island
// otherwise ignore


// Homework : Do the same problem using BFS.

