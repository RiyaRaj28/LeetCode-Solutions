class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size() == 0) return 0; 
        sort(nums.begin(), nums.end()); 

        unordered_set<int>st; 
        int cnt = 1; 
        int maxcnt = 1; 
        for(int i=1; i<nums.size(); i++)
        {
            // if(st.find(nums[i] - 1) != st.end())
            // {
            //     cnt += 1; 
            //     maxcnt = max(maxcnt, cnt);
            // }
            // else cnt = 1; 

            // st.insert(nums[i]); 
            if(nums[i] == nums[i-1]) continue; 

            if(nums[i] - 1 == nums[i-1]) 
            {
                cnt++; 
                maxcnt = max(maxcnt, cnt); 
            }
            else cnt = 1; 


        }
        return maxcnt; 
        
    }
};