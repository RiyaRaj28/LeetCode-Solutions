class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(vector<vector<int>>&grid, int k, int i, int j, int Xor, vector<vector<vector<int>>>&dp)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(i < 0 || i>= m || j<0 || j>=n)
        {
            return 0;
        }

        if (Xor > 15) return 0;
        if(dp[i][j][Xor]!= -1) return dp[i][j][Xor]; 
        
        if(i == 0 && j == 0)
        {
            if((Xor^grid[0][0]) == k) return 1;
            else return 0;
        }

        // Xor ^= grid[i][j];

        int up = i>0 ? solve(grid, k, i-1, j, Xor^grid[i][j], dp) : 0;
        int left = j>0 ? solve(grid, k, i, j-1, Xor^grid[i][j], dp) : 0;

        return dp[i][j][Xor] = (up + left) % MOD; 
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size(); 
        int n = grid[0].size(); 

        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(16, -1))); 
        return solve(grid, k, m-1, n-1, 0, dp);
        
    }
};