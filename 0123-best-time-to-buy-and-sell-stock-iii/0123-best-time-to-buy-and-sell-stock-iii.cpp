class Solution {
public:

    // int solve(vector<int>&prices, int n, int ind, int buy, int cap, vector<vector<vector<int>>>&dp)
    // {
    //     if(ind == n) return 0; 
    //     if(cap == 0) return 0; 

    //     if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap]; 

    //     int profit = 0; 
    //     if(buy)
    //         profit = max(-prices[ind] + solve(prices, n, ind+1, 0, cap, dp), 
    //                         0 + solve(prices, n, ind+1, 1, cap, dp));
    //     else //sell
    //         profit = max(prices[ind] + solve(prices, n, ind+1, 1, cap-1, dp),
    //                         0 + solve(prices, n, ind+1, 0, cap, dp));
        
    //     return dp[ind][buy][cap] = profit;
    // }

    // int maxProfit(vector<int>& prices) 
    // {
    //     int n = prices.size();
    //     vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    //     solve(prices, n, 0, 1, 2, dp);   

    //     for(int i=0; i<n; i++)
    //     {
    //         for(int j=0; j<=1; j++)
    //         {
    //             for(int k=0; k<=2; k++)
    //             {
    //                 cout << dp[i][j][k] << " ";
    //             }
    //         }
    //         cout << "\n"; 
    //     }

    //     return solve(prices, n, 0, 1, 2, dp);   
    // }

    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size(); 
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=1; j++)
            {
                for(int cap=2; cap>=0; cap--)
                {
                    dp[n][j][cap] = 0;
                }
            }
        }

        for(int i=n-1; i>=0; i--)
        {
            for(int buy = 0; buy<=1; buy++)
            {
                for(int cap=2; cap>=1; cap--)
                {
                    int profit = 0; 
                    if(buy)
                        profit = max(-prices[i]+dp[i+1][0][cap], 0+dp[i+1][1][cap]);
                    else 
                        profit = max(prices[i]+dp[i+1][1][cap-1], 0+dp[i+1][0][cap]);
                    
                    dp[i][buy][cap] = profit; 
                }
            }
        }

    //    for (int i = 0; i <= n; i++) {
    //     cout << "Layer " << i << ":\n";
        
    //     for (int j = 0; j <= 1; j++) {
    //         for (int k = 0; k <= 2; k++) {
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout << endl; // Newline after each row
    //     }
        
    //     cout << endl; // Blank line after each layer
    // }

        return dp[0][1][2]; 

    }
};