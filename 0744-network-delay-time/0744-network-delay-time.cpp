class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // make k as the main source node
        // add the min time 

        //creating adjacency list 
        vector<vector<pair<int, int>>>adj(n+1); 
        for(auto &vec : times)
        {
            int u = vec[0]; 
            int v = vec[1];
            int time = vec[2]; 

            adj[u].push_back({v, time}); 
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; 
        vector<int>result(n+1, INT_MAX); 
        pq.push({0, k});
        result[k] = 0;  

        while(!pq.empty())
        {
            int t = pq.top().first; 
            int u = pq.top().second; 
            pq.pop(); 

            for(auto &vec : adj[u])
            {
                int v = vec.first; 
                int wt = vec.second; 

                if(t + wt < result[v]) 
                {
                    result[v] = t + wt; 
                    pq.push({t+wt, v});
                }
            }
        }

        int sum = 0; 

        for(int i=1; i<=n; i++)
        {
            if(result[i] == INT_MAX) return -1; 
            sum = max(sum, result[i]); 
        }
        
        return sum; 
    }
};