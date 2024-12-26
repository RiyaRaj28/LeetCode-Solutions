class Solution {
public:
    // int solve(int ind, int buy, int n, vector<int>&prices, vector<vector<int>>&dp)
    // {
    //     cout << ind << "\n";
    //     if(ind >= n) return 0; 
        

    //     if(dp[ind][buy] != -1) return dp[ind][buy]; 
        
    //     if(buy == 1)
    //     {
    //         return dp[ind][buy] = max((-prices[ind] + solve(ind+1, 0, n, prices, dp)), 
    //         (0 + solve(ind+1, 1, n, prices, dp)));
    //     }

    //     // sell 
    //     return dp[ind][buy] = max((prices[ind] + solve(ind+2, 1, n, prices, dp)), (0+solve(ind+1, 0, n, prices, dp)));
    // }
    
    // int maxProfit(vector<int>& prices)
    // {
    //     int n = prices.size(); 
    //     vector<vector<int>>dp(n, vector<int>(2, -1));
    //     return solve(0, 1, n, prices, dp); 
    // }

    // int maxProfit(vector<int>& prices)
    // {
    //     int n = prices.size(); 
    //     //tabulated approach 
    //     vector<vector<int>>dp(n+2, vector<int>(2, 0));

    //     //can also skip writing this since everything is already 0
    //     // for(int buy=0; buy<=1; buy++)
    //     // {
    //     //     dp[n][buy] = 0; 
    //     // }

    //    for(int i=n-1; i>=0; i--)
    //     {
    //         for(int buy=0; buy<=1; buy++)
    //         {
    //             // int profit = 0; 
    //             if(buy)
    //             {
    //                 int buyOpt = -prices[i] + dp[i+1][0];
    //                 int notbuyOpt = 0 + dp[i+1][1];

    //                 dp[i][buy] = max(buyOpt, notbuyOpt);
    //             }
    //             else
    //             {                
    //                 int sell = prices[i] + dp[i+2][1]; //point of difference
    //                 int notsell = dp[i+1][0];

    //                 dp[i][buy] = max(sell, notsell);
    //             }
    //         }
    //     }

    //     for(int i=0; i<=n+1; i++)
    //     {
    //         cout << "row[" << i << "] : " ;
    //         for(int j=0; j<=1; j++)
    //         {
    //             cout << dp[i][j] << " ";
    //         }
    //         cout << "\n"; 
    //     }

    //     return dp[0][1];
    // }

    // int maxProfit(vector<int>& prices)
    // {
    //     int n = prices.size(); 
    //     vector<int>curr(2, 0), ahead1(2, 0), ahead2(2, 0); 

    //    for(int i=n-1; i>=0; i--)
    //     {
    //         curr[1] = max(-prices[i] + ahead1[0], 0 + ahead1[1]);
    //         curr[0] = max(prices[i] + ahead2[1], ahead1[0]);

    //         ahead2 = ahead1; 
    //         ahead1 = curr; 

    //         cout<< "row ["<< i <<"]" << curr[0] << " " << curr[1] << "\n";
    //     }

    //     return ahead1[1];
    // }













    int maxProfit(vector<int>& profit)
    {
        int n = profit.size();
        int buy = 2; 
        vector<vector<int>>table(n+2, vector<int>(buy, 0));

        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                table[i][buy] = buy>0 
                                ? max(-profit[i]+table[i+1][0], table[i+1][1])
                                : max(profit[i]+table[i+2][1], table[i+1][0]);
            }
        }
        return table[0][1];
    }















};