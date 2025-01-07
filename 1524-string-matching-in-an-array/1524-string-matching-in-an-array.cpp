class Solution {
public:

    bool check(string s1, string s2)
    {
        //l2 should be longer than l1
        int l1 = s1.length(); 
        int l2 = s2.length(); 

        if(l1>l2) return false; 

        for(int i=0; i<=l2-l1; i++)
        {
            int j;
            for(j=0; j<l1; j++)
            {
                if(s2[i+j] != s1[j])
                {
                    break; 
                }
            }

            if(j==l1) return true; 
        }

        return false; 
    }

    vector<string> stringMatching(vector<string>& words) 
    {
        set<string>st; 
        int n = words.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j!=i && check(words[i], words[j])) st.insert(words[i]);
            }
        }

        vector<string>ans; 
        for(auto it : st)
        {
            ans.push_back(it);
        }
        return ans;    
    }
};