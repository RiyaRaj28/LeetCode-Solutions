class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) 
    {
        
        int n = nums.size(); 
        vector<long long>prev(k, 0); 
        vector<long long>curr(k, 0); 
        vector<long long>ans(k, 0); 

        for(int i=0; i<n; i++)
        {
            int num = nums[i] % k; 
            for(int i=0; i<k; i++) curr[i] = 0; 

            curr[num]++; 

            for(int rem=0; rem<k; rem++)
            {
                curr[(rem*num)%k] += prev[rem]; 
            }

            prev = curr; 
            for(int i=0; i<k; i++) ans[i] += prev[i]; 
        }

        return ans; 
    }
};