class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        //sliding window 
        int l = 0, r = 0; 
        int maxlen = 0; 
        int n = s.length(); 
        unordered_set<int>st; 
        int len = 0; 

        // while(r<n)
        // {
        //     if(st.find(s[r]) == st.end())
        //     {
        //         st.insert(s[r]);
        //         r++; 
        //         len = r-l; 
        //     }
        //     else
        //     {
        //         while(s[l] != s[r])
        //         {
        //             st.erase(s[l]);
        //             l++;
        //         }
        //         st.erase(s[l]);
        //         l++; 
        //     }

        //     maxlen = max(maxlen, len); 
        // }
        // return maxlen; 
        
        for(int r=0; r<n; r++)
        {
            if(st.find(s[r]) != st.end())
            {
                while(l<r && st.find(s[r])!= st.end())
                {
                    st.erase(s[l]);
                    l++; 
                }
            }
            
            st.insert(s[r]);
            maxlen = max(maxlen, r-l+1); 
        }
        return maxlen; 
    }
};