class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        // map : sumofpairs -> {i,j} 
        // search for 0 - curr in map 
        // return i,j,k 
        // set -> unique elements? 

        // unordered_map<int, vector<pair<int, int>>>mpp; 

        // set<vector<int>>st; 

        // int n = nums.size();
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=i+1; j<n; j++)
        //     {
        //         if(i!=j)
        //         {

        //             mpp[nums[i]+nums[j]].push_back({i,j}); 
        //         }
        //     }
        // }
        
        // for(int i=0; i<n; i++)
        // {
        //     int tofind = 0 - nums[i]; 

        //     if(mpp.find(tofind) != mpp.end())
        //     {
        //         for(int p=0; p<mpp[tofind].size(); p++)
        //         {
        //         int j = mpp[tofind][p].first; 
        //         int k = mpp[tofind][p].second; 

        //         if(i!= j && i!=k)
        //         {
        //             vector<int>temp = {nums[i],nums[j],nums[k]}; 
        //             sort(temp.begin(), temp.end()); 

        //             st.insert(temp); 
        //         }
        //         }
        //     }
        // }

        // vector<vector<int>>ans; 

        // // while(!st.empty())
        // // {
        // //     vector<int>t = st.top(); 
        // //     ans.push_back(t);
        // //     st.pop(); 
        // // }

        // for(auto it : st)
        // {
        //     vector<int>t = it; 
        //     ans.push_back(t); 
        // }

        // return ans; 

        
        vector<vector<int>>ans; 
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(i!= 0 && nums[i] == nums[i-1]) continue; 

            int j = i+1; 
            int k = n-1; 

            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k]; 

                if(j<n-1 && sum < 0) j++; 
                else if(k>j && sum > 0) k--;
                else 
                {
                    ans.push_back({nums[i], nums[j], nums[k]}); 
                    j++;
                    k--;

                    while(j<k && nums[j]==nums[j-1]) j++; 
                    while(j<k && nums[k]==nums[k+1] ) k--; 
                }
            }
        }

        return ans; 

    }

};