// class DisjointSet
// {
//     public : 
//     vector<int> parent, rank, size; 
//     DisjointSet(int n)
//     {
//         parent.resize(n);
//         rank.resize(n, 0);
//         size.resize(n, 1);
//         for(int i=0; i<n; i++) parent[i] = i; 
//     }

//     int find(int x)
//     {
//         if(parent[x] == x) return x; 
//         return parent[x] = find(parent[x]);
//     }

//     void Union(int x, int y)
//     {
//         int x_par = find(x);
//         int y_par = find(y);

//         if(x_par == y_par) return; 

//         if(size[y_par] > size[x_par])
//         {
//             parent[x_par] = y_par; 
//             size[y_par] += size[x_par];
//         }
//         else
//         {
//             parent[y_par] = x_par;
//             size[x_par] += size[y_par];
//         }
//     }
// };

// class Solution {

// public:
//     int largestIsland(vector<vector<int>>& grid) 
//     {
//         int n = grid.size();
//         DisjointSet ds(n*n);

//         int frow[4] = {-1, 0, 1, 0};
//         int fcol[4] = {0, 1, 0, -1}; 

//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 if(grid[i][j] == 0) continue; 
//                 for(int k=0; k<4; k++)
//                 {
//                     int nrow = frow[k] + i; 
//                     int ncol = fcol[k] + j; 

//                     if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] == 1)
//                     {
//                         int node = i * n + j; 
//                         int anode = nrow * n + ncol; 
//                         ds.Union(node, anode);
//                     }
//                 }
//             }
//         }

//         //for each 0, chech 4-dirs if 1 is present 
//         // if present, add to set ds 
//         // find parent of each element in the set and find the total size of that component 
//         // maintain in a max component variable 

//         int msize = 1; 

//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 int tsize = 1; 

//                 if(grid[i][j] == 1) continue; 
//                 else if(grid[i][j] == 0)
//                 {
//                     set<int> st;  
//                     for(int k=0; k<4; k++)
//                     {
//                        int nrow = frow[k] + i; 
//                        int ncol = fcol[k] + j; 

//                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] == 1)
//                        {
//                             // we are finding the parent of the adjacent 1 and inserting it into the set to avoid adding 
//                             // same set size again 
//                             st.insert(ds.find(nrow * n + ncol));
//                        }                       
//                     }
                   
//                    for(auto it : st)
//                    {
//                       tsize += ds.size[it]; 
//                    }
//                 }
//                 msize = max(msize, tsize);
//             }
//         }

//         for(int i=0; i<n*n; i++)
//         {
//             msize = max(msize, ds.size[ds.find(i)]);
//         }

//         return msize; 
//     }
// };








class DisjointSet
{
    public:
    vector<int>parent, rank, size; 
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for(int i=0; i<n; i++) parent[i] = i; 
    }

    int find(int x)
    {
        if(x == parent[x]) return x; 
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int x_par = find(x);
        int y_par = find(y);

        if(x_par == y_par) return; 

        if(size[x_par] > size[y_par])
        {
            parent[y_par] = x_par; 
            size[x_par] += size[y_par]; 
        }
        else if(size[y_par] > size[x_par])
        {
            parent[x_par] = y_par; 
            size[y_par] += size[x_par];
        }
        else
        {
            parent[x_par] = y_par; 
            size[y_par] += size[x_par];
        }
    }
};

class Solution {

public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        DisjointSet ds(n*n); 

        vector<int>frow = {-1, 0, 1, 0};
        vector<int>fcol = {0, 1, 0, -1};

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0) continue; 
                int node = i * n + j; 

                for(int k=0; k<4; k++)
                {
                    int nrow = i + frow[k];
                    int ncol = j + fcol[k];
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] == 1)
                    {   
                        int anode = nrow * n + ncol; 
                        ds.Union(node, anode);
                    }
                }
            }
        }

        int msize = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int tsize = 1; 
                int node = i*n + j; 
                if(grid[i][j] == 1) continue; 
                if(grid[i][j] == 0)
                {
                    set<int>st; 
                    for(int k=0; k<4; k++)
                    {
                        int nrow = i + frow[k];
                        int ncol = j + fcol[k];

                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] == 1)
                        {
                            int anode = nrow*n + ncol; 
                            st.insert(ds.find(anode));
                        }
                    }
                    
                    for(auto it : st)
                    {
                        tsize += ds.size[it];
                    }
                }
                msize = max(msize, tsize); 
            }
        }

        
        for(int i=0; i<n*n; i++)
        {
            msize = max(msize, ds.size[ds.find(i)]);
        }
        return msize;
    }
};



















