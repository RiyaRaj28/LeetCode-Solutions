class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //m1 - two looops - n2
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    return{i,j};
                }
            }
        }
        return {-1, -1}; 

        // m2 - hashing
        // map<int, int> mpp; 
        // for(int i=0; i<nums.size(); i++)
        // {
        //     int rem = target - nums[i]; 
        //     if(mpp.find(rem) != mpp.end())
        //     {
        //         return {i, mpp[rem]};
        //     }
        //     mpp[nums[i]] = i; 
        // }
        // return {-1, -1}; 

        //m3 - greedy app only for finding if nums exist or not
        //will not work since we are sorting the array so   indices   will not be the same
        // int left=0, right=nums.size()-1;
        // sort(nums.begin(), nums.end()); 

        // while(left<right)
        // {
        //     int sum = nums[left] + nums[right];
        //     if(sum == target)
        //     {
        //         return{left,right};
        //     }

        //     else if(sum>target) right--;
        //     else left++;
        // }
        // return {-1,-1}; 


        
    }
};