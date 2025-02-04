class Solution {
public:
    int maxAscendingSum(vector<int>& nums) 
    {
        // if the next elmeent is greater than prev then incerese the sum 
        // else set the sum to 0 
        // maintian a maxsum 

        int maxsum = 0; 
        int sum = 0; 
        int n = nums.size(); 
        int curr = INT_MIN; 

        for(int i=0; i<n; i++)
        {
            if(nums[i] > curr) sum += nums[i];
            else sum = nums[i]; 

            curr = nums[i]; 

            maxsum = max(maxsum, sum); 
            
        }

        return maxsum; 
        
    }
};