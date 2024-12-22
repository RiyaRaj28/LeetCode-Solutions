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

// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(); 
//         int n = grid[0].size(); 

//         if(m==1 && n==1) return grid[0][0]; 

//         //tabulation -> bottom up approach. we will store the count at each cell and go on updating it. 

//         vector<vector<int>>table(m, vector<int>(n, INT_MAX)); 

//         for(int i=0; i<m; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 if(i==0 && j==0) table[i][j] = grid[i][j];
//                 else
//                 {
//                     int up = INT_MAX;
//                     int left = INT_MAX; 
//                     if(i>0) up = table[i-1][j];
//                     if(j>0) left = table[i][j-1]; 

//                     table[i][j] = grid[i][j] + min(up, left);
//                 }
//             }
//         }

//         return table[m-1][n-1];
//     }

//SPACE OPTIMISED
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(); 
//         int n = grid[0].size(); 

//         if(m==1 && n==1) return grid[0][0]; 

//         //tabulation + sp optimisation -> bottom up approach. we will store the count at each cell and go on updating it. 

//         vector<int>prev(n, 0);

//         for(int i=0; i<m; i++)
//         {
//             vector<int> curr(n, 0); 
//             for(int j=0; j<n; j++)
//             {
//                 if(i==0 && j==0) curr[j] = grid[i][j];
//                 else
//                 {
//                     int up = INT_MAX;
//                     int left = INT_MAX; 
//                     if(i>0) up = prev[j];
//                     if(j>0) left = curr[j-1]; 

//                     curr[j] = grid[i][j] + min(up, left);
//                 }
//             }
//             prev = curr; 
//         }

//         return prev[n-1];
//     }
    
// };




// class Solution {
// public:

//     int solve(vector<vector<int>>&grid, int i, int j)
//     {
//         int m = grid.size();
//         int n = grid[0].size(); 
//         //base case 
//         // we are going from n-1,n-1 to 0,0
//         if(i<0 || j<0) return 1e8; 

//         if(i==0 && j==0) return grid[i][j]; 

//         int up = solve(grid, i-1, j); 
//         int left = solve(grid, i, j-1); 

//         return grid[i][j] + min(up, left);
//     }

//     int minPathSum(vector<vector<int>>& grid) 
//     {
//         // recursive approach is simple just go from n,n to 0,0 with the correct base cases 

//         // just keep moving left or up 

//         // and take their minimum, the min of both the two along with the sum of the current gird elem

//         // in tabulation however 
//         // we will make a 2d dp array 
//         // have to go to the first index 
//         // so dp[0][0] = 0
//         // and left will be 
//         // and up will be 
//         // we will start from 0,0 and go till n-1,n-1 here though 
        
//         int m = grid.size(); 
//         int n = grid[0].size(); 
//         return solve(grid, m-1, n-1);
//     }


    
class Solution {
public:

    int solve(vector<vector<int>>&grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size(); 
        //base case 
        // we are going from n-1,n-1 to 0,0
        if(i<0 || j<0) return 1e8; 

        if(i==0 && j==0) return grid[i][j]; 

        int up = solve(grid, i-1, j); 
        int left = solve(grid, i, j-1); 

        return grid[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) 
    {
        // recursive approach is simple just go from n,n to 0,0 with the correct base cases 

        // just keep moving left or up 

        // and take their minimum, the min of both the two along with the sum of the current gird elem

        // in tabulation however 
        // we will make a 2d dp array 
        // have to go to the first index 
        // so dp[0][0] = 0
        // and left will be 
        // and up will be 
        // we will start from 0,0 and go till n-1,n-1 here though 



        
        int m = grid.size(); 
        int n = grid[0].size(); 

        vector<vector<int>>dp(m, vector<int>(n, 0)); 

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0) dp[i][j] = grid[i][i];

                // have to check for the existence of down and right value and add that to the current val

                else
                {
                    int up = i>0 ? dp[i-1][j] : 1e8; 
                    int left = j>0 ? dp[i][j-1] : 1e8;
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }

        return dp[m-1][n-1]; 
    }



};