class Solution {
public:
    // string shortestCommonSupersequence(string str1, string str2) 
    // {
    //     int n = str1.length();
    //     int m = str2.length();

    //     vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    //     for(int i=1; i<=n; i++)
    //     {
    //         for(int j=1; j<=m; j++)
    //         {
    //             if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
    //             else 
    //             {
    //                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    //             }
    //         }
    //     }

    //     // for(int i=0; i<=n; i++)
    //     // {
    //     //     for(int j=0; j<=m; j++)
    //     //     {
    //     //         cout << dp[i][j] << " ";
    //     //     }
    //     //     cout << "\n";
    //     // }

    //     string ans = "";
    //     int i = n, j = m; 
    //     while(i > 0 && j > 0)
    //     {
    //         // have to compare one previous index here 
    //         if(str1[i-1] == str2[j-1])
    //         {
    //             ans += str1[i-1];
    //             i--;
    //             j--;
    //         }
    //         else if(dp[i-1][j] > dp[i][j-1])
    //         {
    //             ans += str1[i-1];
    //             i--;
    //         }
    //         else
    //         {
    //             ans += str2[j-1];
    //             j--; 
    //         }
    //     }

    //     // we are folowwing one based indexing, so we will add the str1[i-1] and str2[j-1]

    //     while(i > 0)
    //     {
    //         ans += str1[i-1];
    //         i--; 
    //     }

    //     while(j > 0)
    //     {
    //         ans += str2[j-1];
    //         j--;
    //     }

    //     string final_ans = ans;
    //     reverse(final_ans.begin(), final_ans.end());

    //     return final_ans; 
    // }












      string shortestCommonSupersequence(string str1, string str2) 
    {
        int n = str1.length();
        int m = str2.length();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else 
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // for(int i=0; i<=n; i++)
        // {
        //     for(int j=0; j<=m; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        int i = n, j=m; 
        string ans = "";

        while(i>0 && j>0)
        {
            if(str1[i-1] == str2[j-1]) 
            {
                ans += str1[i-1]; 
                i--; 
                j--; 
            }
            else if(dp[i][j-1] < dp[i-1][j])
            {
                ans += str1[i-1];
                i--; 
            }
            else 
            {
                ans += str2[j-1]; 
                j--; 
            }
        }

        while(i>0)
        {
            ans += str1[i-1]; 
            i--;
        }
        while(j>0)
        {
            ans += str2[j-1]; 
            j--;
        }
    string final_ans = ans;
        reverse(final_ans.begin(), final_ans.end());

        return final_ans; 

        // return ans; 
    }

};