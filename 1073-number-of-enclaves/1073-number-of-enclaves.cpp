class Solution {
public:
    void dfs(vector<vector<int>>&grid, vector<vector<int>>&mat, int x, int y)
    {
        int m = grid.size(); 
        int n = grid[0].size(); 
        mat[x][y] = -1; 
        int frow[4] = {-1, 0, 1, 0};
        int fcol[4] = {0, 1, 0, -1};

        for(int i=0; i<4; i++)
        {
            int nrow = x + frow[i];
            int ncol = y + fcol[i]; 

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1 && mat[nrow][ncol] != -1)
            {
                dfs(grid, mat, nrow, ncol);
            }
        }

    }

    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = grid.size(); 
        int n = grid[0].size();

        vector<vector<int>>mat(m, vector<int>(n, 0)); 

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 || i==m-1 || j==0 || j==n-1)
                {
                    if(grid[i][j] == 1)
                    {
                        dfs(grid, mat, i, j); 
                    }
                }
            }
        }
        int count = 0; 

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1 && mat[i][j] == 0) count++; 
            }
        }

        return count; 
        
    }
};