class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
         int n = prices.size(); 
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        vector<vector<int>>curr(2, vector<int>(k+1, 0)), ahead(2, vector<int>(k+1, 0)); 
        

        for(int i=n-1; i>=0; i--)
        {
            for(int buy = 0; buy<=1; buy++)
            {
                for(int cap=k; cap>=1; cap--)
                {
                    int profit = 0; 
                    if(buy)
                        profit = max(-prices[i]+ahead[0][cap], 0+ahead[1][cap]);
                    else 
                        profit = max(prices[i]+ahead[1][cap-1], 0+ahead[0][cap]);
                    
                    curr[buy][cap] = profit; 
                }
            }
            ahead = curr; 
        }

        return ahead[1][k]; 
        
    }
};