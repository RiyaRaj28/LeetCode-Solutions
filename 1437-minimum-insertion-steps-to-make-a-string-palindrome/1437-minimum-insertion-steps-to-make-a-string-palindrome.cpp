class Solution {
public:

    int LCS(string &s, string &t)
    {
        int n = s.length(); 

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0)); 

        // for(int i=0; i1<n; i++) dp[i][0] = 0; 

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }

        return dp[n][n]; 
    }

    int minInsertions(string s) 
    {
        string t = s; 
        reverse(t.begin(), t.end()); 
        int n = s.length(); 

        int LCS_num = LCS(s, t); 
        return n - LCS_num; 
    }
};