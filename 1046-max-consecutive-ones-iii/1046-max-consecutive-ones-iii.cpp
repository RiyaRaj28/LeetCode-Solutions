class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int n = nums.size(); 
        map<int, int>mpp; 
        int l = 0, r = 0; 
        int cnt0 = 0; 
        int maxlen = 0; 
        while(r<n)
        {
            if(nums[r] == 0) cnt0 += 1;

            while(cnt0 > k)
            {
                if(nums[l] == 0)
                {
                    cnt0--; 
                }
                l += 1; 
            }

            maxlen = max(maxlen, r-l+1);
            r += 1; 
        }

        return maxlen; 
        
    }
};