class Solution {
public:
    // int climbStairs(int n) 
    // {
    //     //tabulation approach with space optimisation 
    //     if(n<=2) return n; 

    //     int n1 = 1; 
    //     int n2 = 2; 

    //     for(int i=3; i<=n; i++)
    //     {
    //         int curr = n1 + n2; 
    //         n1 = n2; 
    //         n2 = curr; 
    //     }

    //     return n2; 
    // }




















   int rec(int n, int ind, vector<int>&dp)
   {
    if(ind == n) return 1; 
    if(ind > n) return 0; 

    int s1 = rec(n, ind+1, dp); 
    int s2 = rec(n, ind+2, dp); 

    return dp[ind] = s1+s2; 
   }

    int climbStairs(int n) 
    {
        if(n <=2) return n; 
        vector<int>dp(n+1, -1); 
        // return rec(n, 0, dp); 

        // int onestep = 1;
        // int twostep = 2;
        
        for(int i=0; i<3; i++) dp[i] = i;
        

        for(int i=3; i<=n; i++)
        {
            int onestep = dp[i-1];
            int twostep = dp[i-2];
            dp[i] = onestep + twostep; 
        }

        return dp[n];
        
    }
};