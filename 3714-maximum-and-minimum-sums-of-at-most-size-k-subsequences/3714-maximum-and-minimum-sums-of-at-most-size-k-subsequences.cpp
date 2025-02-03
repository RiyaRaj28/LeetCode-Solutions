#define ll long long
class Solution {
public:
    const int MOD = 1e9 + 7; 
    // int recursion(int ind, int cnt, long long mini, long long maxi, vector<int>&nums, int k, int n, vector<vector<long long>>&dp)
    // {
    //     if(cnt == k || ind == n)
    //     {
    //         // if(maxi != LLONG_MIN && mini != LLONG_MAX) return (maxi+mini)%MOD; 
    //         // else return 0; 

    //         return (cnt > 0) ? (maxi + mini)%MOD : 0;
    //     }

    //     if(dp[ind][cnt] != -1) return dp[ind][cnt]; 

    //     int include = recursion(ind+1, cnt+1, min(mini, (long long)nums[ind]), max(maxi, (long long)nums[ind]), nums, k, n, dp);
    //     int notinclude = recursion(ind+1, cnt, mini, maxi, nums, k, n, dp);

    //     return dp[ind][cnt] = (include+notinclude)%MOD; 
    // }



    // int minMaxSums(vector<int>& nums, int k) 
    // {
    //     int n = nums.size();
    //     vector<vector<long long>>dp(n, vector<long long>(k+1, -1));

    //     return recursion(0, 0, LLONG_MAX, LLONG_MIN, nums, k, n, dp)%MOD;
    //     // return dp[n-1][k];
    // }



    ll rec(int ind, int k, vector<vector<ll>>& dp)
    {
        if(k == 1 || ind == 0) return 1; 

        if(dp[ind][k] != -1) return dp[ind][k]; 

        return dp[ind][k] = (rec(ind-1, k, dp) + rec(ind-1, k-1, dp))%MOD; 
    }


    int minMaxSums(vector<int>& nums, int k) 
    {
        ll n = nums.size();
        sort(nums.begin(), nums.end()); 
        vector<vector<ll>>dp(n+1, vector<ll>(k+1, -1));
        int sum = 0; 
        for(int i=0; i<nums.size(); i++)
        {
            ll mini = (nums[i]*rec(n-i-1, k, dp))%MOD; 
            ll maxi = (nums[i]*rec(i, k, dp))%MOD; 

            sum = (sum + maxi + mini)%MOD;
        }
        return sum;
    }




















};