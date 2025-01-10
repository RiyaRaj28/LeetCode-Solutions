class Solution {
public:
//     int timer = 1; 

//     void dfs(int parent, int node, vector<int> adj[], vector<int>&visited, vector<int>&low, vector<int>&tin, vector<vector<int>>&bridges)
//     {
//         visited[node] = 1; 
//         low[node] = timer;
//         tin[node] = timer; 
//         timer++; 

//         for(auto anode : adj[node])
//         {
//             if(anode == parent) continue; 

//             if(visited[anode] == 0)
//             {
//                 dfs(node, anode, adj, visited, low, tin, bridges);
//                 low[node] = min(low[anode], low[node]);
//             }

//             if(low[anode] > tin[node])
//             {
//                 bridges.push_back({node, anode}); 
//             }
//             else
//             {
//                 low[node] = min(low[anode], low[node]); 
//             }
//         }
//     }

//     vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
//     {
//         vector<int> adj[n];

//         for(auto it: connections)
//         {
//             int u = it[0];
//             int v = it[1];

//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
        
//         vector<vector<int>> bridges; 
//         vector<int> visited(n, 0);
//         vector<int> low(n);
//         vector<int> tin(n);

//         dfs(-1, 0, adj, visited, low, tin, bridges); 

//         return bridges; 
//     }
// };


int timer = 1; 

void dfs(int node, vector<vector<int>>&adj, vector<int>&tin, vector<int>&low, vector<bool>&visited, int parent, vector<vector<int>>&bridges)
{
    visited[node] = true; 
    low[node] = timer;
    tin[node] = timer; 
    timer++; 

    //think about this here right now 
    // i am sitting in the library

    for(auto &anode : adj[node])
    {
        if(anode == parent) continue; 
        if(!visited[anode])
        {
            dfs(anode, adj, tin, low, visited, node, bridges);
            low[node] = min(low[node], low[anode]);

        }
        if(tin[node] < low[anode])
        {
            bridges.push_back({node, anode});
        }
        else 
        {
            low[node] = min(low[node], low[anode]);
        }
    }
}


// class Solution {
// public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        // int n = connections.size();
        vector<vector<int>>adj(n);

        for(auto &it : connections)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>tin(n);
        vector<int>low(n);
        vector<bool>visited(n, false);
        vector<vector<int>>bridges;

        dfs(0, adj, tin, low, visited, -1, bridges);
        return bridges; 
    }
};
















