class Solution {
public:
    int subarraySum(vector<int>& nums) 
    {
        int n = nums.size(); 
        int sum = 0; 

        for(int i=0; i<n; i++)
        {
            int start = max(0, i-nums[i]); 
            int temp = 0; 

            for(int j=start; j<=i; j++)
            {
                temp += nums[j]; 
            }

            sum += temp; 
        }
        return sum; 
    }
};