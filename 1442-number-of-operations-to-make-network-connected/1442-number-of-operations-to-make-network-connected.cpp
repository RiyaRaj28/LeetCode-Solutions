class Solution {
public:

    vector<int>parent; 
    vector<int>rank; 

    void Union(int x, int y)
    {
        int x_par = find(x); 
        int y_par = find(y);

        if(x_par == y_par) return; 

        if(rank[x_par] > rank[y_par]) parent[y_par] = x_par; 
        else if(rank[x_par] < rank[y_par]) parent[x_par] = y_par; 
        else
        {
            parent[y_par] = x_par; 
            rank[x_par]++; 
        }
    }

    int find(int x)
    {
        if(x == parent[x]) return x; 

        return parent[x] = find(parent[x]); 
    }

    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        //we have to find out the different number of components 
        //and we have to connect all the components together 
        //

        // to connect v comps we need v-1 edges 
        int edges = connections.size();
        if(edges < n-1) return -1; 

        parent.resize(n);
        rank.resize(n, 0); 
        for(int i=0; i<n; i++) parent[i] = i; 

        for(auto &vec : connections)
        {
            int u = vec[0];
            int v = vec[1];

            if(find(u) != find(v)) Union(u, v);
        }

        set<int>st; 
        for(int i=0; i<n; i++)
        {
            st.insert(find(i));
        }

        return st.size()-1; 
    }
};