class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        map<int, int>mpp; 
        int sum = 0; 

        for(int i=0; i<trips.size(); i++)
        {
            int person = trips[i][0];
            int pick = trips[i][1]; 
            int drop = trips[i][2]; 

            if(mpp.find(pick) == mpp.end()) mpp[pick] = person; 
            else mpp[pick] += person; 

            if(mpp.find(drop) == mpp.end()) mpp[drop] = -person; 
            else mpp[drop] -= person; 
        }

        for(auto it : mpp)
        {
            sum += (it.second); 

            if(sum > capacity) return false;
        }

        return true; 

        
    }
};