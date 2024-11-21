class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size()+1; 
        for(int i=0; i<=n; i++)
        {
            bool flag = false; 
            for(int j=0; j<n-1; j++)
            {
                if(i == nums[j]) 
                {
                    flag = true;
                    break;
                }
            }
            if(flag == false) return i;
        }
        return 0; 
        
    }
};