class Solution {
public:
    // void dfstopo(vector<vector<int>>&adj, int u, int n, stack<int>&st, vector<bool>&visited)
    // {
    //     visited[u] = true; 

    //     for(int &v : adj[u])
    //     {
    //         if(!visited[v])
    //         {
    //             // st.push(v);
    //             dfstopo(adj, v, n, st, visited);
    //         }
    //     }

    //     st.push(u); 

    // }

    // vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    // {
    //     int q = queries.size(); 
    //     if(prerequisites.size() == 0) return vector<bool>(q, false);

    //     int n = numCourses; 
    //     vector<vector<int>>adj(n);

    //     for(auto &vec : prerequisites)
    //     {
    //         int u = vec[0]; 
    //         int v = vec[1]; 

    //         adj[u].push_back(v); 
    //     }

    //     stack<int>st; 
    //     vector<int>ans; 
    //     vector<bool>visited(n); 

    //     for(int u=0; u<n; u++)
    //     {
    //         if(!visited[u])
    //         {
    //             dfstopo(adj, u, n, st, visited);
    //         }
            
    //     }

    //     while(!st.empty())
    //     {
    //         ans.push_back(st.top()); 
    //         st.pop();
    //     }

    //     unordered_map<int, int>mpp; 
    //     for(int i=0; i<ans.size(); i++)
    //     {
    //         mpp[ans[i]] = i; 
    //     }
 
       
    //     vector<bool>queryans(q); 
    //     for(int i=0; i<queries.size(); i++)
    //     {
    //         int u = queries[i][0]; 
    //         int v = queries[i][1]; 

    //         if(mpp[u] < mpp[v]) queryans[i] = true; 
    //         else queryans[i] = false; 
    //     }
    //     return queryans; 
    // }
    void bfs(vector<vector<int>>&adj, vector<vector<bool>>&isReachable, int par, vector<bool>&visited)
    {
        queue<int>q; 
        q.push(par); 
        // visited[par] = true; 

        while(!q.empty())
        {
            int u = q.front(); 
            q.pop(); 

            for(int &v : adj[u])
            {      
                if(!isReachable[par][v]) 
                {   
                    isReachable[par][v] = 1; 
                    q.push(v);
                } 
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
       int q = queries.size(); 
        if(prerequisites.size() == 0) return vector<bool>(q, false);

        int n = numCourses; 
        vector<vector<int>>adj(n);

        for(auto &vec : prerequisites)
        {
            int u = vec[0]; 
            int v = vec[1]; 

            adj[u].push_back(v); 
        }

        vector<bool>visited(n, false); 

        vector<vector<bool>>isReachable(n, vector<bool>(n, 0)); 
        for(int u=0; u<numCourses; u++)
        {
            
            bfs(adj, isReachable, u, visited);
            
        }

        vector<bool>ans(q); 

        for(int i=0; i<queries.size(); i++)
        {
            int u = queries[i][0]; 
            int v = queries[i][1]; 

            if(isReachable[u][v]) ans[i] = true; 
            else ans[i] = false; 
        } 
        
        return ans; 
    }

};