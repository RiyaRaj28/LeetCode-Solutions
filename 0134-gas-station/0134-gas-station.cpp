class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        // int n = gas.size(); 
        // int startidx = -1; 

        // for(int i=0; i<n; i++)
        // {
        //     int gast = 0;
        //     bool isposs = true;  
        //     for(int j=0; j<n; j++)
        //     {
        //         int idx = (i+j)%n; 
        //         gast += gas[idx];

        //         if(gast < cost[idx])
        //         {
        //             isposs = false;
        //             break;
        //         }
        //         gast -= cost[idx]; 
        //     }
        //     if(isposs) 
        //     {
        //         startidx = i;
        //         break;
        //     }
        // }

        // return startidx; 

        int n = gas.size(); 
        int currgas = 0; 
        int stidx = 0; 
        for(int i=0; i<n; i++)
        {
            currgas = currgas + gas[i] - cost[i]; 

            if(currgas < 0)
            {
                stidx = i+1; 
                currgas = 0;
            }
        }

        currgas = 0; 

        for(int i=0; i<n; i++)
        {
            int j = (i+stidx)%n; 
            currgas += gas[j] - cost[j]; 

            if(currgas < 0)
            {
                return -1;
            }
        }

        return stidx; 
    }
};


























