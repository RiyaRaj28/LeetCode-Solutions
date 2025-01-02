class Solution {
public:
    void DFS(vector<vector<int>>&isConnected, vector<int>&visited, vector<vector<int>>&adj, int u)
    {
        int n = isConnected.size();
        visited[u] = 1; 

        // int x = i; 
        // int y = j; 
        for(int &v : adj[u])
        {

            if(!visited[v])
            {
                DFS(isConnected, visited, adj, v); 
            }
        }        
    }

    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int row = isConnected.size(); 
        int col = isConnected[0].size(); 
        int n = row; 
        // vector<vector<int>>visited(row, vector<int>(col, 0)); 
        int count = 0; 

        vector<int>visited(row, 0); 

        vector<vector<int>>adj(n, vector<int>(n, 0));
        for(int u=0; u<row; u++)
        {
            for(int v=0; v<col; v++)
            {
                if(u!=v && isConnected[u][v]==1)
                adj[u].push_back(v); 
            }
        }

        for(int u=0; u<row; u++)
        {
            if(!visited[u])
            {
                DFS(isConnected, visited, adj, u);
                count++;
            }
            
        }
        return count; 
    }
};