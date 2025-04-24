class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) 
    {
        int n = values.size(); 
        vector<int>vis(n, 0); 
        long long i = 0, score = 0; 

        while(i<n)
            {
                if(vis[i] == 1) break; 
                vis[i] = 1; 
                
                string ins = instructions[i]; 

                if(ins == "add")
                {
                    score += (long long)values[i];  
                    i += 1; 
                }
                else if(ins == "jump")
                {
                    i += values[i]; 
                    if(i<0) break; 
                }
            }
        return score; 
    }
};