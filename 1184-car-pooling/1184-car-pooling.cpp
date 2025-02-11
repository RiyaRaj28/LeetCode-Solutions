class Solution {
public:

    static const bool comp(vector<int>&trips1, vector<int>&trips2)
    {
        return trips1[1] < trips2[1]; 
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        //  EASY SOLUTION
        // map<int, int>mpp; 
        // int sum = 0; 

        // for(int i=0; i<trips.size(); i++)
        // {
        //     int person = trips[i][0];
        //     int pick = trips[i][1]; 
        //     int drop = trips[i][2]; 

        //     if(mpp.find(pick) == mpp.end()) mpp[pick] = person; 
        //     else mpp[pick] += person; 

        //     if(mpp.find(drop) == mpp.end()) mpp[drop] = -person; 
        //     else mpp[drop] -= person; 
        // }
        // for(auto it : mpp)
        // {
        //     sum += (it.second); 

        //     if(sum > capacity) return false;
        // }
        // return true; 

        // STANDARD SOLUTION

        sort(trips.begin(), trips.end(), comp); 

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; 

        int total_pass = 0;

        for(int i=0; i<trips.size(); i++)
        {
            int currpass = trips[i][0]; 
            int st = trips[i][1]; 
            int end = trips[i][2]; 

            while(!pq.empty() && st >= pq.top().first)
            {
                total_pass -= pq.top().second; 
                pq.pop();
            }

            total_pass += currpass; 
            if(total_pass > capacity) return false; 

            pq.push({end, currpass}); 
        } 

        return true; 



















    }
};