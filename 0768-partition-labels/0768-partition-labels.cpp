class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        int n = s.length(); 
        unordered_map<char, int>mpp; 

        int st = 0, e = 0; 
        for(int i=0; i<n; i++)
        {
            mpp[s[i]] = i;
        }

        vector<int>ans; 

        for(int i=0; i<n; i++)
        {
            e = max(e, mpp[s[i]]); 

            if(i == e)
            {
                ans.push_back(e-st+1); 
                st = e+1; 
            }
        }

        return ans; 
        
    }
};