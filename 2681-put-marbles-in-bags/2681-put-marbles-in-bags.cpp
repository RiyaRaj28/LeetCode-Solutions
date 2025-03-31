class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        int n = weights.size(); 

        vector<int>pairsum(n-1); 

        for(int i=0; i<n-1; i++)
        {
            pairsum[i] = weights[i] + weights[i+1]; 
        }

        sort(pairsum.begin(), pairsum.end()); 

        long long maxi = 0, mini = 0; 

        for(int i=0; i<k-1; i++)
        {
            mini += pairsum[i]; 
            maxi += pairsum[n-2-i]; 
        }

        return maxi-mini; 
        
    }
};