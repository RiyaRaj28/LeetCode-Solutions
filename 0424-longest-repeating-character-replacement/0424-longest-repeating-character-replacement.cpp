class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int l = 0, r = 0; 
        int maxlen = 0; 
        int n = s.length();
        unordered_map<int, int>mpp; 

        int maxFreq = 0; 
        while(r<n)
        {
            mpp[s[r]]++;
            maxFreq = max(maxFreq, mpp[s[r]]);

            while( (r - l + 1) - maxFreq > k)
            {
                mpp[s[l]]--;
                l++;
            }

            maxlen = max(maxlen, r-l+1);
            r++;
        }
 
        return maxlen; 

        
    }
};