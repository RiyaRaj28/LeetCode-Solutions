class Solution {
public:
    int majorityElement(vector<int>& arr) 
    {
        int n = arr.size(); 
        // map<int, int>mpp; 

        // for(int i=0; i<n; i++)
        // {
        //     mpp[nums[i]]++; 
        // }

        // int cnt = 0; 
        // int ans = -1; 
        // for(auto it : mpp)
        // {
        //     if(it.second > n/2) ans = it.first; 
        // }

        // return ans; 

        int cnt = 0; 
        int el = arr[0];
        for(int i=0; i<n; i++)
        {
            if(cnt == 0)
            {
                el = arr[i];
                cnt = 1; 
            }
            else if(arr[i] == el)
            {
                cnt += 1;
            }
            else
            {
                cnt -= 1; 
            }

        }

        return el; 
        
    }
};