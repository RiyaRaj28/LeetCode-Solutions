class Solution {
public:

    vector<int>parent;
    vector<int>rank; 

    int find(int x)
    {
        if(x == parent[x]) return x; 

        return parent[x] = find(parent[x]);
    }

    bool Unite(int x, int y)
    {
        int xp = find(x); 
        int yp = find(y);

        if(xp == yp) return false;

        if(rank[xp] > rank[yp])
        {
            parent[yp] = xp;
            rank[xp] += 1;
        }
        else if(rank[yp] > rank[xp])
        {
            parent[xp] = yp; 
            rank[yp] += 1;
        }
        else
        {
            parent[xp] = yp;
            rank[xp] += 1;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        rank.resize(n+1, 1);
        parent.resize(n+1, 0);

        for(int i=0; i<=n; i++) parent[i] = i; 

        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1]; 

            if(!Unite(u, v)) return {u, v};
        }
        return {-1, -1}; 
    }
};