class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int, pair<int, int>>mpp; 

        

        // int k = n*m; 
        // vector<int>freq(k);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                mpp[mat[i][j]] = {i, j};
            }
        }

        vector<int>rows(n, 0);
        vector<int>cols(m, 0);

        for(int i=0; i<arr.size(); i++)
        {
            int x = mpp[arr[i]].first; 
            int y = mpp[arr[i]].second;

            rows[x]++; 
            cols[y]++;
            if(rows[x] >= m || cols[y] >= n) return i; 
        }
        return -1; 
    }
};