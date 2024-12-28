class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        //1 2 3 
        // we take and update it at that index only if 
        // arr[i] % arr[prev] == 0 && dp[prev] + 1 > dp[i] 
        // dp[i] = dp[prev] + 1 
        // lastInd = i 
        // we need to find length and backtrak also 

    //     int n = nums.size();
    //     int lastInd = -1; 
    //     sort(nums.begin(), nums.end()); 
    //     vector<int>hash(n, 1);
    //     vector<int>dp(n, 1);
    //     int maxi = -1; 
    //     for(int i=1; i<nums.size(); i++)
    //     {
    //         hash[i] = i;
    //         for(int prev=0; prev<i; prev++)
    //         {
    //             if(nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i])
    //             {
    //                 dp[i] = dp[prev] + 1;
    //                 hash[i] = prev; 
    //             }
    //         }

    //         if(dp[i] > maxi)
    //         {
    //             maxi = dp[i];
    //             lastInd = i;  
    //         }
    //     }

    // vector<int> temp;
    // temp.push_back(nums[lastInd]);

    // while (hash[lastInd] != lastInd) {
    //     lastInd = hash[lastInd];
    //     temp.push_back(nums[lastInd]);
    // }

    // reverse(temp.begin(), temp.end());
    // return temp;






  // we will update the dp and hash array only if arr[i] % arr[prev] == 0

  int n = nums.size(); 
  sort(nums.begin(), nums.end()); 
  vector<int>dp(n, 1), hash(n, 0); 
  int maxi = 1; 
  int last = 0; 

  for(int i=1; i<n; i++)
  {
      hash[i] = i;
      for(int prev=0; prev<i; prev++)
      {
            if(nums[i]%nums[prev]==0 && dp[prev]+1>dp[i])
            {
                dp[i] = dp[prev]+1; 
                hash[i] = prev;
            }
      }

      if(dp[i]>maxi)
      {
          maxi = dp[i]; 
          last = i; 
      }
  }

  vector<int>temp; 
  while(last!=hash[last])
  {
       temp.push_back(nums[last]); 
       last = hash[last];
  }

  temp.push_back(nums[last]);
  reverse(temp.begin(), temp.end());
  return temp; 
    }
};