class Solution {
public:
    int maximumGap(vector<int>& nums) {
         int gap = 0;
        
        if (nums.size() == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        for (int i = 0; i < n - 1; i++) {
            int sub = nums[i + 1] - nums[i];
            
            if (sub > gap) {
                gap = sub;
            }
        }
        
        return gap;
    }
};