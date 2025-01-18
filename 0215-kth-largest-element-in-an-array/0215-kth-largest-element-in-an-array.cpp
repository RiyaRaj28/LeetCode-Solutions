class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        //have to maintain a min heap of size k, if the size exceeds then we 
        //pop out the elements 

        priority_queue<int, vector<int>, greater<int>>pq; 

        int size = 0; 
        for(int i=0; i<nums.size(); i++)
        {
            pq.push(nums[i]);

            if(pq.size()>k) pq.pop();
        }
        return pq.top();
        
    }
};