class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        // vector<vector<int>>ans; 
        // set<vector<int>>st;

        int n = nums.size(); 
        sort(nums.begin(), nums.end()); 

        // for(int i=0; i<n-2; i++)
        // {
        //     for(int j=i+1; j<n-1; j++)
        //     {
        //         for(int k=n-1; k>j; k--)
        //         {
        //             int sum = nums[i] + nums[j] + nums[k]; 
        //             if(sum == 0 && i!=j && i!=k && j!=k)
        //             {
        //                 st.insert({nums[i],nums[j],nums[k]}); 
        //             }
        //         }
        //     }
        // }
        vector<vector<int>>ans; 


        for(int i=0; i<n; i++)
        {
            if(i!=0 && nums[i] == nums[i-1]) continue; 
            
            int j = i+1; 
            int k = n-1; 
        
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k]; 
                if(sum < 0 && j<n-1) j++; 
                else if(sum > 0 && k>j) k--;
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j<k && nums[j] == nums[j-1]) j++; 
                    while(j<k && nums[k] == nums[k+1]) k--; 
                }
            }
        }

        return ans; 
        
    }
};