class Solution {
public:

    int iterativeBS(vector<int>&nums, int target)
    {
        int n = nums.size(); 
        int low = 0, high = n-1; 
        while(low < high)
        {
            int mid = low + (high-low)/2; 

            if(nums[mid] < target) low = mid+1; 
            else if(nums[mid] > target) high = mid-1; 
            else return mid; 
        }

        return -1; 
    }

    int recursiveBS(vector<int>&nums, int target, int low, int high)
    {
        int n = nums.size(); 
        // if(index == n) return -1; 
        // if(nums[index] == target) return index; 
        // if(high > nums.size()-1 || low < 0) return -1; 
        if(low > high) return -1; 

        int mid = low + (high-low)/2; 

        if(nums[mid] == target) return mid; 
        else if(nums[mid] > target) return recursiveBS(nums, target, low, mid-1); 
        else return recursiveBS(nums, target, mid+1, high); 

        return -1; 

    }

    int search(vector<int>& nums, int target) 
    {
        int n = nums.size(); 
        // return iterativeBS(nums, target);
        return recursiveBS(nums, target, 0, n-1);
        
    }
};