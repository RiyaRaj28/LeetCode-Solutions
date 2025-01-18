class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int>mpp(26, 0);
        for(int i=0; i<tasks.size(); i++) mpp[tasks[i] - 'A']++;

        priority_queue<int>pq; 
        for(int i=0; i<mpp.size(); i++) if(mpp[i]>0) pq.push(mpp[i]);
        int time = 0; 

        while(!pq.empty())
        {
            vector<int>temp; 
            for(int i=0; i<=n; i++)
            {
                if(!pq.empty())
                {
                int freq = pq.top();
                pq.pop();
                freq--; 
                temp.push_back(freq);

                }
               
            }

            for(int &f : temp) if(f>0) pq.push(f);

            if(pq.empty()) time += temp.size();
            else time += n+1; 
        }
        return time; 
    }
};