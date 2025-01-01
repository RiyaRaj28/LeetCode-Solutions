class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        //return false if a cycle exists in the graph 

        // ways -> 
        // 1. direc bfs 
        // 2. direc dfs 
        // 3. undirec bfs 
        // 4. undirec dfs 

        // have to use direc bfs or direc sfs 
        // direc bfs -> kanhs algo -> indegree vec 
        /// if count of the nodes is equal to the number popped : no cycle

        // direc dfs -> inrecursion 
        int V = numCourses; 
        vector<int>indegree(V, 0); 
        vector<vector<int>>adj(V);

        for(auto &it : prerequisites)
        {
            int u = it[1];
            int v = it[0];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int>q; 
        for(int u=0; u<V; u++)
        {
            if(indegree[u] == 0) q.push(u); 
        }

        int count = 0; 
        while(!q.empty())
        {
            int u = q.front(); 
            q.pop(); 
            count++; 

            for(int &v : adj[u])
            {
                indegree[v]--;
                if(indegree[v] == 0) q.push(v); 
            }
        }

        if(count == V) return true; 
        return false; 
    }
};