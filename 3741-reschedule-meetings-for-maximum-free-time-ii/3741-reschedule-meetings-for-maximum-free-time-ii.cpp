class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime)
    {
        int n = startTime.size(); 

        vector<int>gap(1, startTime[0]); 
        for(int i=1; i<n; i++) gap.push_back(startTime[i]-endTime[i-1]); 
        gap.push_back(eventTime - endTime[n-1]); 

        vector<int>largestRight(gap.size(), 0); 
        for(int i=gap.size()-2; i>=0; i--) largestRight[i] = max(largestRight[i+1], gap[i+1]);
        int largestLeft = 0; 
        
        int ans = 0;  
        for(int i=1; i<gap.size(); i++)
        {
            int currint = endTime[i-1] - startTime[i-1]; 

            //if we can shift it to the lar left or lar right, then we add the current inter also
            if(currint <= max(largestLeft, largestRight[i])) ans = max(ans, gap[i-1] + gap[i] + currint); 

            // else we will shift the curr interval to one side, and it is not added 
            ans = max(ans, gap[i]+gap[i-1]); 
            largestLeft = max(largestLeft, gap[i-1]); 
        }

        return ans; 



        
    }
};        
