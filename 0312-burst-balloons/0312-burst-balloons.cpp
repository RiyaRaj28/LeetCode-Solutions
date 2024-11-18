// class Solution {
// public:

//     int solve(int i, int j, vector<int>&nums, vector<vector<int>>&dp)
//     {
//         if(i>j) return 0; 
//         if(dp[i][j] != -1) return dp[i][j];

//         int maxi = INT_MIN; 
//         for(int ind=i; ind<=j; ind++)
//         {
//             int cost = nums[i-1] * nums[ind] * nums[j+1] + solve(i, ind-1, nums, dp) + solve(ind+1, j, nums, dp); 
            
//             maxi = max(maxi, cost); 
//         }
//         return dp[i][j] = maxi; 

//     }

//     int maxCoins(vector<int>& nums) 
//     {
//         nums.push_back(1); 
//         nums.insert(nums.begin(), 1); 
//         int n = nums.size(); 

//         vector<vector<int>>dp(n+2, vector<int>(n+2, -1)); 

//         return solve(1, n-2, nums, dp); 


        
//     }
// };


class Solution {
public:

    int solve(int i, int j, vector<int>&nums, vector<vector<int>>&dp)
    {
        if(i>j) return 0; 
        if(dp[i][j] != -1) return dp[i][j];

        int maxi = INT_MIN; 
        for(int ind=i; ind<=j; ind++)
        {
            int cost = nums[i-1] * nums[ind] * nums[j+1] + solve(i, ind-1, nums, dp) + solve(ind+1, j, nums, dp); 
            
            maxi = max(maxi, cost); 
        }
        return dp[i][j] = maxi; 

    }

    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size(); 

        nums.push_back(1); 
        nums.insert(nums.begin(), 1); 

        //storing 0 as the value in each index as there are 0 balloons bursted initially so value of 0 also
        //also base case is to return 0 when i<j

        vector<vector<int>>dp(n+2, vector<int>(n+2, 0)); 

        // recursion here was bottom up so tabulation has to be top down.
        //
        for(int i=n; i>=1; i--)
        {
            for(int j=1; j<=n; j++)
            {
                if(i>j) continue; 
                int maxi = INT_MIN; 
                for(int ind=i; ind<=j; ind++)
                {
                    int cost = nums[i-1] * nums[ind] * nums[j+1] + dp[i][ind-1] + dp[ind+1][j]; 
                    maxi = max(maxi, cost); 
                }
                dp[i][j] = maxi; 
            }
        }
        return dp[1][n];
    }
};