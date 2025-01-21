class Solution {
public:

    int subarraysLessThanEqualToK(vector<int>&nums, int goal)
    {   
        int l = 0, r = 0, cnt = 0; 
        int n = nums.size(); 
        int sum = 0; 

        if(goal < 0) return 0; 

        while(r < n)
        {
            sum += nums[r];

            while(l<=r && sum > goal)
            {
                sum -= nums[l];
                l++;
            }

            int curr_len = r - l + 1; 
            cnt += curr_len;
            r++; 
        }

        return cnt;

    }

    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        // int l = 0, r = 0, cnt = 0; 
        // int n = nums.size(); 
        // int sum = 0; 

        // int presum = 0; 

        // unordered_map<int, int>mpp; 
        // mpp[0] = 1;

        // for(int i=0; i<n; i++)
        // {
        //     presum += nums[i];
        //     int remove = presum - goal; 

        //     cnt += mpp[remove]; 
        //     mpp[presum]++;

        // }
        // return cnt; 


        int lessThanK = subarraysLessThanEqualToK(nums, goal);
        int lessThanKMinusOne = subarraysLessThanEqualToK(nums, goal-1);

        return lessThanK - lessThanKMinusOne; 

     
    }
};