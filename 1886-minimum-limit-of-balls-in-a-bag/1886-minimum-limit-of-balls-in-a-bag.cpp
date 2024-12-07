class Solution {
public:

    bool isPossible(int mid, vector<int>&nums, int maxOperations)
    {
        //if possible to get mid as the max in maxOps num of steps
        int totalOps = 0; 
        for(int &num : nums)
        {
            int ops = num/mid;

            if(num % mid == 0) ops--; 

            totalOps += ops;  
        }
        return totalOps<=maxOperations; 
    }

    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        // max heap wont work here!!!

        // binary search for the minimum most max value possible
        int l = 1; 
        int r = *max_element(begin(nums), end(nums)); 
        int result = r; 

        while(l<=r)
        {
            int mid = l + (r-l)/2; 

            if(isPossible(mid, nums, maxOperations))
            {
                result = mid; 
                r = mid-1; 
            }
            else 
            {
                l = mid+1; 
            }
        }
        return result;    
    }
};