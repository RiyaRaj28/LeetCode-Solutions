class Solution {
public:

    int solve(string s1, string s2, int i, int j, vector<vector<int>>&dp)
    {
        if(j < 0) return 1; 
        if(i < 0) return 0; 

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) 
        {
            // reduce first str, reduce first str and second str
            return dp[i][j] = (solve(s1, s2, i-1, j, dp) + solve(s1, s2, i-1, j-1, dp));
        }
        else 
        {
            // reduce first str
            return dp[i][j] = solve(s1, s2, i-1, j, dp); 
        }
    }

    int numDistinct(string s, string t) 
    {
        int n = s.length();
        int m = t.length();

        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(s, t, n-1, m-1, dp);


        
    }
};