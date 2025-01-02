class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size(); 
        vector<vector<int>>distance(m, vector<int>(n, -1)); 

        queue<pair<int, int>>q; 
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 0)
                {
                    distance[i][j] = 0; 
                    q.push({i, j});
                }
            }
        }

        int frow[4] = {-1, 0, 1, 0}; 
        int fcol[4] = {0, 1, 0, -1};

        while(!q.empty())
        {
            int x = q.front().first; 
            int y = q.front().second; 
            q.pop();
            
            for(int p=0; p<4; p++)
            {
                int nrow = x + frow[p]; 
                int ncol = y + fcol[p]; 

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&
                distance[nrow][ncol] == -1 )
                {
                    distance[nrow][ncol] = distance[x][y] + 1;
                    q.push({nrow, ncol}); 
                }
            }
        }
        return distance; 
    }
};