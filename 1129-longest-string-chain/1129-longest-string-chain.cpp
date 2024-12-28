// class Solution {
// public:
//     static bool comp(const string &s1, const string &s2)
//     {
//         return s1.size() < s2.size(); 
//     }

//     //bc bcd bcda 
//     bool check(string &s1, string &s2)
//     {
//         if(s1.size() != 1 + s2.size()) return false; 
         
//         int first =0, second = 0; 
//         while(first != s1.size())
//         {
//             if(s1[first] == s2[second])
//             {
//                 first++; 
//                 second++; 
//             }
//             else
//             {
//                 first++; 
//             }
//         }

//         if(first == s1.size() && second == s2.size()) return true;
//         else return false; 
//     }

//     int longestStrChain(vector<string>& words) 
//     {
//         //writing the typical LIS code 
//         int n = words.size(); 
//         vector<int>dp(n, 1);
//         sort(words.begin(), words.end(), comp); 

//         int maxi = 1; 
//         for(int i=1; i<n; i++)
//         {
//             for(int prev=0; prev<i; prev++)
//             {
//                 if(check(words[i], words[prev]) && 
//                     dp[prev] + 1 > dp[i])
//                     {
//                         dp[i] = dp[prev] + 1; 
//                     }
//             }

//             if(maxi<dp[i]) maxi = dp[i]; 
//         }
//         return maxi; 
//     }
// };




class Solution {
public:

static bool comp(string s1, string s2)
{
    return s1.size()<s2.size();
}

bool checkSuccessor(string s1, string s2)
{
    // int i=0, j=0; 

    int n = s1.size(), m = s2.size();
    if(n != m+1) return false; 

    int first = 0, second = 0;
    while(first != n)
    {
        if(s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
            first++;
    }

    if(first != n || second != m) return false; 
    return true; 
}
   
    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(), words.end(), comp);
        int n = words.size(); 
        // vector<vector<int>>table(n+1, vector<int>(n+2, 0)); 
        // for(int i=0; i<n+2; i++) table[n][i] = 1;

        // for(int i=n-1; i>=0; i--)
        // {
        //     for(int prev=i-2; prev>=-1; prev--)
        //     {
        //         int take = checkSuccessor(words[i], words[prev+1]) ? 1 + table[i+1][i+1] : INT_MIN; 
        //         int nottake = table[i+1][prev+1];

        //         table[i][prev+1] = max(take, nottake);
        //     }
        // }

        // return table[0][1];
        vector<int>dp(n, 1);
        int maxi = 1; 

        for(int i=0; i<n; i++)
        {
            for(int prev=0; prev<i; prev++)
            {
                if(checkSuccessor(words[i], words[prev]) && dp[i]<dp[prev]+1)
                {
                    dp[i] = dp[prev]+1;
                }
            }
            if(dp[i]>maxi) maxi = dp[i];
        }

        return maxi; 
    }
};