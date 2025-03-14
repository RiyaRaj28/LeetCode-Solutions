class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int>mpp; 
        for(int i=0; i<nums.size(); i++) mpp[nums[i]]++;

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; 
        for(auto it=mpp.begin(); it!=mpp.end(); it++)
        {
            pq.push({it->second, it->first});

            if(pq.size()>k) pq.pop();
        }

        vector<int>ans; 
        for(int i=0; i<k; i++) 
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans; 
    }
};