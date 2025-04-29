class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int cnt = 0; 
        int n = nums.size(); 
        int maxe = *max_element(nums.begin(), nums.end()); 

        int i = 0, j=0;
        long long total = 0; 
        while(j<n)
        {
            if(nums[j] == maxe)
            {
                cnt++; 

                if(cnt == k)
                {
                    while(cnt >= k)
                    {
                        total += n-j;
                        if(nums[i] == maxe) cnt--; 
                        i++; 
                    }
                }
            }

            // if(cnt == k) total++;
            j++; 
        }
        return total; 
        
    }
};