class Solution {
public:

    vector<int>parent; 
    vector<int>rank; 

    int find(int x)
    {
        if(x == parent[x]) return x; 

        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y)
    {
        int xp = find(x); 
        int yp = find(y); 

        if(xp == yp) return false; 
        if(rank[xp] > rank[yp])
        {
            parent[yp] = xp;
            rank[xp] += 1;
        }
        else if(rank[xp] < rank[yp])
        {
            parent[xp] = yp; 
            rank[yp] += 1; 
        }
        else
        {
            parent[xp] = yp; 
            rank[yp] += 1; 
        }

        return true; 
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        // vector<vector<int>>adj(n+1);

        // for(auto &vec : edges)
        // {
        //     int u = vec[0]; 
        //     int v = vec[1]; 

        //     adj[u].push_back(v); 
        //     adj[v].push_back(u); 
        // }

        // queue<int>q; 
        // vector<bool>visited(n+1, false); 
        // set<pair<int, int>>st; 

        // q.push(1); 
        // while(!q.empty())
        // {
        //     int node = q.front(); 
        //     q.pop();

        //     if(visited[node]) continue; 
        //     visited[node] = true; 

        //     for(int &anode : adj[node])
        //     {
        //         if(!visited[anode]) q.push(anode); 
        //         else st.insert({node, anode}); 
        //     }

        // }

        // for(int i=n-1; i>=0; i--)
        // {
        //     int u = edges[i][0];
        //     int v = edges[i][1]; 

        //     if(st.find({u, v}) != st.end())
        //     {
        //         return {u,v};
        //     }

        // }

        // return {-1, -1}; 

        parent.resize(n+1); 
        for(int i=0; i<n+1; i++) parent[i] = i; 

        rank.resize(n+1, 1);
        for(auto &vec : edges)
        {
            int u = vec[0];
            int v = vec[1]; 

            if(!Union(u, v)) return vec;
        }

        return {-1, -1}; 
        
    }
};