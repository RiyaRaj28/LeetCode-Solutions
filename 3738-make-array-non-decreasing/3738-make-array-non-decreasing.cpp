class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int maxi = nums[0]; 

        // stack<int>st; 
        // int n = nums.size(); 

        // for(int i=n-1; i>=0; i--)
        // {
        //     while(!st.empty() && nums[st.top()]<nums[i])
        //     {
        //         st.pop(); 
        //     }

        //     st.push(i); 
        //     int s = st.size(); 
        //     maxi = max(maxi, s); 
        // }

        // return maxi; 

        int cnt = 1; 
        int n = nums.size();
        for(int i=1; i<n; i++)
        {
            if(nums[i] >= maxi) 
            {
                maxi = nums[i];
                cnt++;
            }
        }

        return cnt; 
        
    }
};