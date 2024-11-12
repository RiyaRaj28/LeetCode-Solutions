class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>count(n, 1), length(n, 1);
        int maxi = 0; 

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i]>nums[j] && length[j]+1 > length[i])
                {
                    length[i] = length[j]+1;
                    count[i] = count[j];
                }
                else if(nums[i]>nums[j] && length[j]+1 == length[i])
                {
                    count[i] += count[j]; 
                } 
            }
            //update max length
            maxi = max(maxi, length[i]);
        }

        //now fetch the count of the max length 
        int nos = 0; 
        for(int i=0; i<n; i++)
        {
            if(length[i] == maxi) nos += count[i];
        }

        return nos;     
        
    }
};