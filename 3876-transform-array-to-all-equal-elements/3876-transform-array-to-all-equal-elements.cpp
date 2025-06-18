class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int cntone = 0, cntnegone = 0; 
        bool ones = true, negones = true; 
        vector<int>temp = nums; 
        
        //all ones 
        for(int i=0; i<n-1; i++)
        {
            if(nums[i] == -1)
            {
                nums[i] = 1;
                if(i+1 < n) nums[i+1] *= -1; 
                cntone++; 
            }
        }

        for(int i=0; i<n; i++)
        {
            if(nums[i] == -1) 
            {
                ones = false; 
                break; 
            }
        }

        nums = temp; 

        //all negones 
        for(int i=0; i<n-1; i++)
        {
            if(nums[i] == 1)
            {
                nums[i] = -1;
                if(i+1 < n) nums[i+1] *= -1; 
                cntnegone++; 
            }
        }  

        for(int i=0; i<n; i++)
        {
            if(nums[i] == 1) 
            {
                negones = false; 
                break; 
            }
        }

        // cout << ones << " " << cntone << endl; 
        // cout << negones << " " << cntnegone << endl; 
        // cout << (ones && cntone<=k || negones && cntnegone <= k);

        return  (ones && cntone<=k || negones && cntnegone <= k); 

    }
};