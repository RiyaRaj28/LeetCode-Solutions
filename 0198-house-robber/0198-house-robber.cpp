class Solution {
public:
    
    // int solve(vector<int>&dp, int i, vector<int>nums)
    // {
    //     if(i >= nums.size()) return 0; 
    //     if(dp[i] != -1) return dp[i];

    //     int take = nums[i] + solve(dp, i+2, nums);
    //     int skip = solve(dp, i+1, nums);

    //     return dp[i] = max(take, skip);
    // }

    // int rob(vector<int>& nums) {
    //     int n = nums.size();

    //     vector<int> dp(n, -1);
    //     return solve(dp, 0, nums);        
    // }


    // WAY 2
    // int solve(int s, int i, int n, vector<int>nums)
    // {
    //     if(i >= n) return s; 

    //     s += nums[i];

    //     int took = solve(s, i+2, n, nums);

    //     s -= nums[i];

    //     int left = solve(s, i+1, n, nums);

    //     return max(left, took);
    // }

    // int rob(vector<int>& nums) 
    //     {
    //         int s = 0; 
    //         int n = nums.size();
    //         return solve(s, 0, n, nums);

    //     }

    //way 3 -> like way1 only 
    // int solve(int i, int n, vector<int>nums, vector<int>&dp)
    // {
    //     if(i >= n) return 0;
    //     if(dp[i] != -1) return dp[i]; 

        
    //     int took = nums[i] + solve(i+2, n, nums, dp);
    //     int left = solve(i+1, n, nums, dp);

    //     return dp[i] = max(left, took);
    // }

    // int rob(vector<int>& nums) 
    // {
    //     int n = nums.size();
    //     vector<int> dp(n, -1);
    //     return solve(0, n, nums, dp);

    // }

    // tabulation

    // int rob(vector<int>& nums){

    //     int n = nums.size();
    //     vector<int> dp(n, -1);

    //     dp[0] = nums[0];
    //     for(int i=1; i<n; i++)
    //     {
    //         int pick = nums[i];
    //         if(i>1) pick += dp[i-2];

    //         int nonpick = dp[i-1];

    //         dp[i] = max(pick, nonpick);
    //     }

    //     return dp[n-1];
    // }

    //SPACE OPTIMISATION
    int rob(vector<int>& nums){

        int n = nums.size();
        int p1 = nums[0];
        int p2 = 0;
        for(int i=1; i<n; i++)
        {
            int pick = nums[i];
            if(i>1) pick += p2;

            int nonpick = p1;

            int curr = max(pick, nonpick);
            p2 = p1;
            p1 = curr;
        }

        return p1;
    }



};