class Solution {
public:
    // int solve(int i1, int i2, string s1, string s2, vector<vector<int>>&dp)
    // {
    //     if(i1 <0 || i2 < 0) return 0; 

    //     if(dp[i1][i2] != -1) return dp[i1][i2]; 

    //     if(s1[i1] == s2[i2])
    //     {
    //         return 1 + solve(i1-1, i2-1, s1, s2, dp);
    //     }

    //     return dp[i1][i2] = max(solve(i1-1, i2, s1, s2, dp), solve(i1, i2-1, s1, s2, dp));
    // }
    
    // int longestCommonSubsequence(string text1, string text2) 
    // {
    //     int n1 = text1.length(); 
    //     int n2 = text2.length(); 

    //     vector<vector<int>>dp(n1, vector<int>(n2, -1)); 
    //     return solve(n1-1, n2-1, text1, text2, dp);
    // }

    // TABULATION
    // int longestCommonSubsequence(string text1, string text2) 
    // {
    //     int n = text1.length();
    //     int m = text2.length();

    //     vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    //     for(int i=0; i<=n; i++) dp[i][0] = 0; 
    //     for(int j=0; j<=m; j++) dp[0][j] = 0; 

    //     for(int i1 = 1; i1 <= n; i1++)
    //     {
    //         for(int i2 = 1; i2 <= m; i2++)
    //         {
    //             if(text1[i1-1] == text2[i2-1]) dp[i1][i2] = 1 + dp[i1-1][i2-1];
    //             else dp[i1][i2] = max(dp[i1-1][i2], dp[i1][i2-1]);
    //         }
    //     }
    //     return dp[n][m]; 
    // }


    // TABULATION - SPACE OPTIMISED 
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<int>prev(m+1, 0), curr(m+1, 0); 

        for(int i=0; i<=m; i++) prev[i] = 0; 
        // for(int j=0; j<=m; j++) dp[0][j] = 0; 

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(text1[i-1] == text2[j-1]) curr[j] = 1 + prev[j-1]; //diagonal
                else curr[j] = max(curr[j-1], prev[j]); //up or left
            }
            prev = curr; 
        }
        return prev[m]; 
    }

};