class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        // int l = 0, r = 0; 

        int n = nums.size();
        unordered_map<int, int>mpp; 
        int l = 0, r = k-1; 
        // for(int i=0; i<=r; i++) mpp[nums[i]]++; 
        
        while(r < n)
        {
            // for(int i=l; i<=r; i++) 
            // {
                set<int>st; 
                for(int i=l; i<=r; i++) st.insert(nums[i]); 

                for(auto it : st) mpp[it]++; 
                // mpp[nums[i]]++;
            // } 
            l += 1; 
            r += 1; 

            
        }

        int maxi = -1; 

        for(auto it : mpp)
        {
            if(it.second == 1) maxi = max(maxi, it.first); 
        }

        return maxi; 

    }
};