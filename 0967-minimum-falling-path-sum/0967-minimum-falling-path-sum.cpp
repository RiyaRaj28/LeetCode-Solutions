// class Solution {
// public:

//     int recursion(int i, int j, vector<vector<int>>&matrix, vector<vector<int>>&dp)
//     {
//         int n = matrix.size();
//         if(i == n-1) return dp[i][j] = matrix[i][j];

//         if(dp[i][j] != -1) return dp[i][j];

//         int left = INT_MAX; 
//         int down = INT_MAX; 
//         int right = INT_MAX; 

//         if(i<n-1 && j>0) left = matrix[i][j] + recursion(i+1, j-1, matrix, dp);
//         if(i<n-1) down = matrix[i][j] + recursion(i+1, j, matrix, dp);
//         if(i<n-1 && j<n-1) right = matrix[i][j] + recursion(i+1, j+1, matrix, dp);

//         return dp[i][j] = min(left, min(down, right));
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) 
//     {
//         int n = matrix.size();
//         vector<vector<int>>dp(n, vector<int>(n, -1));
//         int ans = INT_MAX;

//         for(int j=0; j<n; j++)
//         {
//             ans = min(ans, recursion(0, j, matrix, dp));
//         }

//         return ans; 
//     }
// };

//TABULATION 
// tabulation is a top down approach. we also did it through bottom up approach previously. 


// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) 
//     {
//         int n = matrix.size();
//         vector<vector<int>>table(n, vector<int>(n, 0));

//         for(int j=0; j<n; j++) table[n-1][j] = matrix[n-1][j]; 

//         for(int i=n-2; i>=0; i--)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 int left = INT_MAX; 
//                 int down = INT_MAX; 
//                 int right = INT_MAX; 

//                 if(i<n-1 && j>0) left = matrix[i][j] + table[i+1][j-1];
//                 if(i<n-1) down = matrix[i][j] + table[i+1][j];
//                 if(i<n-1 && j<n-1) right = matrix[i][j] + table[i+1][j+1];

//                 table[i][j] = min(left, min(down, right)); 
//             }
//         }

//         int ans = INT_MAX; 
//         for(int i=0; i<n; i++)
//         {
//             if(table[0][i] < ans) ans = table[0][i];
//         } 
//         return ans; 
//     }
// };


// TABULATION WITH SPACE OPTIMISATION 
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) 
//     {
//         int n = matrix.size();
//         vector<int>next(n, 0); 

//         for(int j=0; j<n; j++) next[j] = matrix[n-1][j]; 

//         for(int i=n-2; i>=0; i--)
//         {
//             vector<int>curr(n, 0); 
//             for(int j=0; j<n; j++)
//             {
//                 int left = INT_MAX; 
//                 int down = INT_MAX; 
//                 int right = INT_MAX; 

//                 if(i<n-1 && j>0) left = matrix[i][j] + next[j-1];
//                 if(i<n-1) down = matrix[i][j] + next[j];
//                 if(i<n-1 && j<n-1) right = matrix[i][j] + next[j+1];

//                 curr[j] = min(left, min(down, right)); 
//             }

//             next = curr; 
//         }

//         int ans = INT_MAX; 
//         for(int i=0; i<n; i++)
//         {
//             if(next[i] < ans) ans = next[i];
//         } 
//         return ans; 
//     }
// };




// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) 
//     {
//        int n = matrix.size(); 
//        vector<vector<int>>table(n, vector<int>(n, 0)); 

//        for(int i=0; i<n; i++)
//        {
//         table[n-1][i] = matrix[n-1][i];
//        }

//        for(int i=n-2; i>=0; i--)
//        {
//         for(int j=n-1; j>=0; j--)
//         {
//             int left = (i<n-1 && j>0) ? table[i+1][j-1] : INT_MAX; 
//             int down = (i<n-1) ? table[i+1][j] : INT_MAX;   
//             int right = (i<n-1 && j<n-1) ? table[i+1][j+1] : INT_MAX; 

//             table[i][j] = matrix[i][j] + min(left, min(down, right));  
//         }
//        }

//        int ans = INT_MAX;
//        for(int i=0; i<n; i++) if(table[0][i] < ans) ans = table[0][i];

//        return ans; 
//     }
// };


// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) 
//     {
//        int n = matrix.size(); 
//        vector<int>next(n, 0), curr(n, 0); 
//        for(int i=0; i<n; i++) next[i] = matrix[n-1][i]; 
 
//        for(int i=n-2; i>=0; i--)
//        {
//         for(int j=n-1; j>=0; j--)
//         {
//             int left = (j>0) ? next[j-1] : INT_MAX; 
//             int down = next[j];   
//             int right = (j<n-1) ? next[j+1] : INT_MAX; 

//             curr[j] = matrix[i][j] + min(left, min(down, right));  
//         }
//         next = curr; 
//        }

//        int ans = INT_MAX;
//        for(int i=0; i<n; i++) if(next[i] < ans) ans = next[i];

//        return ans; 
//     }
// };
















// class Solution {
// public:
//     int solve(int i, int j, vector<vector<int>>&matrix, vector<vector<int>>&dp)
//     {
//         int n = matrix.size();
//         if(i > n-1 || j > n-1 || j<0) return 1e8; 
//         if(dp[i][j] != -1) return dp[i][j]; 
//         if(i == n-1) return matrix[i][j]; 

//         int d = solve(i+1, j, matrix, dp); 
//         int dgr = solve(i+1, j+1, matrix, dp); 
//         int dgl = solve(i+1, j-1, matrix, dp);

//         return dp[i][j] = matrix[i][j] + min(d, min(dgl, dgr)); 
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) 
//     {
//        int n = matrix.size();
//        int mini = INT_MAX;
//        vector<vector<int>>dp(n, vector<int>(n, -1)); 

//        for(int j=0; j<n; j++)
//        {
//             mini = min(mini, solve(0, j, matrix, dp));
//        }
//        return mini; 
//     }
// };




class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        // have to tabulate it 
        // kaise karte tabulate 
        // tabulation is bottom up 
        // have to statrt from the small indexes then build it upwards 
        // small index -> i = 0 to n 
        // j -> 0 to n
        // no. j and i have to be taken for the immediately next index 
        // j can vary as 1, 0, -1 in the next row 
        // have to maintain it in a table 
        // the first row must be filled first then? 
        // no we must operate from the last row first 

        // we will fill up the last row of the table and start our traversal from the second last row 
        // upto the 0th row 
        int n = matrix.size();

        // vector<vector<int>>table(n, vector<int>(n, 0));
        vector<int>next(n, 0); 
        vector<int>curr(n, 0); 

        for(int j=0; j<n; j++)
        {
            next[j] = matrix[n-1][j];
        }

        int ans = 1e8; 

        for(int i=n-2; i>=0; i--)
        {
            for(int j=0; j<n; j++)
            {
                int d = next[j];
                int dl = j>0 ? next[j-1] : 1e8;
                int dr = j<n-1 ? next[j+1] : 1e8;
 
                curr[j] = matrix[i][j] + min(d, min(dl, dr)); 
            }
            next = curr; 
        }

        // int ans = 1e8; 
        for(int i=0; i<n; i++)
        {
            if(next[i] < ans) ans = next[i];
        }
        return ans;
    }
};























