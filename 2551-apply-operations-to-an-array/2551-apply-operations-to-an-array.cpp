class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
        int n = nums.size(); 

        for(int i=0; i<n-1; i++)
        {
            if(nums[i] == nums[i+1])
            {
                nums[i] = nums[i]*2; 
                nums[i+1] = 0; 
            }
        }

        int i = 0, j = n-1; 

        // while(i<j)
        // {
        //     while(nums[i] != 0) i++; 
        //     while(nums[j] == 0) j--; 

        //     if(i<j) swap(nums[i], nums[j]); 
        // }

        vector<int>temp(n, 0); 
        int ind = 0; 

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != 0) temp[ind++] = nums[i]; 
        }

        return temp; 
    }
};