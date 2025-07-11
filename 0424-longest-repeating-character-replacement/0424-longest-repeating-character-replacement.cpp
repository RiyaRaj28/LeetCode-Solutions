class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int maxfreq = 0; 
        map<int, int>mpp; 
        int maxlen = 0; 

        int n = s.length(); 
        int l = 0, r = 0; 
        while(r<n)
        {
            mpp[s[r]]++;
            maxfreq = max(maxfreq, mpp[s[r]]);

            if((r-l+1) - maxfreq > k)
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