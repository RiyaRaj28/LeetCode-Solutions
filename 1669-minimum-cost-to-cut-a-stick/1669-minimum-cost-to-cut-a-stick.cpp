// class Solution {
// public:

//     int minCuts(int i, int j, vector<int>&cuts, vector<vector<int>>&dp)
//     {
//         if(i>j) return 0; 

//         if(dp[i][j] != -1) return dp[i][j]; 

//         int mini = INT_MAX; 
//         for(int k=i; k<=j; k++)
//         {
//             int cost = cuts[j+1] - cuts[i-1] + minCuts(i, k-1, cuts, dp) + minCuts(k+1, j, cuts, dp); 

//             mini = min(mini, cost);
//         }

//         return dp[i][j] = mini; 

//     }

//     int minCost(int n, vector<int>& cuts) 
//     {
//         int c = cuts.size();
//         cuts.push_back(n);
//         cuts.insert(cuts.begin(), 0);
        
//         vector<vector<int>>dp(c+1, vector<int>(c+1, -1));

//         sort(cuts.begin(), cuts.end());
//         int ans = minCuts(1, c, cuts, dp);

//         return ans; 
        
//     }
// };


class Solution {
public:

    int minCost(int n, vector<int>& cuts) 
    {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        
        sort(cuts.begin(), cuts.end());

        vector<vector<int>>dp(c+2, vector<int>(c+2, 0));

        for(int i=c; i>=1; i--)
        {
            for(int j=1; j<=c; j++)
            {
                if(i>j) continue; 
                int mini = INT_MAX; 

                for(int k=i; k<=j; k++)
                {
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j]; 
                    mini = min(mini, cost);
                }
                dp[i][j] = mini; 
            }
        }

        return dp[1][c]; 
    }
};