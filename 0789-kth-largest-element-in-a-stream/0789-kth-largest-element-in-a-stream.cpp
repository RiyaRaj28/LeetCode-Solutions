class KthLargest {
private: 
    priority_queue<int, vector<int>, greater<int>>pq;
    int k;
public:
    // priority_queue<int, vector<int>, greater<int>>pq;
    KthLargest(int k, vector<int>& nums) 
    {
        this->k = k;
        for(int i=0; i<nums.size(); i++) pq.push(nums[i]);
        while(pq.size()>this->k) pq.pop();
    }
    
    int add(int val) 
    {
        pq.push(val);
        while(pq.size() > k) pq.pop();

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */