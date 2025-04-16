class Solution {
public:

    long long count_pairs(int freq)
    {
        long long res = ((freq-1)*(freq))/2; 
        
        return res > 0 ? res : 0; 
    }
    
    long long countGood(vector<int>& nums, int k) 
    {
        long long ans = 0; 
        int n = nums.size(); 

        unordered_map<int, int>mpp; 

        int i = 0, j = 1; 
        int num_of_pairs = 0; 
        mpp[nums[0]]++;

        while(i<j && j<n)
        {
            int prev_pairs = count_pairs(mpp[nums[j]]); 
            mpp[nums[j]]++;
            int curr_pairs = count_pairs(mpp[nums[j]]); 

            num_of_pairs += curr_pairs - prev_pairs; 

            while(num_of_pairs >= k)
            {
                ans += (n-j); 
                prev_pairs = count_pairs(mpp[nums[i]]); 
                mpp[nums[i]]--;
                curr_pairs = count_pairs(mpp[nums[i]]); 
                num_of_pairs += curr_pairs - prev_pairs;
                i++; 
            }
            j++;
        }
        return ans; 
        
        
        
    }
};