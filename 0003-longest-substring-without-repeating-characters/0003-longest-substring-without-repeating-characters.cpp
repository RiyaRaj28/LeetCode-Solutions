class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.length(); 
        
        int l = 0, r = 0; 
        int maxcnt = 0; 
        unordered_set<char>st; 
        while(r<n)
        {
            if(st.find(s[r]) != st.end())
            {
                while(st.find(s[r]) != st.end())
                {
                    st.erase(s[l]); 
                    l++;
                }
            }

            st.insert(s[r]); 
            maxcnt = max(maxcnt, r-l+1);
            r += 1; 
        }

        return maxcnt; 

        
    }
};