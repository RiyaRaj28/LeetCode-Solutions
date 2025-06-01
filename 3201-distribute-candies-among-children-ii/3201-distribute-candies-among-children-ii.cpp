class Solution {
public:

    // long long rec(int ind, int rem, int n, int lt, vector<vector<int>>&memo)
    // {
    //     if(ind == 3) return  rem==0 ? 1 : 0; 
        
    //     if(rem < 0) return 0; 
    //     if(memo[ind][rem] != -1) return memo[ind][rem]; 

    //     long long ways = 0; 
    //     for(int i=0; i<=min(lt, n); i++)
    //     {
    //         ways += rec(ind+1, rem-i, n, lt, memo); 
    //     }

    //     return memo[ind][rem] = ways; 
    // }

    long long distributeCandies(int n, int limit) 
    {
        // vector<vector<int>>memo(4, vector<int>(n+1, -1)); 
        // return rec(0, n, n, limit, memo); 

        // vector<vector<long long>>dp(4, vector<long long>(n+1, 0)); 
        // dp[3][0] = 1; 

        // for(int i=2; i>=0; i--)
        // {
        //     for(int rem = 0; rem <=n; rem++)
        //     {
        //         long long ways = 0; 
        //         for(int j=0; j<=min(limit, rem); j++)
        //         {
        //             ways += dp[i+1][rem-j]; 
        //         }

        //         dp[i][rem] = ways; 
        //     }
        // }
        
        // return dp[0][n]; 

        // int ways = 0; 

        // for(int ch1 = 0; ch1 <= min(limit, n); ch1++)
        // {
        //     for(int ch2 = 0; ch2 <= min(limit, n-ch1); ch2++)
        //     {
        //         // for(int ch3 = 0; ch3 <= min(n-ch1-ch2, limit); ch3++)
        //         // {
        //         //     if(ch1 + ch2 + ch3 == n) ways++; 
        //         // }
        //         int ch3 = n-ch1-ch2; 
        //         if(ch3 <= limit) ways++; 
        //     }
        // }

        // return ways; 

        long long ways = 0; 

        for(int i=max(0,n-2*(limit)); i<=min(limit, n); i++)
        {
            // for(int j=max(0,n-i-limit); j<=min(limit, n-i); j++)
            
                // int k = n-i-j; 
                // if(k <= limit) ways++; 

                int N = n-i;
                int ch2min = max(0,N-limit); 
                int ch2max = min(limit, N);

                ways += ch2max - ch2min + 1; 
            // }
        }

        return ways; 
        


    }
};