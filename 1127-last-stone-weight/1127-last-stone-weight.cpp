class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        int n = stones.size(); 
        priority_queue<int>pq; 
        for(int i=0; i<n; i++) pq.push(stones[i]);

        while(!pq.empty())
        {
            int x = pq.top(); 
            pq.pop(); 

            if(pq.empty()) return x;
            
            int y = pq.top(); 
            pq.pop(); 

            if(x==y) continue;
            if(x!=y) pq.push(x-y);
        }
        return 0;
        
    }
};