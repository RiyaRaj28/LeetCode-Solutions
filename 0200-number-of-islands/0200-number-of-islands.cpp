class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>&grid, vector<vector<int>>&vis)
    {
        int m = grid.size(); 
        int n = grid[0].size(); 

        queue<pair<int, int>>q; 
        q.push({row, col});
        vis[row][col] = 1;

        vector<int>frow = {-1, 0, 1, 0};
        vector<int>fcol = {0, 1, 0, -1}; 

        while(!q.empty())
        {
            int r = q.front().first; 
            int c = q.front().second; 
            q.pop();

            for(int i=0; i<4; i++)
            {
                int ar = r + frow[i]; 
                int ac = c + fcol[i]; 

                if(ar >=0 && ar < m && ac >= 0 && ac < n && !vis[ar][ac] && grid[ar][ac] == '1')
                {
                    q.push({ar, ac});
                    vis[ar][ac] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size(); 
        int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        int cnt = 0; 

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    bfs(i, j, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt; 
    }
};