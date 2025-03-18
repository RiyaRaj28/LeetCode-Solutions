class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        // int len = 0; 
        int n = nums.size(); 
        int i=0, j=0, maxlen = 1; 
        int usedbits = 0; 
        while(j < n)
        {
            while((usedbits & nums[j]) != 0)
            {
                usedbits ^= nums[i]; 
                i++; 
            }

            usedbits |= nums[j]; 
           
           maxlen = max(maxlen, j-i+1); 
           j += 1; 
        }

        return maxlen; 
        
    }
};