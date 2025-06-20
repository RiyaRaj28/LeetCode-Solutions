class Solution {
public:
    const int MOD = 1e9 + 7; 
    long long fac(int n) 
    {
        long long ans = 1; 
        for(int i=1; i<=n; i++)
        {
            ans = (ans * i)%MOD; 
        }

        return ans; 
    }

    int countPermutations(vector<int>& complexity) 
    {
        int n = complexity.size(); 
        int mini = complexity[0]; 

        for(int i=1; i<n; i++)
        {
            if(complexity[i] <= mini) return 0; 
        }

        return fac(n-1)%MOD; 
        
    }
};