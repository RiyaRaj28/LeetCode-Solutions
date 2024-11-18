class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        //for every greed, we have to check in the size array(in increasing order) if any cookie size is    greater than the greed 

        int i=0, j=0; 

        while(j < s.size() && i< g.size())
        {
            int greed = g[i];

            if(greed <= s[j])
            {
                i++; 
            }
                
            j++; 
        }

        return i; 
    }
};