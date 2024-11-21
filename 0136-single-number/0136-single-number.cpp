class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        // map<long long, int>mpp; 
        // for(int i=0; i<nums.size(); i++)
        // {
        //     mpp[nums[i]]++;
        // }

        // for(auto it: mpp)
        // {
        //     if(it.second == 1) return it.first; 
        // }
        // return 0; 
        
        int xor1 = 0; 
        for(int i=0; i<nums.size(); i++)
        {
            xor1 = xor1 ^ nums[i];
        }
        return xor1; 
    }
};