class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        queue<pair<int, int>>q; 
        vector<vector<pair<int, int>>>adj(n); 

        for(auto &vec : flights)
        {
            int u = vec[0]; 
            int v = vec[1]; 
            int wt = vec[2]; 

            adj[u].push_back({v, wt}); 
        }

        q.push({src, 0}); 
        vector<int>result(n, INT_MAX); 
        result[src] = 0; 
        int level = 0; 

        while(!q.empty() && level <= k)
        {
            int size = q.size(); 
            while(size--)
            {
                int node = q.front().first; 
                int dis = q.front().second; 

                q.pop(); 

                for(auto &it : adj[node])
                {
                    int anode = it.first; 
                    int adis = it.second; 

                    if(dis + adis < result[anode])
                    {
                        result[anode] = dis + adis; 
                        q.push({anode, dis+adis}); 
                    }
                }
            }
            level++; 
        }

        return result[dst] == INT_MAX ? -1 : result[dst]; 
    }
};