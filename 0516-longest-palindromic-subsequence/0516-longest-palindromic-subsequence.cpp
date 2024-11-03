class Solution {
public:
    int LCS(string s1, string s2)
    {
        int n = s1.length(); 
        int m = s2.length(); 
        // vector<vector<int>>dp(n+1, vector<int>(m+1, 0)); 
        vector<int>prev(m+1, 0), curr(m+1, 0); 

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    // dp[i][j] = 1+dp[i-1][j-1]; 
                    curr[j] = 1 + prev[j-1];
                    
                    // cout << dp[i][j] << " ";
                }
                // else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
                else curr[j] = max(curr[j-1], prev[j]); 
            }
            prev = curr;
        }

        // return dp[n][m]; 
        return prev[m];
        
    }

    //doing the silly error of not reversing the string properly. missing concept. cant access a string index till not initialised it. need to assign it some dummy value like a dollar 

    int longestPalindromeSubseq(string s) 
    {
        // string s2 = reverse(s.begin(), s.end()); 
        int n = s.length(); 
        string s2 = ""; 
        for(int i=0; i<n; i++)
        {
            s2 += '$';
        }

        int ind = 0; 
        for(int i=n-1; i>=0; i--)
        {
            s2[ind] = s[i];
            ind++; 
        }
        return LCS(s, s2); 
        
    }
};