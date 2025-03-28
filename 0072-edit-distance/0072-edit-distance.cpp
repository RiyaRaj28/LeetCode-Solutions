class Solution {
public:

    // int solve(int i, int j, string &s1, string &s2, vector<vector<int>>&dp)
    // {
    //     if(i<0) return j+1;
    //     if(j<0) return i+1; 

    //     if(s1[i] == s2[j]) return solve(i-1, j-1, s1, s2, dp);

    //     int insert = 1 + solve(i, j-1, s1, s2, dp);
    //     int todelete = 1 + solve(i-1, j, s1, s2, dp);
    //     int replace = 1 + solve(i-1, j-1, s1, s2, dp);

    //     return min(insert, min(todelete, replace)); 
    // }

    // int minDistance(string word1, string word2) 
    // {
    //     int n = word1.length(); 
    //     int m = word2.length(); 
    //     vector<vector<int>>dp(n, vector<int>(m, -1));
    //     return solve(n-1, m-1, word1, word2, dp); 
    // }
    
    // int minDistance(string &word1, string &word2) 
    // {
    //     int n = word1.size();
    //     int m = word2.size();
    //     vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    //     // string 1 is parallel to row
    //     // string 2 is parallel to col

    //     // when 0th col -> parallel to col -> str2 at index 0 
    //     // meaning we have got the second string completely
    //     // or len of second string is 0 -> need 0 ops

    //     for(int i=0; i<=n; i++) dp[i][0] = i; 
    //     for(int j=0; j<=m; j++) dp[0][j] = j;

    //     for(int i=1; i<=n; i++)
    //     {
    //         for(int j=1; j<=m; j++)
    //         {
    //             if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
    //             else 
    //             {
    //                 int insert = 1 + dp[i][j-1];
    //                 int todelete = 1 + dp[i-1][j];
    //                 int replace = 1 + dp[i-1][j-1];

    //                 dp[i][j] = min(insert, min(todelete, replace));
    //             }
    //         }
    //     }

    //     return dp[n][m]; 
    // }

// int minDistance(string &word1, string &word2) 
//     {
//         int n = word1.size();
//         int m = word2.size();

//         // string 1 is parallel to row
//         // string 2 is parallel to col

//         // when 0th col -> parallel to col -> str2 at index 0 
//         // meaning we have got the second string completely
//         // or len of second string is 0 -> need 0 ops

//         vector<int>prev(m+1, 0), curr(m+1, 0);
//         for(int i=0; i<=m; i++) prev[i] = i; 

//         // for(int i=0; i<=n; i++) dp[i][0] = i; 

//         for(int i=1; i<=n; i++)
//         {
//             //need to update the current row also to satisfy the second base case 
//             curr[0] = i; 
//             for(int j=1; j<=m; j++)
//             {
//                 if(word1[i-1] == word2[j-1]) curr[j] = prev[j-1];
//                 else 
//                 {
//                     int insert = 1 + prev[j-1];
//                     int todelete = 1 + prev[j];
//                     int replace = 1 + curr[j-1];

//                     curr[j] = min(insert, min(todelete, replace));
//                 }
//             }
//             prev = curr; 
//         }

//         return prev[m]; 
//     }








   int solve(string &word1, string &word2, int ind1, int ind2)
   {
        //base cases 
        if(ind1<0) return ind2+1; 
        if(ind2<0) return ind1+1;  

        //match 
        if(word1[ind1] == word2[ind2]) return solve(word1, word2, ind1-1, ind2-1);
        
            int insert = 1+ solve(word1, word2, ind1, ind2-1);
            int todelete = 1+ solve(word1, word2, ind1-1, ind2);
            int replace = 1 + solve(word1, word2, ind1-1, ind2-1); 
            // return insert+todelete+replace;
        

        return min(insert, min(todelete, replace));
   }

    int minDistance(string &word1, string &word2) 
    {
        int l1 = word1.length();
        int l2 = word2.length(); 
        vector<vector<int>>table(l1+1, vector<int>(l2+1, 0));

        for(int i=0; i<=l1; i++) table[i][0] = i;
        for(int j=0; j<=l2; j++) table[0][j] = j;

        for(int i=1; i<=l1; i++)
        {
            for(int j=1; j<=l2; j++)
            {
                if(word1[i-1]==word2[j-1]) table[i][j] = table[i-1][j-1];
                else 
                {
                    int insert = 1 + table[i][j-1];
                    int todelete = 1 + table[i-1][j];
                    int replace = 1 + table[i-1][j-1]; 
                    table[i][j] = min(insert, min(todelete, replace));
                }
            }
        }

        // return solve(word1, word2, l1-1, l2-1); 
        return table[l1][l2]; 
    }



    

};