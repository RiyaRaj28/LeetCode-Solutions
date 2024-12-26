class Solution {
public:
    // int maxProfit(vector<int>& prices, int fee)
    // {
    //     // int n = prices.size();
    //     // vector<vector<int>>dp(n+1, vector<int>(2, 0));

    //     // //base case ->0's are already filled 

    //     // for(int i=n-1; i>=0; i--)
    //     // {
    //     //     //buy
    //     //     dp[i][1] = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
    //     //     //sell
    //     //     dp[i][0] = max(prices[i]+dp[i+1][1]-fee, dp[i+1][0]);
    //     // }

    //     // return dp[0][1];
        
    // }






    int maxProfit(vector<int>& prices, int fee)
    {
        int n = prices.size();
        int buy = 2; 
        vector<vector<int>>table(n+1, vector<int>(buy, 0));

        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                table[i][buy] = buy>0
                                ? max(-prices[i]+table[i+1][0], table[i+1][1])
                                : max(prices[i]+table[i+1][1]-fee, table[i+1][0]);
            }
        }

        return table[0][1];
       
        
    }














};