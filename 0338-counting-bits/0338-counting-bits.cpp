class Solution {
public:
    int cntbits(int n)
    {
        int cnt = 0; 

        while(n>0)
        {
            if(n%2 != 0)
            {
                cnt += 1; 
                
            }
            n = n/2; 
        }

        return cnt; 
    }

    int briankerghinan(int n)
    {
        int cnt = 0; 
        while(n)
        {
            n = n&(n-1); 
            cnt++; 
        }

        return cnt; 
    }

    vector<int> countBits(int n) 
    {
        vector<int>ans(n+1); 

        for(int i=0; i<=n; i++)
        {
            // ans[i] = cntbits(i); 
            ans[i] = briankerghinan(i);
        }

        return ans; 










        
    }
};