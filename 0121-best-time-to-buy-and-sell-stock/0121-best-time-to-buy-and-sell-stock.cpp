class Solution {
public:

   // this one question prevented me from getting selected in de shaw 
   // prevented me from going to hyderabad 
   // laid to waste my so much of hard work 
    int maxProfit(vector<int>& prices) 
    {
        // int mini = prices[0]; 
        // int profit = 0; 
        // int n = prices.size();
        // for(int i=1; i<n; i++)
        // {
        //     int cost = prices[i] - mini; 
        //     profit = max(profit, cost); 

        //     mini = min(mini, prices[i]); 
        // }

        // return profit; 





        int prevmin = prices[0]; 
        int profit = 0; 
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i] < prevmin)
            {
                prevmin = prices[i];
            }
            else
            {
                profit = max(profit, prices[i] - prevmin); 
            }
        }
        return profit; 















        
    }
};