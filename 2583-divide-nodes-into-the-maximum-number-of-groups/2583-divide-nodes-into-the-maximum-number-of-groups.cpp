class Solution {
public:
    bool checkBipartite(vector<vector<int>>&adj, int n, vector<int>&colour, int currcolour, int node)
    {
        colour[node] = currcolour; 
        
        for(int &v : adj[node])
        {
            if(colour[v] == colour[node]) return false;
            if(colour[v] == -1) 
            {
                if(!checkBipartite(adj, n, colour, 1 - currcolour, v))
                {
                    return false; 
                } 
            }
        }
        return true; 
    }

    int BFS(vector<vector<int>>&adj, int node, int n)
    {
        vector<bool>visited(n, false); 
        visited[node] = true; 
        queue<int>q; 
        q.push(node); 

        int levels = 0; // these are just the max groups in that component
        while(!q.empty())
        {
            int size = q.size(); 
            levels++; 

            while(size--)
            {
                int u = q.front(); 
                q.pop(); 
    
                for(int &v : adj[u])
                {
                    if(visited[v]) continue; 
                    
                    visited[v] = true; 
                    q.push(v); 
                    
                }
            }

            //one extra level is added here 
        }
        return levels; 
    }

    int  maxGrpFromEachComp(vector<vector<int>>&adj, int node, int n, vector<int>&level, vector<bool>&visited)
    {
        visited[node] = true; 
        int maxlevels = level[node]; 

        for(int &v : adj[node])
        {
            if(!visited[v])
            {
                maxlevels = max(maxlevels, maxGrpFromEachComp(adj, v, n, level, visited)); 
            }
        }

        return maxlevels; 
    }


    int magnificentSets(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(n); 
        for(auto &edge : edges)
        {
            int u = edge[0] -1; //converting to 0 based indexing 
            int v = edge[1] -1; 

            adj[u].push_back(v); 
            adj[v].push_back(u); 
        }
        
        vector<int>colour(n, -1); 
        for(int i=0; i<n; i++)
        {
            if(colour[i] == -1)
            {
                if(!checkBipartite(adj, n, colour, 1, i)) return -1; 
            }
        }

        //finding out the required levels 
        vector<int>level(n, 0); 

        for(int i=0; i<n; i++)
        {
            level[i] = BFS(adj, i, n);

        }

        int maxgroups = 0; 
        vector<bool>visited(n, false); 
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                maxgroups += maxGrpFromEachComp(adj, i, n, level, visited);
            }
        }

        return maxgroups; 
        
    }
};