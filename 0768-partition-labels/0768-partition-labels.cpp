class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        unordered_map<char, pair<int, int>>mpp; 
        for(int i=0; i<s.length(); i++)
        {
            if(mpp.find(s[i]) == mpp.end()) mpp[s[i]] = {i, i}; 
            else mpp[s[i]].second = i; 
        }

        // for(auto it : mpp) cout << it.first << " -> " << it.second.first << " " << it.second.second << endl; 

        int start = mpp[s[0]].first, end = mpp[s[0]].second; 

        int n = s.length(); 
        vector<int>ans;
        while(start < n && end < n)
        {
            for(int i=start+1; i<end; i++)
            {
                end = max(end, mpp[s[i]].second);
            }
            ans.push_back(end-start+1); 

            start = end+1; 
            end = mpp[s[start]].second; 
        }

        return ans; 
        
    }
};