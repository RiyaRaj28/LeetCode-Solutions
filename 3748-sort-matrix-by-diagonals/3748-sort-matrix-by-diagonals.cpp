class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size(); 
        unordered_map<int, priority_queue<int>>max_pq_mpp; 
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>>min_pq_mpp; 

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                //max pq conditions 
                if( i-j == 0 || i-j > 0)
                {
                    max_pq_mpp[i-j].push(grid[i][j]); 
                }
                else
                {
                    min_pq_mpp[j-i].push(grid[i][j]); 
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i-j == 0 || i-j>0)
                {
                    grid[i][j] = max_pq_mpp[i-j].top(); 
                    max_pq_mpp[i-j].pop(); 
                }
                else
                {
                    grid[i][j] = min_pq_mpp[j-i].top(); 
                    min_pq_mpp[j-i].pop(); 
                }
            }
        }

        return grid; 
        
    }
};