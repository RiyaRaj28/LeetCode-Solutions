class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        // int n = nums.size()+1; 
        // for(int i=0; i<n+1; i++)
        // {
        //     bool flag = false; 
        //     for(int j=0; j<n-1; j++)
        //     {
        //         if(i == nums[j]) 
        //         {
        //             flag = true;
        //             break;
        //         }
        //     }
        //     if(flag == false) return i;
        // }
        // return 0; 

        // int n = nums.size();
        // vector<int>hash(n+1, 0); 
        // for(int i=0; i<n; i++)
        // {
        //     hash[nums[i]] = 1; 
        // }

        // for(int i=0; i<=n; i++)
        // {
        //     if(hash[i] == 0) return i; 
        // }

        // return 0; 

        // int n = nums.size();
        // int sum = 0; 
        // for(int i=0; i<n; i++)
        // {
        //     sum += nums[i];
        // }
        // int total_sum = n*(n+1)/2; 

        // return total_sum - sum; 

        int n = nums.size(); 
        int xor1 = 0; 
        for(int i=0; i<=n; i++)
        {
            xor1 = xor1 ^ i; 
        }

        int xor2 = 0; 
        for(int i=0; i<n; i++)
        {
            xor2 = xor2 ^ nums[i];
        }

        return xor1 ^ xor2; 
    }
};