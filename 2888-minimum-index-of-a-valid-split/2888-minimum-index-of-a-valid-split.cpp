class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size(); 

        int el = 0, cnt = -1; 
        for(int i=0; i<n; i++)
        {
            if(cnt <= 0) 
            {
                el = nums[i]; 
                cnt = 1; 
            }
            else
            {
                if(nums[i] == el) cnt++; 
                else cnt--; 
            }


        }

        cout << el << endl; 
        int dom = el; 

        int idx = 0; 

        int other = 0, domcnt = 0; 
        for(int i=0; i<n; i++)
        {
            if(nums[i] == dom) domcnt++; 
            else other++; 

            if(domcnt > other) 
            {
                idx = i; 
                break;
            }
        }

        other = 0, domcnt = 0; 

        for(int i=idx+1; i<n; i++)
        {
            if(nums[i] == dom) domcnt++; 
            else other++; 
        }
        
        return domcnt > other ? idx : -1; 

        return 0; 
    }
};