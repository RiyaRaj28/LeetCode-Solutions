class Solution {
public:

    vector<int> parent;
    vector<int> rank; 

    int find(int x)
    {
        if(parent[x] == x) return x; 

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int x_par = find(x);
        int y_par = find(y);

        if(x_par == y_par) return;

        if(rank[x_par] > rank[y_par]) parent[y_par] = x_par;
        else if(rank[y_par] > rank[x_par]) parent[x_par] = y_par; 
        else 
        {
            parent[y_par] = x_par;
            rank[x_par]++; 
        }

    }
    
    int removeStones(vector<vector<int>>& stones) 
    {
       int n = stones.size(); 

        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++) parent[i] = i;

       for(int i=0; i<n; i++)
       {
           for(int j=i+1; j<n; j++)
           {
               if(stones[i][1] == stones[j][1] || stones[i][0] == stones[j][0])
               {
                    Union(i, j); 
               }
           }
       }

       int comps = 0; 
       for(int i=0; i<n; i++)
       {
           if(i == parent[i]) comps++; 
       }

       return n-comps; 
        
    }
};