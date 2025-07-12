class Solution {
public:
    // bool comp(vector<int>a, vector<int>b)
    // {
    //     if(a[0] == b[0])
    // }
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& t) 
    {
        // sort(triplets.begin(), triplets.end()); 
        // vector<int>curr = {triplets[0][0], triplets[0][1], triplets[0][2]}; 
        vector<int>curr = {0, 0, 0};

        int n = triplets.size(); 
        for(int i=0; i<n; i++)
        {
            int ma = max(curr[0], triplets[i][0]); 
            int mb = max(curr[1], triplets[i][1]); 
            int mc = max(curr[2], triplets[i][2]); 

            if(ma == t[0] && mb == t[1] && mc == t[2]) return true; 

            if(ma > t[0] || mb > t[1] || mc > t[2])
            {
                continue;
            }
            curr[0] = ma; 
            curr[1] = mb; 
            curr[2] = mc; 
        }

        return false; 
        
    }
};