typedef pair<int, pair<int, int>>p; 
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        priority_queue<p, vector<p>, greater<p>> pq; 
        int n = heights.size();
        int m = heights[0].size(); 
        vector<vector<int>>res(n, vector<int>(m, INT_MAX)); 

        res[0][0] = 0; 

        int frow[8] = {0, 1, 0, -1 };
        int fcol[8] = {-1, 0, 1, 0};

        pq.push({0, {0, 0}}); 

        while(!pq.empty())
        {
            int diff = pq.top().first; 
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            for(int i=0; i<4; i++)
            {
                int nrow = x + frow[i];
                int ncol = y + fcol[i]; 

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    // int absdiff = abs(heights[x][y] - heights[nrow][ncol]);

                    // if(absdiff >= diff) res[nrow][ncol] = absdiff;
                    // else res[nrow][ncol] = diff; 

                    int absdiff = max(diff, abs(heights[x][y] - heights[nrow][ncol]));

                    if(absdiff < res[nrow][ncol])
                    {
                        res[nrow][ncol] = absdiff;
                        pq.push({absdiff, {nrow, ncol}});
                    }
                }
            }
        }

        return res[n-1][m-1]; 
    }
};