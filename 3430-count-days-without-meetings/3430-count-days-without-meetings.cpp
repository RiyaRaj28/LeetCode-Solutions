class Solution {
public:

    static bool comp(vector<int>a, vector<int>b)
    {
        return a[0] < b[0]; 
    }

    int countDays(int days, vector<vector<int>>& meetings) 
    {
        sort(meetings.begin(), meetings.end(), comp); 
        int n = meetings.size(); 
        vector<vector<int>>temp; 
        temp.push_back(meetings[0]); 
        for(int i=1; i<n; i++)
        {
            vector<int> prev = temp.back(); 
            vector<int> curr = meetings[i];
            if(curr[0] <= prev[1])
            {
                temp[temp.size()-1][1] = max(prev[1], curr[1]); 
            }
            else
            {
                temp.push_back(curr); 
            }
        }

        // vector<int>hash(days+1, 0); 
        int total = 0; 

        for(int i=0; i<temp.size(); i++)
        {
            int l = temp[i][0]; 
            int r = temp[i][1]; 
            total += r-l+1;  
        }

        // int cnt = 0; 
        // for(int i=1; i<=days; i++)
        // {
        //     if(!hash[i]) cnt++; 
        // }

        return days-total; 
        
    }
};