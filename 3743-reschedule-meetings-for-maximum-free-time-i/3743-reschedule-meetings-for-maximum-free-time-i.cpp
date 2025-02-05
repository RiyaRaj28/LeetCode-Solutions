class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) 
    {
        // int i=0, j=0, r=0, l=0; 

        // int n = startTime.size(); 

        // int maxwin = 0; 
        // int ones = 0;
        
        // for(int i=0; i<n; i++)
        //     {
        //         j = i+k-1; 
        //         int os = startTime[i]; 
        //         int oe = endTime[j];       

        //         if(ones == 0)
        //         {
        //           for(int p=i; p<=j; p++)
        //             {
        //                 if(j<n) ones += endTime[p] - startTime[p]; 
        //             }                    
        //         }
        //         else if(j<n) ones += endTime[j] - startTime[j] - (endTime[i-1] - startTime[i-1]); 

        //         l = i>0 ? endTime[i-1]-1 : -1;
        //         r = j<n-1 ? startTime[j+1] : eventTime; 
    
        //         int temp =  r - l - 1 - ones; 
        //         maxwin = max(maxwin, temp);                     
        //     }
        // return maxwin; 


        int n = startTime.size(); 
        vector<int>gaps(n+1, 0); 

        gaps[0] = startTime[0] - 0; 
        gaps[n] = eventTime - endTime[n-1]; 

        for(int i=1; i<n; i++)
        {
            gaps[i] = startTime[i] - endTime[i-1]; 
        }

        int i=0, j=0; 
        int sum = 0, maxsum = 0; 
        while(j<n+1)
        {
            if(j-i+1 > k+1)
            {
                sum -= gaps[i];
                i++;
            }

            sum += gaps[j];
            maxsum = max(maxsum, sum); 
            j++;
        }

        return maxsum; 




    }
}; 