class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, pair<int, int>>>q;
        int fresh = 0; 

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({0, {i,j}});
                }
                else if(grid[i][j] == 1) fresh++;
            }
        }

        int mxtime = 0;
        vector<int>frow = {-1, 0, 1, 0};
        vector<int>fcol = {0, 1, 0, -1};
        int cnt = 0;

        while(!q.empty())
        {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int time = q.front().first;
            mxtime = max(mxtime, time);
            q.pop();

            for(int i=0; i<4; i++)
            {
                int ax = x + frow[i];
                int ay = y + fcol[i];

                if(ax>=0 && ax<m && ay>=0 && ay<n && grid[ax][ay] == 1)
                {
                    cnt++;
                    grid[ax][ay] = 2;
                    q.push({time+1, {ax, ay}});
                }
            }
        }

        if(cnt != fresh) return -1;
        return mxtime;
        
    }
};