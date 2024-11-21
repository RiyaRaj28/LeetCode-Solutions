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

        int n = nums.size();
        vector<int>hash(n+1, 0); 
        for(int i=0; i<n; i++)
        {
            hash[nums[i]] = 1; 
        }

        for(int i=0; i<=n; i++)
        {
            if(hash[i] == 0) return i; 
        }

        return 0; 
        
    }
};