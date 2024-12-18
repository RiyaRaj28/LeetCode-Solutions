class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        stack<pair<int, int>>st; 
        int n = prices.size();
        if(n == 1) return prices; 
        vector<int>ans(n); 

        st.push({prices[0], 0}); 
        for(int i=1; i<n; i++)
        {
            int next = prices[i]; 

            if(!st.empty())
            {
                while(!st.empty() && next <= st.top().first)
                {
                    ans[st.top().second] = st.top().first - next; 
                    st.pop(); 
                }
                st.push({next, i});
            }
        }

        while(!st.empty())
        {
            ans[st.top().second] = st.top().first;
            st.pop(); 
        }

        return ans; 
    }
};