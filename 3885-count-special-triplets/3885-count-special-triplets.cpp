class Solution {
public:
    const int MOD = 1e9 + 7; 
    int specialTriplets(vector<int>& nums) 
    {
        // // n2 approach 
        // int cnt = 0; 
        // int n = nums.size(); 
        // for(int i=0; i<n; i++)
        // {
        //     bool left = false, right = false; 
        //     int lcnt = 0, rcnt = 0; 
        //     for(int j=0; j<i; j++)
        //     {
        //         if(nums[j] == 2*nums[i])
        //         {
        //             left = true;
        //             lcnt++; 
        //         }
        //     }

        //     if(left)
        //     {
        //         for(int j=i+1; j<n; j++)
        //         {
        //             if(nums[j] == 2*nums[i])
        //             {
        //                 right = true; 
        //                 rcnt++; 
        //             }
        //         }
        //     }

        //     if(left==true && right==true) cnt += (lcnt*rcnt)%MOD; 
        // }

        // return cnt%MOD; 
        

        // O(n) approach 
        // unordered_map<int, vector<int>>mpp; 
        // long long cnt = 0; 
        // int n = nums.size(); 
        // for(int i=0; i<n; i++)
        // {
        //     mpp[nums[i]].push_back(i); 
        // }

        // for(int i=0; i<n; i++)
        // {
        //     int lcnt = 0, rcnt = 0; 
        //     int num = nums[i]; 
        //     int twice = nums[i]*2; 
        //     if(mpp.find(twice) != mpp.end())
        //     {
        //         for(int j=0; j<mpp[twice].size(); j++)
        //         {
        //             if(mpp[twice][j] < i) lcnt++; 
        //             else if(mpp[twice][j] > i) rcnt++; 
        //         }
        //     }

        //     cnt += (lcnt*rcnt)%MOD;
        // }
        // return cnt%MOD; 


        unordered_map<int, int>lt, rt; 
        for(int it : nums) rt[it]++; 

        int n = nums.size(); 
        long long cnt = 0; 
        for(int i=0; i<n; i++)
        {
            int num = nums[i]; 
            int twice = 2*num; 
            rt[num]--;
            cnt += ((long long)lt[twice]*rt[twice])%MOD; 
            lt[num]++;
            
        }

        return cnt%MOD; 









    }
};