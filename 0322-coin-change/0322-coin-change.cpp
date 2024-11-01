class Solution {
public:

    int solve(vector<int>&arr, int ind, int target, vector<vector<int>>&dp)
    {
        if(ind == 0)
        {
            if(target % arr[ind] == 0) return target/arr[ind]; 
            else return 1e9; 
        }

        if(dp[ind][target] != -1) return dp[ind][target]; 

        int nottake = solve(arr, ind-1, target, dp);
        int take = 1e9; 
        if(arr[ind] <= target) take = 1 + solve(arr, ind, target - arr[ind], dp); 

        return dp[ind][target] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));

        int ans = solve(coins, n-1, amount, dp); 

        if(ans == 1e9) return -1; 
        else return ans; 
    }
};