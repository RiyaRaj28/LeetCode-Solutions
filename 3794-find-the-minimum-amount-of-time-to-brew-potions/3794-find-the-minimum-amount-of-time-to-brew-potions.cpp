typedef long long ll; 
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) 
    {
        ll n = mana.size(); 
        ll m = skill.size(); 

        vector<ll>prev(m); 
        ll t = 0; 

        for(int i=0; i<m; i++)
        {
            prev[i] = t + mana[0] * skill[i]; 
            t = prev[i]; 
        }

        vector<ll>temp(m); 

        for(int i=1; i<n; i++)
        {
            int man = mana[i]; 
            temp[m-1] = prev[m-1] + man*skill[m-1]; 

            for(int i=m-2; i>=0; i--)
            {
                temp[i] = temp[i+1] - man*skill[i+1]; 
            }

            ll maxdiff = 0; 

            for(int i=0; i<m; i++)
            {
                ll previous = prev[i] + (ll)man*skill[i]; 
                ll minposs = temp[i]; 

                if(previous > minposs) maxdiff = max(maxdiff, previous - minposs); 
            }

            if(maxdiff != 0)
            {
                temp[m-1] += maxdiff; 
                for(int i=m-2; i>=0; i--)
                {
                    temp[i] = temp[i+1] - (ll)man*skill[i+1]; 
                }
            }

            prev = temp; 
        }
        return prev[m-1]; 
    }
};