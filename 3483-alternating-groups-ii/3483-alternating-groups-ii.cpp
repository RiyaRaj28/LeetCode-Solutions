class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& arr, int k) 
    {
        int i = 0, j = 0; 
        int n = arr.size(); 
        int cnt = 0; 
        int len = 1; 

        for(int i=1; i<2*n; i++)
        {
            int curr = arr[i%n];
            int prev = arr[(i-1)%n];

            if(curr != prev)
            {
                len += 1; 
            }
            else len = 1; 

            if(len >= k) cnt += 1; 

            if(i >= n+k-2) break;
        }

        return cnt; 
        
    }
};