typedef long long ll; 
class Solution {
public:

static bool comp1(pair<pair<int, int>, int>a, pair<pair<int, int>, int>b)
{
    return a.first.first < b.first.first; 
}

vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(); 

        vector<ll>ans(n); 
        vector<pair< pair<ll, ll>, int >>vec; 

        for(int i=0; i<n; i++)  vec.push_back({{nums1[i], i}, nums2[i]}); 
        sort(vec.begin(), vec.end(), comp1);
        priority_queue<int, vector<int>, greater<int>>pq; 
        ll sum = 0; 

        for(int i=0; i<n; i++)
        {
            if(i > 0 && vec[i].first.first == vec[i-1].first.first)
            {
                ll temp = ans[vec[i-1].first.second]; 
                ans[vec[i].first.second] = temp; 
            }else
            {
                ans[vec[i].first.second] = sum; 
            }

            pq.push(vec[i].second); 
            sum += vec[i].second; 

            if(pq.size() > k)
            {
                sum -= pq.top(); 
                pq.pop(); 
            }
        }
        
        return ans; 
        
    }
};