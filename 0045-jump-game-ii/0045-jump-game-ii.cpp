class Solution {
public:

    // int rec(vector<int>&nums, int n, int ind)
    // {
    //     if(ind >= n-1) return 0; 

    //     int steps = INT_MAX;
    //     for(int i=1; i<=nums[ind]; i++)
    //     {
    //         int next = rec(nums, n, ind+i);
    //         if(next != INT_MAX)
    //         {
    //             steps = min(steps, next+1);
    //         }
            
    //     }
    //     return steps; 
    // }

    // int jump(vector<int>& nums) 
    // {
    //     // int minsteps = INT_MAX;
    //     int n = nums.size(); 
    //     int ans = rec(nums, n, 0); 
    //     if(ans == INT_MAX) return -1;
    //     return ans;  
    // }


    int jump(vector<int>& nums) 
    {
        int n = nums.size(); 
        int l = 0, r = 0; 
        int steps = 0; 

        while(r<n-1)
        {
            int farthest = 0; 

            for(int i=l; i<=r; i++)
            {
                farthest = max(farthest, nums[i]+i);
            }

            l = r+1; 
            r = farthest; 
            steps += 1; 
        }

        return steps; 
    }















};