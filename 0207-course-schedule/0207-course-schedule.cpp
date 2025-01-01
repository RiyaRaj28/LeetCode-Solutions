class Solution {
public:
    bool directDFS(vector<vector<int>>&adj, vector<bool>&inRecursion, int u, vector<bool>&visited)
    {
        visited[u] = true; 
        inRecursion[u] = true; 

        for(int &v : adj[u])
        {
            if(!visited[v])
            {
                if(directDFS(adj, inRecursion, v, visited)) return true; 
            }
            else if(inRecursion[v]) return true; 
        }
        inRecursion[u] = false; 

        return false; 
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>>adj(numCourses);
        vector<bool>visited(numCourses, false); 
        vector<bool>inRecursion(numCourses, false);

        for(auto &it : prerequisites)
        {
            int u = it[1];
            int v = it[0];

            adj[u].push_back(v);
        }

        for(int u=0; u<numCourses; u++)
        {
            if(!visited[u])
            {
                if(directDFS(adj, inRecursion, u, visited)) return false; 
            }
        }
        return true; 
    }
};