class Solution {
public:

    int rec(vector<vector<int>>&queries, int ind, int val, int k, vector<vector<int>>&dp)
    {
        if(val == 0) return k; 
        if(k >= queries.size() || val<0) return queries.size()+1;
        // if(ind < queries[k][0] || ind > queries[k][1]) return queries.size()+1; 

        if(dp[val][k] != -1) return dp[val][k]; 

        int res = rec(queries, ind, val, k+1, dp); 
        if(queries[k][0]<=ind && ind <= queries[k][1]) res = min(res, rec(queries, ind, val-queries[k][2], k+1, dp)); 

        return dp[val][k] = res;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int maxi = -1; 
        int n = nums.size(); 
        for(int i=0; i<n; i++)
        {
            vector<vector<int>>dp(nums[i]+1, vector<int>(queries.size()+1, -1)); 
            int ans = rec(queries, i, nums[i], 0, dp); 
            maxi = max(maxi, ans); 
        }

        return maxi>queries.size() ? -1 : maxi; 
    }
};