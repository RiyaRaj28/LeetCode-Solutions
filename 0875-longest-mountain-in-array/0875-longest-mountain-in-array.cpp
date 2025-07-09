class Solution {
public:
    int longestMountain(vector<int>& arr) 
    {
        // expected - two ptr approach 

        int i=1; 
        int n = arr.size(); 
        int ans = 0; 
        while(i<n-1)
        {
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
            {
            int cnt = 0; 
            int j = i; 

            while(j>0 && arr[j] > arr[j-1])
            {
                j--; 
                cnt++; 
            }

            while(i<n-1 && arr[i] > arr[i+1])
            {
                i++; 
                cnt++; 
            }

            ans = max(ans, cnt); 
            }
            else
            {
                i++; 
            }
        }

        if(ans > 0) return ans+1; 
        return ans; 
        
    }
};