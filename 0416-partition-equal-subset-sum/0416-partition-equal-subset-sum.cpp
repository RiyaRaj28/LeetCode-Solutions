class Solution {
public:

    bool isPossible(vector<int>&arr, int k)
    {
        int n = arr.size();

        //have to make a 2d table with target and index
        //just store the base cases in the table 
        vector<bool>prev(k+1, false), curr(k+1, false);
        prev[0] = curr[0] = true;  // here the index 0 of prev and curr shows that we need to acheive a target of 0. If we need to achieve a target of 0, that means that it is possible, thus true 
        if(arr[0] <= k) prev[arr[0]] = true; // prev[target] = 0 here because we want to 
        // get a value of arr[0] in order to complete our target, thus at the arr[0], we have target value equal to the index, that is arr[0], so we got our target 

        for(int i=1; i<n; i++)
        {
            for(int target = 1; target <= k; target++)
            {
                bool take = arr[i] <= target ? prev[target-arr[i]] : false; 
                // check the previous values, if we get the remaning value of target at the index, then return that value else false 
                bool nottake = prev[target];
                curr[target] = take | nottake;
            }
            prev = curr;
        }
        return prev[k];
    }

    bool canPartition(vector<int>& nums) 
    {
        //here the sum we need to find is ultimately just s/2
        //if sum is even then only possible else it is not 

        int sum = 0; 
        int n = nums.size(); 
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
        }

        if(sum % 2 != 0) return false; 
        else return isPossible(nums, sum/2); 
    }
};