class Solution {
public:

    int minCuts(int i, int j, vector<int>&cuts, vector<vector<int>>&dp)
    {
        if(i>j) return 0; 

        if(dp[i][j] != -1) return dp[i][j]; 

        int mini = INT_MAX; 
        for(int k=i; k<=j; k++)
        {
            int cost = cuts[j+1] - cuts[i-1] + minCuts(i, k-1, cuts, dp) + minCuts(k+1, j, cuts, dp); 

            mini = min(mini, cost);
        }

        return dp[i][j] = mini; 

    }

    int minCost(int n, vector<int>& cuts) 
    {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        
        vector<vector<int>>dp(c+2, vector<int>(c+2, -1));

        sort(cuts.begin(), cuts.end());
        int ans = minCuts(1, c, cuts, dp);

        return ans; 
        
    }
};