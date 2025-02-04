class Solution {
public:
    // int cnt(vector<int>& nums, int k, int start, int end)
    // {
        // unordered_map<int, int>mpp; 
        // // int n = nums.size(); 
        // int maxfreq = 0; 

        // // int k_cnt = 0; 
        // for(int i=start; i<end; i++)
        //     {
        //         if(nums[i] != k) mpp[nums[i]]++; 
        //         // mpp[nums[i]]++; 
        //         // if(nums[i] == k) k_cnt++; 

        //         maxfreq = max(maxfreq, mpp[nums[i]]);
        //     }        
        // return maxfreq;    
    // }

    int maxFrequency(vector<int>& nums, int k) 
    {
        int n = nums.size(); 
        // int k_cnt = 0; 
        // int maxfreq = 0; 

        // for(int i=0; i<n; i++)
        //     {
        //         // if(nums[i] == k) k_cnt += 1;

        //         int left_cnt = i > 0 ? cnt(nums, k, 0, i) : INT_MIN;
        //         int right_cnt = i<n-1 ? cnt(nums, k, i+1, n) : INT_MIN;

        //         int curr_max =  nums[i] == k ? 1 + max(left_cnt, right_cnt) : max(left_cnt, right_cnt); 
        //         maxfreq = max(maxfreq, curr_max);                 
            
        //     }
        // maxfreq = max(maxfreq, cnt(nums, k, 0, n)); 
        // return maxfreq; 

        // int cnt = 0, mxcnt = 0; 
        int original = count(nums.begin(), nums.end(), k); 
        int mxcnt = 0;

        for(int target=1; target<=50; target++)
        {
            if(target == k) continue; 
            int cnt = 0; 
            for(int el=0; el<n; el++)
            {
                if(nums[el] == target)
                {
                    cnt += 1; 
                    mxcnt = max(mxcnt, cnt); 
                }
                else if(nums[el] == k) if(cnt>0) cnt -= 1; 
                else continue; 
            }
        }

        return mxcnt+original; 
    }
};