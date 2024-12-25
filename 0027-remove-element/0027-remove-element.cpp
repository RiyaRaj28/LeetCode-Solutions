class Solution {
public:
    int removeElement(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int i = 0; 
        int j = n - 1; 

        if(nums.size() == 1)
        {
            if(nums[0] == k) return 0; 
            else return 1; 
        }

        while(i < j)
        {
            while(i<n && nums[i] != k) i++;  
            while(j>=0 && nums[j] == k ) j--; 

            if(i<j)
                swap(nums[i], nums[j]); 
        }
        cout << i; 
        return i; 
        
        
    }
};