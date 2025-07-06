class Solution {
public:
    int numberOfSubstrings(string s, int k) 
    {
        int cnt = 0; 
        int n = s.length(); 
        int l = 0; 
        unordered_map<char, int>mpp; 

        for(int i=0; i<n; i++)
        {
            mpp[s[i]] += 1; 

            while(mpp[s[i]] == k)
            {
                mpp[s[l]]--; 
                l++;
            }
            cnt += l; 
        }

        return cnt; 
        
        
    }
};