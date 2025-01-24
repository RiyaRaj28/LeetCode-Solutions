class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //brute : using stl 
        if(next_permutation(nums.begin(), nums.end()) ==true)
        {
            return; 
        }
        else
        {
            sort(nums.begin(), nums.end());        
        }

        //logic of the stl 
        // int index = -1; 
        // int n = nums.size(); 
        // for(int i=n-2; i>=0; i--)
        // {
        //     if(nums[i]<nums[i+1]) 
        //     {
        //         index = i; 
        //         break;
        //     }
        // }

        // if(index==-1) 
        // {
        //     reverse(nums.begin(), nums.end());
        //     return; 
        // }

        // for(int i= n-1; i>index; i--)
        // {
        //     if(nums[i]>nums[index]) 
        //         {swap(nums[index], nums[i]);
        //         break; 
        //         }
        // }

        // reverse(nums.begin() + index + 1, nums.end());         
    }
};