// class Solution {
// public:

//     int recursion(vector<vector<int>>triangle, int i, int j, vector<vector<int>>&dp)
//     {
//         int n = triangle.size();
//         if(i == n-1) return triangle[i][j];

//         if(dp[i][j] != -1) return dp[i][j]; 

//         int neeche = recursion(triangle, i+1, j, dp); 
//         int bagal = recursion(triangle, i+1, j+1, dp); 

//         return dp[i][j] = triangle[i][j] + min(neeche, bagal);  
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();

//         vector<vector<int>>dp(n, vector<int>(n, -1));
//         return recursion(triangle, 0, 0, dp);    
//     }
// };

class Solution {
public:

    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     vector<vector<int>>table(n, vector<int>(n, 0)); 

    //     for(int i=0; i<n; i++) table[n-1][i] = triangle[n-1][i]; 

    //     for(int i=n-2; i>=0; i--)
    //     {
    //         for(int j=i; j>=0; j--)
    //         {
    //                 int d = triangle[i][j] + table[i+1][j];
    //                 int dg = triangle[i][j] + table[i+1][j+1];

    //                 table[i][j] = min(d, dg);
                
    //         }
    //     }
    //     return table[0][0];
    // }

      // USING SPACE OPTIMISATION
      int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>next(n, 0);

        for(int i=0; i<n; i++) next[i] = triangle[n-1][i]; 

        for(int i=n-2; i>=0; i--)
        {
            vector<int>curr(n, 0); 
            for(int j=i; j>=0; j--)
            {
                    int d = triangle[i][j] + next[j];
                    int dg = triangle[i][j] + next[j+1];

                    curr[j] = min(d, dg);
            }
            next = curr; 
        }
        return next[0];
    }
};