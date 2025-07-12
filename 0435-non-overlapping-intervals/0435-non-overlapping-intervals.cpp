class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) 
    {
        int n = inter.size(); 
        sort(inter.begin(), inter.end());

        int i = 0, j = 1; 
        int cnt = 0; 
        while(j<n)
        {
            int cs = inter[i][0];
            int ce = inter[i][1]; 

            int ns = inter[j][0];
            int ne = inter[j][1];

            if(ce <= ns)
            {
                i = j;
                j += 1;
            }
            else if(ce <= ne)
            {
                j += 1; 
                cnt += 1;
            }
            else if(ce > ne)
            {
                i = j; 
                j += 1;
                cnt += 1;
            }
        }    
        return cnt; 
    }
};