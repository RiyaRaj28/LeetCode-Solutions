class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int neg = 0; 
        int zeros = 0; 
        int n = nums.size(); 

        for(int i=0; i<n; i++)
        {
            if(nums[i]<0) neg++; 
            else if(nums[i] == 0) zeros++; 
            else break; 
        }

        int pos = n - neg - zeros; 

        return max(neg, pos); 
        
    }
};