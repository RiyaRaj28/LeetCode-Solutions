class Solution {
public:
    int minSteps(string s, string t) 
    {
        map<char, int>mpp; 

        for(int i=0; i<s.length(); i++)
        {
            mpp[s[i]]++; 
        }

        for(int i=0; i<t.length(); i++)
        {
            mpp[t[i]]--; 
        }

        int cnt = 0; 
        for(auto it : mpp)
        {
            cnt += abs(it.second); 
        }

        return cnt/2;
        
    }
};