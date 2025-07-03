class Solution {
public:
    
    // int t[46];

    // int solve(int n)
    // {
    //     if(n<0) return 0; 

    //     if(t[n] != -1) return t[n];

    //     if(n == 0) return 1; 

    //     int one_step = solve(n-1);
    //     int two_step = solve(n-2);

    //     return t[n] = one_step + two_step; 
    // }

    // int climbStairs(int n) 
    // {
    //     memset(t, -1, sizeof(t)); 
    //     return solve(n);
    // }

    // int climbStairs(int n) 
    // {
    //   if(n == 0 || n==1 || n==2 || n== 3) return n; 

    //   int a = 1; 
    //   int b = 2; 
    //   int c = 3; 

    //   for(int i=3; i<=n; i++)
    //   {
    //     c = b + a; 

    //     int temp_b = b; 
    //     b = c; 
    //     a = temp_b; 
    //   }

    //   return c; 
    // }

    // int arr[46];
    
    // int solve(int n)
    // {
    //     if(n == 1 || n==2 || n==3) return n; 
    //     arr[0] = 0; 
    //     arr[1] = 1; 
    //     arr[2] = 2;

    //     for(int i=3; i<=n; i++)
    //     {
    //         arr[i] = arr[i-1] + arr[i-2]; 
    //     }
    //     return arr[n];
    // }

    // int climbStairs(int n) 
    // {
    //     //we're going to store the values in an array 

    //     return solve(n);

    // }






    // int solve(int n, vector<int>&dp)
    // {
    //     if(n == 0 ) return 1; 
    //     if(n<0) return 0; 

    //     if(dp[n] != -1) return dp[n]; 

    //     int one_step = solve(n-1, dp); 
    //     int two_step = solve(n-2, dp); 

    //     return dp[n] = one_step + two_step; 
        
    // }

    // int climbStairs(int n) 
    // {
    //     vector<int>dp(n+1, -1); 
    //     dp[0] = 0; 

    //     solve(n, dp); 
    //     return dp[n]; 

    // }







    // int solve(int n, vector<int>&dp)
    // {
    //     if(n == 0 ) return 1; 
    //     if(n<0) return 0; 

    //     if(dp[n] != -1) return dp[n]; 

    //     int one_step = solve(n-1, dp); 
    //     int two_step = solve(n-2, dp); 

    //     return dp[n] = one_step + two_step; 
        
    // }

    int climbStairs(int n) 
    {
        vector<int>dp(n+1, 0);
        if(n== 1) return 1; 
        if(n==2) return 2; 
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2; 

        for(int i=3; i<=n; i++)
        {
            // cout << dp[i-1] << endl;
            // cout << dp[i-2] << endl;
            dp[i] = dp[i-1] + dp[i-2];
        } 
        // cout << dp[n] << endl; 
        return dp[n]; 




    }




};