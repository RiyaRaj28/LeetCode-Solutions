class Solution {
public:

    bool isPossible(vector<int>nums, int k, int mid)
    {
        int n = nums.size(); 
        int houses = 0; 
        for(int i=0; i<n; i++)
        {
            if(nums[i] <= mid)
            {
                houses++; 
                i++; 
            }
        }

        return houses>=k; 
    }

    int minCapability(vector<int>& nums, int k) 
    {
        int l = *min_element(nums.begin(), nums.end()); 
        int r = *max_element(nums.begin(), nums.end()); 
        int res = r; 

        while(l <= r)
        {
            int mid = l + (r-l)/2; 

            if(isPossible(nums, k, mid)) 
            {
                res = mid;
                r = mid-1; 
            }
            else l = mid+1; 
        }
        return res; 
    }
};