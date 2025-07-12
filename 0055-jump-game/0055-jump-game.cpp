class Solution {
public:
    bool canJump(vector<int>& nums) {

        int max_poss = 0; 
        int max_step = 0; 
        for(int i=0; i<nums.size(); i++)
        {
            if(i>max_poss) return false; 

            max_step = i + nums[i]; 
            max_poss = max(max_poss, max_step); 
        }

        return true; 
        
    }
};