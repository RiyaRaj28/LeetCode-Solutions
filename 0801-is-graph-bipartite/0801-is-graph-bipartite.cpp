class Solution {
public:
    bool bfs(vector<vector<int>>&graph, vector<int>&coloured, int curr, int currColour)
    {
        coloured[curr] = currColour; 
        queue<int>q; 
        q.push(curr); 

        while(!q.empty())
        {
            int u = q.front(); 
            q.pop(); 
            // int currCol = q.front().second; 

            for(int &v : graph[u])
            {
                if(coloured[u] == coloured[v]) return false; 

                if(coloured[v] == -1)
                {
                    coloured[v] = 1 - coloured[u]; 
                    q.push(v); 
                }
            }
        }

        return true; 
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        //thru bfs here 
        int V = graph.size(); 
        vector<int>coloured(V, -1); 

        for(int u=0; u<V; u++)
        {
            if(coloured[u] == -1)
            {
                if(bfs(graph, coloured, u, 0) == false) return false; 
            }
        }
        return true;    
    }
};