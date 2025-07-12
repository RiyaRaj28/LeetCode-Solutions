class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& ni) 
    {
        //merge the overlappting intervals 
        // keep increasing current end till it is greater than the start of next 
        // if(intervals[curr][i] > intervals[i+1][0]) 
        // continue 


        int n = inter.size(); 
        vector<vector<int>>ans; 
        int i = 0; 
        while(i<n && ni[0] > inter[i][1])
        {
            ans.push_back(inter[i]); 
            i++;
        }

        while(i<n && ni[1] >= inter[i][0])
        {
            ni[0] = min(ni[0], inter[i][0]); 
            ni[1] = max(ni[1], inter[i][1]); 
            i += 1;
        }

        ans.push_back({ni[0], ni[1]});

        while(i<n)
        {
            ans.push_back(inter[i]); 
            i += 1; 
        }
        return ans;         
    }
};