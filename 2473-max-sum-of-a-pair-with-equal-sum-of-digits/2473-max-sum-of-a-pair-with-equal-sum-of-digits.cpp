class Solution {
public:

    long sumOfDig(long num)
    {
        long sum = 0; 
        while(num > 0)
        {
            sum += num%10; 
            num = num/10; 
        }

        return sum; 
    }

    int maximumSum(vector<int>& nums) 
    {
        unordered_map<long, priority_queue<int>>mpp; 

        for(int i=0; i<nums.size(); i++)
        {
            long sum = sumOfDig(nums[i]); 
            // mpp[sum] += 1; 

            mpp[sum].push(nums[i]); 
        }

    long ans = 0; 

    for(auto it=mpp.begin(); it!= mpp.end(); it++)
    {
        if((it->second).size() > 1)
        {
            long first = (it->second).top(); 
            (it->second).pop(); 

            long second = (it->second).top(); 
            (it->second).pop(); 

            ans = max(ans, first+second); 
        }
    }

    return ans == 0 ? -1 : ans; 
    }


};