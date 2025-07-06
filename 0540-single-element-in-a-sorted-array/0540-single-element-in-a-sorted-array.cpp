class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(); 
        int l = 0, r = n-1; 

        while(l<r)
        {
            int m = l + (r-l)/2; 

            if(m%2 == 1) m = m-1; 

            if(nums[m] != nums[m+1]) r = m; 
            else l = m+2; 
        }

        return nums[l]; 
    }
};