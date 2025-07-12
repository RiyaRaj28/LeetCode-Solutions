class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        int n = hand.size(); 
        priority_queue<int, vector<int>, greater<int>>pq; 
        if(n%groupSize != 0) return false; 

        map<int, int>mpp; 

        for(int i=0; i<n; i++)
        {
            mpp[hand[i]]++;
        }

        for(auto it : mpp)
        {
            pq.push(it.first); 
        }

        while(!pq.empty())
        {
            int smallest = pq.top(); 
            for(int i=smallest; i<smallest+groupSize; i++)
            {
            if(mpp.find(i) == mpp.end()) return false; 

            mpp[i]--;
            if(mpp[i] == 0)
            {
                if(pq.top() != i) return false; 
                pq.pop(); 
            }
            }

        }
        return true; 
    }
};