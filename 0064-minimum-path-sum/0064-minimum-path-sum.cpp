class Solution {
public:
    int recursion(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&grid)
    {
        if(i==0 && j==0) return grid[i][j]; 
        if(i<0 || j<0) return INT_MAX; 

        if(dp[i][j] != -1) return dp[i][j]; 

        int up = recursion(i-1, j, dp, grid); 
        int left = recursion(i, j-1, dp, grid); 
        
        return dp[i][j] = grid[i][j] + min(left,up); 
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size(); 

        if(m==1 && n==1) return grid[0][0]; 

        vector<vector<int>>dp(m, vector<int>(n, -1)); 
        return recursion(m-1, n-1, dp, grid);
        // return dp[m-1][n-1];  
    }
    
};