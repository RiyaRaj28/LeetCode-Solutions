typedef pair<int, pair<int,int>>P;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    { 
        int n = grid.size();
        // if(n == )
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1; 
        vector<vector<int>>dis(n, vector<int>(n, INT_MAX));

        priority_queue<P, vector<P>, greater<P>>pq; 

        pq.push({0, {0, 0}}); 
        dis[0][0] = 0;
        int frow[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int fcol[8] = {1, 1, 1, 0, -1, -1, -1, 0};

        while(!pq.empty())
        {
            int len = pq.top().first; 
            int x = pq.top().second.first; 
            int y = pq.top().second.second; 
            pq.pop(); 

            for(int p=0; p<8; p++)
            {
                int nrow = x + frow[p]; 
                int ncol = y + fcol[p]; 

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n 
                    && grid[nrow][ncol] == 0)
                {
                    if(len + 1 < dis[nrow][ncol])
                    {
                        dis[nrow][ncol] = len + 1; 
                        pq.push({len+1, {nrow, ncol}}); 
                    }
                }
            }
        }

        if(dis[n-1][n-1] == INT_MAX) return -1; 
        return dis[n-1][n-1] + 1; 
    }
};