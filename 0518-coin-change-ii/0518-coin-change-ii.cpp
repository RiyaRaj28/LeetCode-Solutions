class Solution {
public:

    int recur(vector<int>&coins, int index, int amt, vector<vector<int>>&memo)
    {
        if(amt == 0) return 1; 
        if(amt < 0 || index < 0) return 0; 

        if(memo[index][amt] != -1) return memo[index][amt]; 

        int nottaken = recur(coins, index-1, amt, memo); 
        int taken = 0; 
        if(amt - coins[index] >= 0) 
            taken = recur(coins, index, amt-coins[index], memo); 

        return memo[index][amt] = taken + nottaken; 
    }

    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size(); 
        // vector<vector<int>>memo(n, vector<int>(amount+1, -1)); 
        // return recur(coins, n-1, amount, memo); 

        vector<vector<long long>>dp(n, vector<long long>(amount+1, 0)); 
        // dp[0][0] = 1;

        for(int targ=0; targ<=amount; targ++)
        {
            if(targ % coins[0] == 0) dp[0][targ] = 1;
        }

        for(int i=1; i<n; i++)
        {
            for(int targ = 0; targ <= amount; targ++)
            {
                int nottaken = dp[i-1][targ];

                int taken = 0; 
                if(targ - coins[i] >= 0)
                {
                    taken = dp[i][targ- coins[i]]; 
                }

                dp[i][targ] = (long long)taken + (long long)nottaken; 
            }
        }

        return dp[n-1][amount]; 
        
        
    }
};