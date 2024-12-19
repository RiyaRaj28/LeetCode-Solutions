class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int runningsum = 0; 
        int n  = arr.size(); 
        int part = 0; 

        for(int i=0; i<n; i++)
        {
            runningsum += arr[i]; 
            int currsum = (i*(i+1))/2;

            if(runningsum == currsum) part++; 
        }
        
        return part; 
    }
};