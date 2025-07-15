class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>>pac(m, vector<int>(n, 0));
        vector<vector<int>>atl(m, vector<int>(n, 0));

        queue<pair< pair<int, int>, int >>q1;
        queue<pair< pair<int, int>, int >>q2;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j==0 || i==0)
                {
                    q1.push({{i, j}, heights[i][j]});
                    pac[i][j] = true;
                }

                if(i==m-1 || j==n-1)
                {
                    q2.push({{i, j}, heights[i][j]});
                    atl[i][j] = true;
                }
            }
        }

        vector<int>frow = {-1, 0, 1, 0};
        vector<int>fcol = {0, 1, 0, -1};

        while(!q1.empty())
        {
            int x = q1.front().first.first;
            int y = q1.front().first.second;
            int ht = q1.front().second; 
            q1.pop();

            for(int i=0; i<4; i++)
            {
                int ax = x + frow[i];
                int ay = y + fcol[i];

                if(ax>=0 && ax<m && ay>=0 && ay<n && heights[ax][ay] >= ht && pac[ax][ay] == 0)
                {
                    pac[ax][ay] = 1;
                    q1.push({{ax, ay}, heights[ax][ay]});
                }
            }
        }

        while(!q2.empty())
        {
            int x = q2.front().first.first;
            int y = q2.front().first.second;
            int ht = q2.front().second; 
            q2.pop();

            for(int i=0; i<4; i++)
            {
                int ax = x + frow[i];
                int ay = y + fcol[i];

                if(ax>=0 && ax<m && ay>=0 && ay<n && heights[ax][ay] >= ht && atl[ax][ay] == 0)
                {
                    atl[ax][ay] = 2;
                    q2.push({{ax, ay}, heights[ax][ay]});
                }
            }
        }

        vector<vector<int>>res;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(pac[i][j] && atl[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }

        return res;

        
    }
};