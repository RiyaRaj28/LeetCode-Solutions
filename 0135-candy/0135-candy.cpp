class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1,candy = n;
        while(i<n)
        {
            //new peak efor new mountain

            if(ratings[i] == ratings[i-1])
            {
                i++; 
                continue; 
            }
            int peak = 0;
            while(ratings[i] > ratings[i-1])
            {
                i++; 
                peak++; 
                candy += peak; 

                if(i==n) 
                    return candy; 
            }

            int dip = 0; 
            while(i<n && ratings[i] < ratings[i-1])
            {
                i++; 
                dip++; 
                candy += dip; 
            }
 
            //subtract the shorter path
            candy -= min(peak, dip); 
        }

        return candy; 
    }
};