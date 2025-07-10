class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int>st; 
        for(int i=0; i<nums.size(); i++)
        {
            st.insert(nums[i]); 
        }
        int maxcnt = 0; 
        
        for(auto it : st)
        {
            if(st.find(it-1) == st.end())
            {
                int x = it; 
                int cnt = 1; 

                while(st.find(x+1) != st.end())
                {
                    x = x+1; 
                    cnt++; 
                }
                maxcnt = max(maxcnt, cnt); 

            }
            
        }

        return maxcnt; 
    }
};