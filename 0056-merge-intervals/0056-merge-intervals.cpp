class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size(); 
        sort(intervals.begin(),intervals.end()); 

        // int ps = intervals[0][0]; 
        // int pe = intervals[0][1]; 
        // vector<vector<int>>ans; 

        // for(int i=1; i<n; i++)
        // {
        //     int ns = intervals[i][0]; 
        //     int ne = intervals[i][1]; 

        //     if(ns > pe)
        //     {
        //         ans.push_back({ps, pe}); 
        //         ps = ns; 
        //         pe = ne; 
        //     }
        //     else
        //     {
        //         ps = min(ps, ns); 
        //         pe = max(pe, ne); 
        //     }
        // }

        // ans.push_back({ps, pe}); 

        // return ans; 


        vector<vector<int>>ans; 
        // int n = intervals.size(); 
        vector<int>temp = intervals[0]; 
        for(int i=0; i<n; i++)
        {
            if(intervals[i][0] <= temp[1])
            {
                temp[1] = max(intervals[i][1], temp[1]);
            }
            else
            {
                ans.push_back(temp); 
                temp = intervals[i];
            }
        }

        ans.push_back(temp); 
        return ans; 
























        
    }
};