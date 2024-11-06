class Solution {
public:
    int solve(int ind, int buy, int n, vector<int>&prices, vector<vector<int>>&dp)
    {
        if(ind >= n) return 0; 

        if(dp[ind][buy] != -1) return dp[ind][buy]; 
        
        if(buy == 1)
        {
            return dp[ind][buy] = max((-prices[ind] + solve(ind+1, 0, n, prices, dp)), 
            (0 + solve(ind+1, 1, n, prices, dp)));
        }

        // sell 
        return dp[ind][buy] = max((prices[ind] + solve(ind+2, 1, n, prices, dp)), (0+solve(ind+1, 0, n, prices, dp)));
    }
    
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size(); 
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return solve(0, 1, n, prices, dp); 
    }

};