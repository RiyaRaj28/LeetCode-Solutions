class Solution {
public:
    bool dfs(vector<vector<int>>&graph, vector<int>&coloured, int u, int currColour)
    {
        coloured[u] = currColour; 

        for(int &v : graph[u])
        {
            if(coloured[v] == coloured[u]) return false; 

            if(coloured[v] == -1)
            {
            if(dfs(graph, coloured, v, 1-currColour) == false) return false; 
            }
        }
        return true; 
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        //thru dfs here 
        int V = graph.size(); 
        vector<int>coloured(V, -1); 

        for(int u=0; u<V; u++)
        {
            if(coloured[u] == -1)
            {
                if(dfs(graph, coloured, u, 0) == false) return false; 
            }
        }
        return true; 
        
    }
};