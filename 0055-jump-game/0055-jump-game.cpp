class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxpos = 0; 
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(i>maxpos) return false; 
            maxpos = max(maxpos, i + nums[i]);
        }
        return true;   
    }
};