class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        int s = tasks.size(); 
        int time = 0; 
        priority_queue<int>pq; 

        map<char, int>mpp; 
        for(int i=0; i<s; i++)
        {
            mpp[tasks[i]]++;
        }

        for(auto it : mpp)
        {
            pq.push(it.second);
        }        

        while(!pq.empty())
        {
            vector<int>temp; 
            temp.clear();

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

            if(!temp.empty())
            {
                for(int i=0; i<temp.size(); i++)
                {
                    if(temp[i] > 0 ) pq.push(temp[i]); 
                }
            }

            if(!pq.empty())
            {
                time += n+1;
            }
            else
            {
                time += temp.size(); 
            }
        }
        return time; 
    }
};