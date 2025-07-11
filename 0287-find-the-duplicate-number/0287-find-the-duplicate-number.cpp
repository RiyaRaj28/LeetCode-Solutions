class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         int n = nums.size(); 
        int ans = -1;

        for(int i=0; i<n; i++)
        {
            int ind = abs(nums[i]) - 1; 
            if(nums[ind] < 0)
            {
                ans = ind+1; 
                break; 
            }

            nums[ind] *= -1;
        }

        return abs(ans); 
        
    }
};