class Solution {
public:
    //is topological sort possible using Kanh's 
    // created a queue, added and popped elements, if equal to total number of nodes, then 
    // no cycle exists -> return true!
    // we use indegree concept for cycle here!
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    // {
    //     vector<int> indegree(numCourses, 0);
    //     vector<vector<int>> adj(numCourses); 
    //     for(auto &u : prerequisites)
    //     {
    //         int course = u[0]; 
    //         int prerequisite = u[1]; 

    //         adj[prerequisite].push_back(course); 
    //         indegree[course]++; 

    //     }

    //     queue<int> q; 
    //     for(int u=0; u<numCourses; u++)       
    //     {
    //         if(indegree[u] == 0)
    //             q.push(u); 
    //     }

    //     int count = 0; 
    //     while(!q.empty())
    //     {
    //         int u = q.front(); 
    //         q.pop(); 
    //         count++; 

    //         for(int &v : adj[u])
    //         {
    //             indegree[v]--; 

    //             if(indegree[v] == 0) q.push(v); 
    //         }
    //     }

    //     return count == numCourses;  
    // }

    bool DFS(int numCourses, vector<vector<int>> adj, vector<bool>&inRecursion, vector<bool>&visited, int u)
    {
        visited[u] = true; 
        inRecursion[u] = true; 

        for(int &v: adj[u])
        {
            if(!visited[v])
            {
                if(DFS(numCourses, adj, inRecursion, visited, v))
                    return true; 
            }
            else if(inRecursion[v])
            {
                return true; //cycle exits
            }
        }

        inRecursion[u] = false; 
        return false; //cycle does not exist -> correct order
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        //topo sort possible detect using dfs : visited, in recursion
        if(prerequisites.size() == 0) return true; 

        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites)
        {
            int u = it[1]; 
            int v = it[0]; 
            
            adj[u].push_back(v); 
        }

        vector<bool> visited(numCourses, false); 
        vector<bool> inRecursion(numCourses, false); 

        for(int u=0; u<numCourses; u++)
        {
            if(!visited[u] && DFS(numCourses, adj, inRecursion, visited, u))
            {
                return false;  //cycle is detected
            }
        }

        return true; //no cycle is detected
    }

};