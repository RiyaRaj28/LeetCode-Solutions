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
    //     unordered_map<long, priority_queue<int>>mpp; 

    //     for(int i=0; i<nums.size(); i++)
    //     {
    //         long sum = sumOfDig(nums[i]); 
    //         // mpp[sum] += 1; 

    //         mpp[sum].push(nums[i]); 
    //     }

    // long ans = 0; 

    // for(auto it=mpp.begin(); it!= mpp.end(); it++)
    // {
    //     if((it->second).size() > 1)
    //     {
    //         long first = (it->second).top(); 
    //         (it->second).pop(); 

    //         long second = (it->second).top(); 
    //         (it->second).pop(); 

    //         ans = max(ans, first+second); 
    //     }
    // }

    // return ans == 0 ? -1 : ans; 

   vector<int>hash(82, 0); 

   // if the new element is greater than the previous stored element of
   // the same digit sum then we update that value 

   // else we will just update the maxsum every time 
   
   int ans = 0; 
   for(int i=0; i<nums.size(); i++)
   {
      long sum = sumOfDig(nums[i]); 

      if(hash[sum] == 0) hash[sum] = nums[i]; 
      else 
      { 
        ans = max(ans, hash[sum]+nums[i]);
        hash[sum] = max(hash[sum], nums[i]); 
      }
   }

   return ans == 0 ? -1 : ans; 






















    }


};