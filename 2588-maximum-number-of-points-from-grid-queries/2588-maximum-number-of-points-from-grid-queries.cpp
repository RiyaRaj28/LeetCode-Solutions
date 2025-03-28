class Solution {
public:

    typedef pair<int, pair<int, int>> pi; 

    // void bfs(vector<vector<int>>&grid, int val, int &ans, vector<vector<int>>vis)
    // {
    //     int m = grid.size(); 
    //     int n = grid[0].size(); 

    //     queue<pair<int, int>>q; 
    //     if(!vis[0][0] && grid[0][0] < val) 
    //     {
    //         ans = grid[0][0]; 
    //         vis[0][0] = 1; 
    //     }
    //     else return; 
    //     q.push({0, 0}); 


    //     // int ans = 1; 
        
    //     vector<int> frow = {-1, 0, 1, 0}; 
    //     vector<int> fcol = {0, 1, 0, -1}; 

    //     while(!q.empty())
    //     {
    //         int x = q.front().first; 
    //         int y = q.front().second; 
    //         q.pop(); 

    //         for(int i=0; i<4; i++)
    //         {
    //             int ax = x + frow[i]; 
    //             int ay = y + fcol[i]; 

    //             if(ax>=0 && ax<m && ay>=0 && ay<n && grid[ax][ay]<val)
    //             {
    //                 if(!vis[ax][ay])
    //                 {
    //                     vis[ax][ay] = 1; 
    //                     ans += 1; 
    //                 }
    //                 q.push({ax, ay}); 
    //             }
    //         }
    //     }

    //     // return ans; 
    // }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& que) 
    {
        int q = que.size(); 
        vector<pair<int, int>>queries;

        int m = grid.size(); 
        int n = grid[0].size(); 

        for(int i=0; i<q; i++) queries.push_back({que[i], i}); 
        sort(queries.begin(), queries.end());

        vector<vector<int>>vis(m, vector<int>(n, 0)); 
        vector<int>ans(q, 0); 
        int cnt = 0;
        priority_queue<pi, vector<pi>, greater<pi>>pq; 
        pq.push({grid[0][0], {0,0}}); 
        vis[0][0] = 1; 

        vector<int> frow = {-1, 0, 1, 0}; 
        vector<int> fcol = {0, 1, 0, -1}; 

        for(int i=0; i<queries.size(); i++)
        {
            int val = queries[i].first; 
            int ind = queries[i].second; 

            while(!pq.empty() && pq.top().first < val)
            {
                int x = pq.top().second.first;
                int y = pq.top().second.second; 
                pq.pop(); 


                cnt += 1; 

                for(int i=0; i<4; i++)
                {
                    int ax = x + frow[i]; 
                    int ay = y + fcol[i]; 

                    if(ax>=0 && ax<m && ay>=0 && ay<n && !vis[ax][ay])
                    {
                        pq.push({grid[ax][ay], {ax, ay}}); 
                        vis[ax][ay] = 1; 
                        

                    }
                }
            }

            ans[ind] = cnt; 
        }

        return ans; 
    }




    // void dfs(vector<vector<int>>&grid, int val, vector<vector<int>>&vis, int x, int y, int &ans)
    // {
    //     int m = grid.size(); 
    //     int n = grid[0].size(); 

    //     if(vis[x][y]) return; 
    //     else vis[x][y] = 1; 

    //     if(grid[x][y] < val) ans += 1; 
    //     else return; 

    //     vector<int> frow = {-1, 0, 1, 0}; 
    //     vector<int> fcol = {0, 1, 0, -1}; 

    //     for(int i=0; i<4; i++)
    //     {
    //         int ax = x + frow[i]; 
    //         int ay = y + fcol[i]; 

    //         if(ax>=0 && ax<m && ay>=0 && ay<n && !vis[ax][ay] && grid[ax][ay] < val) 
    //         {
    //             dfs(grid, val, vis, ax, ay, ans); 
    //         }
    //     }

    // }

    // vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) 
    // {
    //     int q = queries.size(); 
    //     vector<int>ans(q, 0); 
    //      int m = grid.size(); 
    //     int n = grid[0].size(); 

    //     for(int i=0; i<queries.size(); i++)
    //     {
    //         vector<vector<int>>vis(m, vector<int>(n, 0));
    //         int answ = 0; 
    //         dfs(grid, queries[i], vis, 0, 0, answ); 
    //         ans[i] = answ; 
    //     }
    //     return ans; 
    // }


};