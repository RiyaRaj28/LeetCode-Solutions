// class Solution {
// public:
//     int recursion(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&grid)
//     {
//         if(i==0 && j==0) return grid[i][j]; 
//         if(i<0 || j<0) return INT_MAX; 

//         if(dp[i][j] != -1) return dp[i][j]; 

//         int up = recursion(i-1, j, dp, grid); 
//         int left = recursion(i, j-1, dp, grid); 
        
//         return dp[i][j] = grid[i][j] + min(left,up); 
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(); 
//         int n = grid[0].size(); 

//         if(m==1 && n==1) return grid[0][0]; 

//         vector<vector<int>>dp(m, vector<int>(n, -1)); 
//         return recursion(m-1, n-1, dp, grid);
//         // return dp[m-1][n-1];  
//     }
    
// };

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size(); 

        if(m==1 && n==1) return grid[0][0]; 

        //tabulation -> bottom up approach. we will store the count at each cell and go on updating it. 

        vector<vector<int>>table(m, vector<int>(n, INT_MAX)); 

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0) table[i][j] = grid[i][j];
                else
                {
                    int up = INT_MAX;
                    int left = INT_MAX; 
                    if(i>0) up = table[i-1][j];
                    if(j>0) left = table[i][j-1]; 

                    table[i][j] = grid[i][j] + min(up, left);
                }
            }
        }

        return table[m-1][n-1];
    }
    
};