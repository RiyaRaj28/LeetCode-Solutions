class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        int m = isWater.size();
        int n = isWater[0].size(); 

        vector<vector<int>>ans(m, vector<int>(n, -1));
        queue<pair<int, pair<int, int>>>q; 

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isWater[i][j] == 1)
                {
                    ans[i][j] = 0; 
                    q.push({0, {i, j}}); 
                }

            }
        }

        int frow[4] = {0, -1, 0, 1}; 
        int fcol[4] = {1, 0, -1, 0}; 

        while(!q.empty())
        {
            int dis = q.front().first; 
            int x = q.front().second.first; 
            int y = q.front().second.second; 
            q.pop(); 

            for(int i=0; i<4; i++)
            {
                int nrow = x + frow[i]; 
                int ncol = y + fcol[i]; 

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && ans[nrow][ncol] == -1)
                {
                    ans[nrow][ncol] = dis + 1; 
                    q.push({dis+1, {nrow, ncol}}); 
                }
            }
        }

        return ans; 
    }
};