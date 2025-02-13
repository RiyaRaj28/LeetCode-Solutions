typedef long long ll;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        priority_queue<ll, vector<ll>, greater<ll>>pq; 
        int steps = 0; 
        for(int i=0; i<nums.size(); i++) pq.push(nums[i]); 

        while(pq.top() < k)
        {
            ll f = pq.top(); 
            pq.pop(); 

            ll s = pq.top();
            pq.pop(); 

            // pq.push(min(f,s)*2 + max(f,s)); 
            pq.push(f*2 + s);
            steps += 1; 
        }

        return steps; 
        // if(pq.top() >= k) return steps; 
        // else return -1;; 

        
    }
};