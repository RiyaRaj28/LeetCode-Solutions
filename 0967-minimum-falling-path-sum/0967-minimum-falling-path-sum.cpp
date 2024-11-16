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


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
       int n = matrix.size(); 
       vector<int>next(n, 0), curr(n, 0); 
       for(int i=0; i<n; i++) next[i] = matrix[n-1][i]; 
 
       for(int i=n-2; i>=0; i--)
       {
        for(int j=n-1; j>=0; j--)
        {
            int left = (j>0) ? next[j-1] : INT_MAX; 
            int down = next[j];   
            int right = (j<n-1) ? next[j+1] : INT_MAX; 

            curr[j] = matrix[i][j] + min(left, min(down, right));  
        }
        next = curr; 
       }

       int ans = INT_MAX;
       for(int i=0; i<n; i++) if(next[i] < ans) ans = next[i];

       return ans; 
    }
};
