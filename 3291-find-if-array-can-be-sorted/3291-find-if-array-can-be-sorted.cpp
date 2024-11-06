class Solution {
public:
    bool canSortArray(vector<int>& nums) 
    {
        int n = nums.size();
        //run the loop n-1 times 
        for(int i=0; i< nums.size(); i++)
        {
            for(int j=0; j<n-i-1; j++)
            {
                if(nums[j] <= nums[j+1]) continue; 
                else 
                {
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1]))
                    {
                        int temp = nums[j];
                        nums[j] = nums[j+1];
                        nums[j+1] = temp; 
                        
                    }
                    else return false; 
                }
            }
            
        }

        return true; 
        
    }
};