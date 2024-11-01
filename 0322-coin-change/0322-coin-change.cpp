class Solution {
public:

    // int solve(vector<int>&arr, int ind, int target, vector<vector<int>>&dp)
    // {
    //     if(ind == 0)
    //     {
    //         if(target % arr[ind] == 0) return target/arr[ind]; 
    //         else return 1e9; 
    //     }

    //     if(dp[ind][target] != -1) return dp[ind][target]; 

    //     int nottake = solve(arr, ind-1, target, dp);
    //     int take = 1e9; 
    //     if(arr[ind] <= target) take = 1 + solve(arr, ind, target - arr[ind], dp); 

    //     return dp[ind][target] = min(take, nottake);
    // }

    // int coinChange(vector<int>& coins, int amount) 
    // {
    //     int n = coins.size();
    //     vector<vector<int>>dp(n, vector<int>(amount+1, -1));

    //     int ans = solve(coins, n-1, amount, dp); 

    //     if(ans == 1e9) return -1; 
    //     return ans; 
    // }

    // int coinChange(vector<int>& coins, int target)
    // {
    //     int n = coins.size(); 
    //     vector<vector<int>>dp(n, vector<int>(target+1, 0));

    //     for(int i=0; i<=target; i++)
    //     {
    //         if(i % coins[0] == 0) dp[0][i] = i/coins[0]; 
    //         else dp[0][i] = 1e9; 
    //     }

    //     for(int i=1; i<n; i++)
    //     {
    //         for(int targ = 0; targ<= target; targ++)
    //         {
    //             int nottake = dp[i-1][targ];
    //             int take = 1e9; 
    //             if(coins[i] <= targ) take = 1+ dp[i][targ - coins[i]];

    //             dp[i][targ] = min(take, nottake);  
    //         }
    //     }

    //     int ans = dp[n-1][target]; 
    //     if(ans >= 1e9) return -1; 
    //     else return ans; 
    // } 

    int coinChange(vector<int>& coins, int target)
    {
        int n = coins.size(); 
        // vector<vector<int>>dp(n, vector<int>(target+1, 0));
        vector<int>prev(target+1, 0), curr(target+1, 0);

        for(int i=0; i<=target; i++)
        {
            if(i % coins[0] == 0) prev[i] = i/coins[0]; 
            else prev[i] = 1e9; 
        }


        for(int i=1; i<n; i++)
        {
            for(int targ = 0; targ<= target; targ++)
            {
                int nottake = prev[targ];
                int take = 1e9; 
                //dont go to previous here
                if(coins[i] <= targ) take = 1+ curr[targ - coins[i]];

                curr[targ] = min(take, nottake);  
            }
            prev = curr; 
        }

        int ans = prev[target]; 
        if(ans >= 1e9) return -1; 
        else return ans; 
    } 
};