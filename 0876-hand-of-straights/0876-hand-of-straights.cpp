class Solution {
public:

// `if(i != pq.top()) return false;`: This is the key part. It's checking if the current number `i` we're processing is the same as the smallest number remaining in our priority queue.

// - Why is this important? Because we're forming groups in ascending order, the next number we remove from `mpp` should always be the smallest number remaining.
// - If `i` is not equal to `pq.top()`, it means there's a smaller number still in the queue that we haven't fully processed yet. This would break the requirement of forming groups with consecutive numbers.

    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        priority_queue<int, vector<int>, greater<int>>pq; 
        int n = hand.size();
        unordered_map<int, int>mpp; 
        if(n%groupSize != 0) return false; 

        for(int i=0; i<n; i++)
        {
            mpp[hand[i]]++;
        }

        for(auto it=mpp.begin(); it!=mpp.end(); it++)
        {
            pq.push(it->first);
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
                    if(i != pq.top()) return false; 
                    pq.pop();
                }
            }
        }

        return true; 
        
    }
};