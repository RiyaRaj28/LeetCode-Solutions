class Solution {
public:

    // int solve(int ind, )
    // int findTargetSumWays(vector<int>& nums, int target) 
    // {
    //     // divide the entire array into two subsets -> 
    //     // one subset will have only pos and the other should have all neg
    //     // elements 
    //     // their absolute difference? 
    //     // the s1-> positive should be larger 
    //     int n = nums.size();

    //     //modify target as per subset sum
    //     int sum = 0; 
    //     for(int i=0; i<n; i++)
    //     {
    //         sum += nums[i]; 
    //     }

    //     if(sum - target < 0) return 0; 
    //     if((sum - target)%2 != 0) return 0; 
    //     int s1 = (sum-target)/2; 

    //     vector<vector<int>>dp(n, vector<int>(s1+1, 0)); 
        
    //     // for(int i=0; i<n; i++) dp[0][i] = 1; 
    //     // if(nums[0] <= target) dp[nums[0]] = 1; 

    //     if(nums[0] == 0) dp[0][0] = 2; 
    //     else dp[0][0] = 1; 

    //     if(nums[0] != 0 && nums[0]<=s1) dp[0][nums[0]] = 1; 

    //     for(int i=1; i<n; i++)
    //     {
    //         for(int targ = 0; targ<=s1; targ++)
    //         {
    //             int nottake = dp[i-1][targ]; //taking into first subset
    //             int take = 0; 
    //             if(nums[i] <= targ) take = dp[i-1][targ - nums[i]];

    //             dp[i][targ] = take + nottake; 
    //         }
    //     }

    //     return dp[n-1][s1]; 
    // }

    // int solve(vector<int>&nums, int target, int ind)
    // {
    //     int n = nums.size(); 
    //     // if(target == 0) return 1; 
    //     // if(ind >= n) return 0; 

    //     if(ind == n) return target == 0 ? 1 : 0;

    //     int sum = solve(nums, target-nums[ind], ind+1); 
    //     int sub = solve(nums, target+nums[ind], ind+1); 
    //     return sum+sub; 
    // }


    // int findTargetSumWays(vector<int>& nums, int target) 
    // {
    //     return solve(nums, target, 0); 
        
    // }









    int solve(vector<int>&nums, int target, int ind)
    {
        if(ind < 0) return 0; 
        
        if(ind == 0)
        {
            if(target == 0 && nums[0] == 0) return 2; 
            else if(target == 0 || nums[0] == target) return 1; 
            else return 0; 
        }
        

        //have to find target sum only simply 
        // rest func will handle 

        int take = nums[ind] <=target ? solve(nums, target-nums[ind], ind-1) : 0;
        int nottake = solve(nums, target, ind-1);

        return take+nottake; 
    }


    // have to count the partitions with difference 0 
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        // return solve(nums, target, 0); 
        // int final_target = (target/2);
        // if(final_target%2 != 0) return 0; 
        int n = nums.size();

        int sum = 0; 
        for(int i=0; i<n; i++) sum += nums[i]; 
 
        if(sum - target < 0) return 0; 
        if((sum-target)%2 != 0) return 0; 
        int targ = (sum-target)/2; 

        return solve(nums, targ, n-1);
        
    }















};