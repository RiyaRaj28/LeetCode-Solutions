class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int>mpp; 
        int cnt = 0; 
        unordered_map<int, int>m1; 
        for(int i=0; i<n; i++) m1[nums[i]]++; 

        for(int i=0; i<n; i++)
        {
            mpp.clear();
            for(int j=i; j<n; j++)
            {
                mpp[nums[j]]++; 

                if(mpp.size() >= m1.size()) cnt++; 
            }
        }

        return cnt; 




        
    }
};