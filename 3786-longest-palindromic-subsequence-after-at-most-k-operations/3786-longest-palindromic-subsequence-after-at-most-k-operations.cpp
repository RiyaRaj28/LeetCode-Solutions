class Solution {
public:
    int longest(string &s, int i, int j, int k, vector<vector<vector<int>>>&dp)
    {
        if(i > j) return 0; 
        if(i == j) return 1; 

        if(dp[i][j][k] != -1) return dp[i][j][k]; 

        int minopsreq = min(abs(s[i] - s[j]), 26 - abs(s[i] - s[j])); 

        int ans = max(longest(s, i+1, j, k, dp), longest(s, i, j-1, k, dp));

        if(k >= minopsreq) ans = max(ans,  2+longest(s, i+1, j-1, k-minopsreq, dp));

        return dp[i][j][k] = ans;

    }


    int longestPalindromicSubsequence(string s, int k) 
    {
        // int maxlen = 0;
        // return LPS("", s, 0, 0, 0, k, maxlen);   
        int n = s.length();

        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(k+1, -1))); 
        return longest(s, 0, n-1, k, dp);
    }
};