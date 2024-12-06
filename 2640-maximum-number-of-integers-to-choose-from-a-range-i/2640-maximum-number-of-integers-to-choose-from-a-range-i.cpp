class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) 
    {
        int sum = 0;
        int count = 0;  

        set<int>st; 
        for(int num : banned)
        {
            st.insert(num);
        }

        for(int i=1; i<=n; i++)
        {
            if(st.find(i) == st.end())
            {
                if(sum + i <= maxSum)
                {
                    sum += i; 
                    count++; 
                }
                else break; 
            }
        }

        return count; 
        
    }
};