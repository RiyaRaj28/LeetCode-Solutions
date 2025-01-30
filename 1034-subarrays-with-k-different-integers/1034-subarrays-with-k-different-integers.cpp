class Solution {
public:
    int lessThanKCnt(vector<int>&nums, int k)
    {
        // if(k<0) return 0; 
        unordered_map<int, int>mpp;  
        int l = 0, r = 0; 
        int n = nums.size(); 
        int count = 0; 

        while(r<n)
        {
            mpp[nums[r]]++; 
            // if(mpp.size() <= k) count += r-l+1; 

            while(mpp.size() > k)
            {
                mpp[nums[l]]--; 
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]); 
                l += 1; 
            }

            count += r-l+1; 
            r += 1; 
        }

        return count; 
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        int lessThanK = lessThanKCnt(nums, k);
        int lessThanKMinusOne = lessThanKCnt(nums, k-1);

        return lessThanK - lessThanKMinusOne; 


    }
    
    // int subarraysWithKDistinct(vector<int>& nums, int k) 
    // {   
    //     map<int, int>mpp; 
    //     int count = 0; 
        
    //     int i = 0, j = 0; 
    //     int n = nums.size(); 
    //     for(int i=0; i<n; i++)
    //     {
    //         mpp.clear(); 
    //         for(int j=i; j<n; j++)
    //         {
    //             mpp[nums[j]]++; 
    //             if(mpp.size() == k) count += 1; 
    //             else if(mpp.size() > k) break; 
    //         }

    //     }
        
    //     return count; 
        
    // }
};