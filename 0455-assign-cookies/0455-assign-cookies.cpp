class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        // sort(g.begin(), g.end());
        // sort(s.begin(), s.end());

        // //for every greed, we have to check in the size array(in increasing order) if any cookie size is    greater than the greed 

        // int i=0, j=0; 

        // while(j != s.size() && i< g.size())
        // {
        //     int greed = g[i];

        //     if(greed <= s[j])
        //     {
        //         i++; 
        //     }
                
        //     j++; 
        // }

        // return i; 




        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=0, j=0; 
        int n=g.size(), m = s.size();

        while(i<n && j<m)
        {
            if(g[i] <= s[j])
            {
                i++;
                j++;
            }
            else if(g[i] > s[j])
            {
                j++;
            }
        }

        return i;



    










        





















    }
};