class Solution {
public:
    bool hasSpecialSubstring(string s, int k) 
    {
        int n = s.length(); 
        for(int i=0; i<n-k+1; i++)
        {
            
        unordered_set<char>st; 
        for(int j=i; j<i+k; j++) st.insert(s[j]); 

        if(st.size() == 1)
        {
            if(i == 0 && s[i+k-1] != s[i+k]) return true; 
            else if(i>0 && s[i-1] != s[i] && s[i+k-1]!=s[i+k]) return true; 
        }
        
        }
        return n==1 ? true : false; 

    }
};