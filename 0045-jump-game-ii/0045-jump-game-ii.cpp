class Solution {
public:

    int rec(vector<int>&nums, int n, int ind)
    {
        if(ind >= n-1) return 0; 

        int steps = INT_MAX;
        for(int i=1; i<=nums[ind]; i++)
        {
            int next = rec(nums, n, ind+i);
            if(next != INT_MAX)
            {
                steps = min(steps, next+1);
            }
            
        }
        return steps; 
    }

    int jump(vector<int>& nums) 
    {
        // int minsteps = INT_MAX;
        int n = nums.size(); 
        int ans = rec(nums, n, 0); 
        if(ans == INT_MAX) return -1;
        return ans;  
    }
};