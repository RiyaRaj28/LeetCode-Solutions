class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int>st; 
        int n = asteroids.size();
        int i = 0; 

        for(int i=0; i<n; i++)
        {
            //think about yourself only riya 
            // if(st.empty()) st.push(asteroids[i]);
            // else
            // {
            //     if(asteroids[i] < 0 && !st.empty()) 
            // {
            //     if(st.top() <= abs(asteroids[i])) st.pop();
            //     // else i++;
            // }
            // else(st.push(asteroids[i]));
            // }

            //collision condition 
            while(!st.empty() && asteroids[i]<0 && st.top()>0)
            {
                int sum = st.top() + asteroids[i];
                if(sum < 0) st.pop();
                else if(sum > 0) asteroids[i] = 0;
                else
                {
                    st.pop();
                    asteroids[i] = 0;
                }
                
                // else asteroids[i] = 0;
                // else if(sum == 0)
                // {
                //     st.pop();

                // }

            }
            if(asteroids[i] != 0) st.push(asteroids[i]);

        }
        vector<int>ans; 
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans; 
        
    }
};