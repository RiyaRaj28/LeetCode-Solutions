class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) 
    {
        // int n = nums.size(); 
        // vector<int>result(n); 
        // for(int i=0; i<nums.size(); i++)
        //     {
        //         if(nums[i] > 0)
        //         {
        //             int k = nums[i];
        //             k = k%n; 
        //             int ind = (i + k) % n; 
        //             result[i] = nums[ind];  
        //         }

        //         else if(nums[i] == 0)
        //         {
        //             result[i] = nums[i];
        //         }

        //         else
        //         {
        //             // when negative have to rotate to left 
        //             // int k = abs(nums[i]);
        //             // int ind = abs(i - k + n)%n; 
        //             // result[ind] = nums[i]; 

        //             int k = abs(nums[i]);
        //             k = k%n; 

        //             if(i >= k) result[i-k] = nums[i]; 
        //             else result[n - k + i] = nums[i]; 
        //         }
        //     }

        // return result; 

        int n = nums.size(); 

        vector<int>result(n, -1); 
        for(int i=0; i<n; i++)
        {
            if(!nums[i]) result[i] = nums[i];

            else if(nums[i] < 0)
            {
                int ind = (i - abs(nums[i]))%n; 
                while(ind < 0) ind += n;
                result[i] = nums[ind];
            }
            else
            {
                int ind = (i + nums[i])%n; 
                while(ind < 0) ind += n;
                result[i] = nums[ind];
            }
        }

        return result; 
        
    
        
    }
};