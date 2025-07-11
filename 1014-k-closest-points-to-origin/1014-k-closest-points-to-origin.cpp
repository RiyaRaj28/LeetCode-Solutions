typedef pair<int, pair<int, int>>pii;
class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<pii>pq; 

        int n = points.size(); 
        for(int i=0; i<n; i++)
        {
            int xs = points[i][0] * points[i][0]; 
            int ys = points[i][1] * points[i][1]; 

            pq.push({xs+ys, {points[i][0], points[i][1]}});

            if(pq.size() > k) pq.pop(); 
        }

        vector<vector<int>>ans; 
        while(!pq.empty())
        {
            int x = pq.top().second.first;
            int y = pq.top().second.second; 
            pq.pop();

            ans.push_back({x,y});

        }

        return ans; 



        
    }
};