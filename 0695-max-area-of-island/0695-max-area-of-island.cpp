class Solution {
public:
    vector<int>size; 
    vector<int>parent; 

    int find(int x)
    {
        if(x == parent[x]) return x; 

        return parent[x] = find(parent[x]);
    }

    void Unite(int x, int y)
    {
        int xp = find(x); 
        int yp = find(y);

        if(xp == yp) return; 

        if(size[xp] >= size[yp])
        {
            parent[yp] = xp;
            size[xp] += size[yp];
        }
        else if(size[yp] < size[xp])
        {
            parent[xp] = yp;
            size[yp] += size[xp];
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        parent.resize(m*n, 0);
        size.resize(m*n, 0);

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                parent[i*n + j] = i*n + j;
                if(grid[i][j] == 1) size[i*n + j] = 1;
            }
        }

        vector<vector<int>>vis(m, vector<int>(n, 0));
        vector<int> frow = {-1, 0, 1, 0};
        vector<int>fcol = {0, 1, 0, -1};

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    for(int p=0; p<4; p++)
                    {
                        int ar = i + frow[p];
                        int ac = j + fcol[p];

                        if(ar >= 0 && ar < m && ac >= 0 && ac < n && grid[ar][ac] == 1)
                        {
                            Unite(i*n + j, ar*n + ac);
                        }
                    }
                }
            }
        }
        int mxsize = 0;

        for(int i=0; i<n*m; i++)
        {
            mxsize = max(mxsize, size[i]);
        }
        return mxsize; 
    }
};