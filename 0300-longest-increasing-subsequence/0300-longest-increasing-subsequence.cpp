class Solution {
public:

    // int solve(int ind, int prev, int n, vector<int>&nums)
    // {
    //     if(ind == n) return 0; 

    //     int nottake = solve(ind+1, prev, n, nums);
    //     int take = INT_MIN; 
    //     if(prev == -1 || nums[prev] < nums[ind])
    //         take = 1 + solve(ind+1, ind, n, nums);

    //     return max(take, nottake); 
    // }

    // int lengthOfLIS(vector<int>& nums) 
    // {
    //     int n = nums.size();
    //     return solve(0, -1, n, nums); 
        
    // }

    // MEMOISATION 

    //     int solve(int ind, int prev, int n, vector<int>&nums, vector<vector<int>>&dp)
    // {
    //     if(ind == n) return 0; 

    //     if(dp[ind][prev+1] != -1) return dp[ind][prev+1]; 

    //     int nottake = solve(ind+1, prev, n, nums, dp);
    //     int take = INT_MIN; 
    //     if(prev == -1 || nums[prev] < nums[ind])
    //         take = 1 + solve(ind+1, ind, n, nums, dp);

    //     return dp[ind][prev+1] = max(take, nottake); 
    // }

    // int lengthOfLIS(vector<int>& nums) 
    // {
    //     int n = nums.size();
    //     vector<vector<int>>dp(n, vector<int>(n+1, -1));
    //     return solve(0, -1, n, nums, dp); 
        
    // }

// TABULATION !!!
// int lengthOfLIS(vector<int>& nums) 
//     {
//         int n = nums.size(); 
//          vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        
//         for(int i=n-1; i>-1; i--)
//         {
//             for(int prev = i-1; prev >= -1; prev--)
//             {
//                 int nottake = dp[i+1][prev+1]; 
//                 int take = INT_MIN; 
//                 if(prev == -1 || nums[i] > nums[prev])
//                 {
//                     take = 1 + dp[i+1][i+1]; 
//                 }
                
//                 dp[i][prev+1] = max(take, nottake); 
//             }
//         }

//         for(int i=0; i<=n; i++)
//         { 
//             cout << "row[" << i << "] : ";
//             for(int j=0; j<=n; j++)
//             {
//                 cout << dp[i][j] << " ";
//             }
//             cout << "\n"; 
//         }
        
//         return dp[0][0]; 
//     }


// SPACE OPTIMISED

// int lengthOfLIS(vector<int>& nums) 
//     {
//         int n = nums.size(); 
//          vector<int>front(n+1), curr(n+1); 
        
//         for(int i=n-1; i>-1; i--)
//         {
//             for(int prev = i-1; prev >= -1; prev--)
//             {
//                 int nottake = front[prev+1]; 
//                 int take = INT_MIN; 
//                 if(prev == -1 || nums[i] > nums[prev])
//                 {
//                     take = 1 + front[i+1]; 
//                 }
                
//                 curr[prev+1] = max(take, nottake); 
//             }

//             front = curr; 
//         }
        
//         return front[0]; 
//     }

// EVEN MORE SPACE OPTIMISED 
// int lengthOfLIS(vector<int>& nums) 
// {
//     int n = nums.size();
//     vector<int>dp(n, 1); 
//     for(int ind = 0; ind<n; ind++)
//     {
//         for(int prev = 0; prev<ind; prev++)
//         {
//             if(nums[prev] < nums[ind]) 
//             {
//                 dp[ind] = max(1 + dp[prev], dp[ind]); 
//             }
//         }
//     }
//     int ans = INT_MIN; 

//     for(int i=0; i<n; i++)
//     {
//         if(dp[i] > ans) ans = dp[i];
//     }

//     return ans; 
// }

















// have to solve such that we get the longest increasing subsequence count
//iske liye, take arr[i] only if it is greater that the previous index value 


int solve(vector<int>&nums, int ind, int prev, vector<vector<int>>&dp)
{
    int n= nums.size();
    if(ind == n) return 0; 

    if(dp[ind][prev+1] != -1) return dp[ind][prev+1]; 

    int take = (prev==-1 || nums[ind]>nums[prev]) ? 1 + solve(nums, ind+1, ind, dp) : INT_MIN; 
    int nottake = solve(nums, ind+1, prev, dp); 

    return dp[ind][prev+1] = max(take, nottake); 

}

int lengthOfLIS(vector<int>& nums) 
{
    int n = nums.size();
    vector<vector<int>>dp(n, vector<int>(n+1, -1));

    // return solve(nums, 0, -1, dp); 

    vector<vector<int>>table(n+1, vector<int>(n+1, 0)); 
    // for(int i=0; i<=n; i++) table[n][i] = 1; 
        // for(int i=0; i<=n; i++)
        // { 
        //     cout << "row[" << i << "] : ";
        //     for(int j=0; j<=n; j++)
        //     {
        //         cout << table[i][j] << " ";
        //     }
        //     cout << "\n"; 
        // }

        //space optimised 
        vector<int>ahead(n+1, 0); 
        vector<int>curr(n+1, 0);

    // for(int i=n-1; i>=0; i--)
    // {
    //     for(int j=i-1; j>=-1; j--)
    //     {
    //         // int take = (j==-1 || nums[i]>nums[j]) ? 1 + table[i+1][i+1] : INT_MIN;
    //         // int nottake = table[i+1][j+1];

    //         // table[i][j+1] = max(take, nottake); 

    //         int take = (j==-1 || nums[i]>nums[j]) ? 1 + ahead[i+1] : INT_MIN; 
    //         int nottake = ahead[j+1];

    //         curr[j+1] = max(take, nottake);
    //     }
    //     ahead = curr; 
    
    // }

    // return ahead[0]; 


        // for(int i=0; i<=n; i++)
        // { 
        //     cout << "row[" << i << "] : ";
        //     for(int j=0; j<=n; j++)
        //     {
        //         cout << table[i][j] << " ";
        //     }
        //     cout << "\n"; 
        // }

    // return table[0][0]; 



    //binary search 

    // we try to find a greater element in i-1 to 0 
    // if found, add 1
    // else do a lower bound bs and place element at that index ?

    vector<int>temp; 

    temp.push_back(nums[0]);

    for(int i=1; i<nums.size(); i++)
    {
        if(nums[i]>temp.back()) temp.push_back(nums[i]);
        else
        {
            int lb = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[lb] = nums[i];
        }
    }

    for(int i=0; i<nums.size(); i++) cout << nums[i] << " ";
    cout << "\n"; 
    for(int i=0; i<temp.size(); i++) cout << temp[i] << " "; 

    return temp.size();
}
};