class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        // a -> twice 
        // b -> missing 
        int xorr = 0; 
        int n = grid.size();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int num = i*n + (j+1); 
                xorr ^= num^grid[i][j]; 
            }
        }

        //rightmost set bit 
        int r = xorr & ~(xorr - 1);

        int a = 0, b = 0; 

        for(int i = 0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int num = grid[i][j];

                if(num & r) a ^= num; 
                else b ^= num; 
            }
        }

        for(int i=1; i<=n*n; i++) 
        {
            if(i&r) a ^= i;
            else b ^= i;  
        }     

        int ca = 0; 

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == a) ca++;
            }
        }

        if(ca == 2) return {a,b}; 
        return {b, a};    

    }
};