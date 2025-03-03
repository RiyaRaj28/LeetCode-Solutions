class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        // vector<int>t1, t2, t3; 

        int n = nums.size(); 
        // for(int i=0; i<n; i++)
        // {
        //     if(nums[i] < pivot) t1.push_back(nums[i]); 
        //     else if(nums[i] > pivot) t2.push_back(nums[i]); 
        //     else t3.push_back(nums[i]); 
        // }

        // vector<int>ans; 
        // for(int i=0; i<t1.size(); i++) ans.push_back(t1[i]); 
        // for(int i=0; i<t3.size(); i++) ans.push_back(t3[i]); 
        // for(int i=0; i<t2.size(); i++) ans.push_back(t2[i]); 

        // return ans; 

        int lessthan = 0, equalto = 0, greaterthan = 0; 
        for(int i=0; i<n; i++)
        {
            if(nums[i] < pivot) lessthan++; 
            else if(nums[i] > pivot) greaterthan++; 
            else equalto++; 
        }

        int less = 0, equal = lessthan, greater = lessthan + equalto; 
        vector<int>ans(n); 
        int i = 0; 

        while(i<n)
        {
            if(nums[i] < pivot) ans[less++] = nums[i]; 
            else if(nums[i] > pivot) ans[greater++] = nums[i]; 
            else ans[equal++] = nums[i];  

            i++; 
        }

        return ans; 
        
        
    }
};