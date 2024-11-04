class Solution {
public:

    // int solve(string s1, string s2, int i, int j, vector<vector<int>>&dp)
    // {
    //     if(j < 0) return 1; 
    //     if(i < 0) return 0; 

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s1[i] == s2[j]) 
    //     {
    //         // reduce first str, reduce first str and second str
    //         return dp[i][j] = (solve(s1, s2, i-1, j, dp) + solve(s1, s2, i-1, j-1, dp));
    //     }
    //     else 
    //     {
    //         // reduce first str
    //         return dp[i][j] = solve(s1, s2, i-1, j, dp); 
    //     }
    // }

    // int numDistinct(string s, string t) 
    // {
    //     int n = s.length();
    //     int m = t.length();

    //     vector<vector<int>>dp(n, vector<int>(m, -1));
    //     return solve(s, t, n-1, m-1, dp);


        
    // }

    int numDistinct(string s, string t) 
    {
        int n = s.length();
        int m = t.length();

        vector<vector<double>>dp(n+1, vector<double>(m+1, 0));
        // return solve(s, t, n-1, m-1, dp);

        //taking the second string along the column 
        for(int i=0; i<=m; i++) dp[0][i] = 0; 
        for(int j=0; j<=n; j++) dp[j][0] = 1; 

        for(int i1 = 1; i1<=n; i1++)
        {
            for(int i2 = 1; i2<=m; i2++)
            {
                if(s[i1-1] == t[i2-1]) dp[i1][i2] = dp[i1-1][i2] + dp[i1-1][i2-1]; 
                else 
                {
                    dp[i1][i2] = dp[i1-1][i2]; 
                }
            }
        }

        return (int)dp[n][m]; 
    }
};