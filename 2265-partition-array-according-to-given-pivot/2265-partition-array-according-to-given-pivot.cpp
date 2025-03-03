class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int>t1, t2, t3; 

        int n = nums.size(); 
        for(int i=0; i<n; i++)
        {
            if(nums[i] < pivot) t1.push_back(nums[i]); 
            else if(nums[i] > pivot) t2.push_back(nums[i]); 
            else t3.push_back(nums[i]); 
        }

        vector<int>ans; 
        for(int i=0; i<t1.size(); i++) ans.push_back(t1[i]); 
        for(int i=0; i<t3.size(); i++) ans.push_back(t3[i]); 
        for(int i=0; i<t2.size(); i++) ans.push_back(t2[i]); 

        return ans; 
        
        
    }
};