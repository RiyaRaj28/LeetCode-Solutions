class Solution {
public:

    // bool isCycleDFS(int u, vector<vector<int>> graph, vector<bool> &visited, vector<bool> &inRecursion)
    // {
    //     visited[u] = true; 
    //     inRecursion[u] = true; 

    //     for(int v : graph[u])
    //     {
    //         if(!visited[v] && isCycleDFS(v, graph, visited, inRecursion))
    //             return true; 
    //         else if(inRecursion[v])
    //             return true; 
    //     }

    //     inRecursion[u] = false; 
    //     return false; 
    // }

    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    // {
    //     int V = graph.size();

    //     vector<bool> visited(V, false);
    //     vector<bool> inRecursion(V, false);

    //     for(int u=0; u<V; u++)
    //     {
    //         if(!visited[u])
    //         {
    //             isCycleDFS(u, graph, visited, inRecursion);
    //         }
    //     }

    //     vector<int> safe_nodes; 

    //     for(int v=0; v<V; v++)
    //     {
    //         if(inRecursion[v] == false) safe_nodes.push_back(v);
    //     }
        
    //     return safe_nodes; 
    // }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int V = graph.size();
        
        vector<vector<int>> adj(V); 
        vector<bool> isSafe(V, false); 
        vector<int> indegree(V, 0); 

        //reversing the given graph 
        for(int u=0; u<V; u++)
        {
            for(int &v : graph[u])
            {
                adj[v].push_back(u);
                indegree[u]++; 
            }
        }

        //put in q 
        queue<int> q; 
        for(int u=0; u<V; u++)
        {
            if(indegree[u] == 0) 
                q.push(u);
        }

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            isSafe[u] = true; 

            for(int &v : adj[u])
            {
                indegree[v]--;

                if(indegree[v] == 0)
                    q.push(v); 
            }
        }

        vector<int> safe_nodes; 

        for(int u=0; u<V; u++)
        {
            if(isSafe[u] == true)
            {
                safe_nodes.push_back(u);
            }
        }

        return safe_nodes; 
    }

};