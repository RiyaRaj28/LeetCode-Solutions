class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        // int mini = INT_MAX; 
        // int num = 0, cnt = 0; 
        // bool poss = true; 

        int n = grid.size(); 
        int m = grid[0].size(); 
        // int maxi = 0; 

        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //     {
        //         maxi = max(maxi, grid[i][j]); 
        //     }
        // }

        // for(int i=1; i<=maxi; i++)
        // {
        //     num = i; 
        //     cnt = 0, poss = true; 
        //     int steps = 0; 

        //     for(int i=0; i<n; i++)
        //     {
        //         for(int j=0; j<m; j++)
        //         {
        //             int diff = abs(grid[i][j] - num);

        //             if(diff % x != 0) 
        //             {
        //                 poss = false; 
        //                 break; 
        //             }
        //             else
        //             {
        //                 steps = diff/x; 
        //                 cnt += steps; 
        //             }
        //         }
        //         if(!poss) break; 
        //     }

        //     if(poss)
        //     {
        //         mini = min(mini, cnt); 
        //     }
        //     // else break; 
        // }

        // return mini==INT_MAX ? -1 : mini; 



        vector<int>arr(m*n, 0); 
        int ind = 0; 
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                arr[ind++] = grid[i][j]; 
            }
        }

        sort(arr.begin(), arr.end()); 
        int p = arr.size(); 

        int median = arr[p/2]; 
        cout << median << endl; 
        // if(p%2 != 0) median = arr[p/2]; 
        // else
        // {
        //     median = (arr[p/2] + arr[p/2 - 1])/2; 
        // }

        int total = 0; 
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int diff = abs(grid[i][j] - median); 
                if(diff%x != 0) return -1; 
                else
                {
                    total += diff/x; 
                }
            }
        }

        return total;
    }
};