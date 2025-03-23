class Solution {
public:
    vector<int>parent; 
    vector<int>rank; 

    int find(int x)
    {
        if(parent[x] != x) parent[x] = find(parent[x]); 
        return parent[x]; 
    }

    void Union(int x, int y)
    {
        int px = find(x); 
        int py = find(y); 

        if(px == py)
        {
            return; 
        }

        if(rank[px] > rank[py])
        {
            parent[py] = px; 
        }
        else if(rank[px] < rank[py])
        {
            parent[px] = py; 
        }
        else
        {
            parent[py] = px; 
            rank[px]++;  
        }
    }

    int intersect(vector<int>a, vector<int>b)
{
        unordered_set<int> setA(a.begin(), a.end());
        unordered_set<int> setB(b.begin(), b.end());
        int count = 0;
        for (int num : setB) {
            if (setA.count(num)) {
                count++;
            }
        }
        return count;
    // return cnt; 
}

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int V = properties.size(); 
        
        parent.resize(V, 0); 
        rank.resize(V, 0); 
        for(int i=0; i<V; i++) parent[i] = i; 
        
        // unordered_map<int, vector<int>>adj;

        for(int i=0; i<V; i++)
            {
                for(int j=i+1; j<V; j++)
                    {
                        int u = i; 
                        int v = j; 

                        if(find(u) != find(v))
                        {
                            if(intersect(properties[u], properties[v]) >= k)
                            {
                                Union(u, v); 
                            }
                        }
                    }
            }

        // unordered_set<int>st; 
        // for(int i=0; i<parent.size(); i++) st.insert(find(i)); 
        int cnt = 0; 
        for(int i=0; i<V; i++) if(parent[i] == i) cnt++; 

        return cnt; 
    }
};