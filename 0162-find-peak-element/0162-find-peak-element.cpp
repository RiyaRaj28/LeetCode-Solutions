class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int n = nums.size(); 
        int l = 0, r = n-1; 

        while(l<=r)
        {
            int mid = l + (r-l)/2; 

            // if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) return mid; 
            if(l == r) return mid; 
            else if(nums[mid] > nums[mid+1]) 
            {
                r = mid; 
            }
            else
            {
                l = mid+1; 
            }
            
            
        }

        return -1; 

        
    }
};