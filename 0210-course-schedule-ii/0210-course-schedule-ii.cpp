class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int V = numCourses;
        vector<vector<int>>adj(V);
        vector<int>indegree(V, 0);

        for(int i=0; i<prerequisites.size(); i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
            indegree[a]++;
        } 

        queue<int>q;
        for(int i=0; i<V; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int>res;
        int cnt = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            cnt++;

            for(int &anode : adj[node])
            {
                indegree[anode]--;

                if(indegree[anode] == 0) q.push(anode);
            }
        }

        if(cnt == V) return res;
        return {};   
    }
};