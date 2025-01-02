class Solution {
public:
    // void bfs()
    int orangesRotting(vector<vector<int>>& grid) 
    {
        // bfs - 4 directionally 
        // rety min time till no cell has a fresh orange 

        // call bfs on the rotten oranges 
        // we search in the surroundings -> bfs 
        queue<pair<pair<int, int>, int>>q; 
        int m = grid.size();
        int n = grid[0].size(); 
        vector<vector<int>>visited(m, vector<int>(n, 0)); 
        int fresh = 0; 

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!visited[i][j] && grid[i][j]==2)
                {
                    visited[i][j] = 2; 
                    q.push({{i,j}, 0}); 
                }
                else if(grid[i][j] == 1) fresh++; 
            }
        }

        vector<int> frow = {-1, 0, 1, 0}; 
        int fcol[4] = {0, 1, 0, -1}; 
        int count = 0; 

        int max_time = 0; 
        while(!q.empty())
        {
            int x = q.front().first.first; 
            int y = q.front().first.second; 
            int time = q.front().second; 
            q.pop(); 

            max_time = max(time, max_time); 
            for(int p=0; p<4; p++)
            {
                int nrow = x + frow[p];
                int ncol = y + fcol[p]; 

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n
                && !visited[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    grid[nrow][ncol] = 2; 
                    visited[nrow][ncol] = 1; 
                    q.push({{nrow, ncol}, time + 1});
                    count++;  
                }
            }
        }

        if (count == fresh) return max_time; 
        return -1; 
    }
};