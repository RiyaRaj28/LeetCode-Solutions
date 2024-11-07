class Solution {
public:

    // int solve(int ind, int prev, int n, vector<int>&nums)
    // {
    //     if(ind == n) return 0; 

    //     int nottake = solve(ind+1, prev, n, nums);
    //     int take = INT_MIN; 
    //     if(prev == -1 || nums[prev] < nums[ind])
    //         take = 1 + solve(ind+1, ind, n, nums);

    //     return max(take, nottake); 
    // }

    // int lengthOfLIS(vector<int>& nums) 
    // {
    //     int n = nums.size();
    //     return solve(0, -1, n, nums); 
        
    // }

    // MEMOISATION 

    //     int solve(int ind, int prev, int n, vector<int>&nums, vector<vector<int>>&dp)
    // {
    //     if(ind == n) return 0; 

    //     if(dp[ind][prev+1] != -1) return dp[ind][prev+1]; 

    //     int nottake = solve(ind+1, prev, n, nums, dp);
    //     int take = INT_MIN; 
    //     if(prev == -1 || nums[prev] < nums[ind])
    //         take = 1 + solve(ind+1, ind, n, nums, dp);

    //     return dp[ind][prev+1] = max(take, nottake); 
    // }

    // int lengthOfLIS(vector<int>& nums) 
    // {
    //     int n = nums.size();
    //     vector<vector<int>>dp(n, vector<int>(n+1, -1));
    //     return solve(0, -1, n, nums, dp); 
        
    // }

// TABULATION !!!
// int lengthOfLIS(vector<int>& nums) 
//     {
//         int n = nums.size(); 
//          vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        
//         for(int i=n-1; i>-1; i--)
//         {
//             for(int prev = i-1; prev >= -1; prev--)
//             {
//                 int nottake = dp[i+1][prev+1]; 
//                 int take = INT_MIN; 
//                 if(prev == -1 || nums[i] > nums[prev])
//                 {
//                     take = 1 + dp[i+1][i+1]; 
//                 }
                
//                 dp[i][prev+1] = max(take, nottake); 
//             }
//         }
        
//         return dp[0][0]; 
//     }


// SPACE OPTIMISED

int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size(); 
         vector<int>front(n+1), curr(n+1); 
        
        for(int i=n-1; i>-1; i--)
        {
            for(int prev = i-1; prev >= -1; prev--)
            {
                int nottake = front[prev+1]; 
                int take = INT_MIN; 
                if(prev == -1 || nums[i] > nums[prev])
                {
                    take = 1 + front[i+1]; 
                }
                
                curr[prev+1] = max(take, nottake); 
            }

            front = curr; 
        }
        
        return front[0]; 
    }
};