class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(); 
        vector<int>ones; 
        for(int i=0; i<n; i++)
        {
            if(boxes[i]=='1') ones.push_back(i); 
        }

        int sum = 0; 
        vector<int>ans(n); 
        for(int i=0; i<n; i++)
        {
            int sum = 0; 
            // if(boxes[i] == '1')
            // {
                for(int j=0; j<ones.size(); j++)
                {
                        sum += abs(i-ones[j]); 
                }
                ans[i] = sum; 
            // }
        }
        return ans; 
    }
};