class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int last_a = -1, last_b = -1, last_c = -1, ans = 0; 

        int n = s.length(); 
        for(int i=0; i<n; i++)
        {
            if(s[i] == 'a') last_a = i; 
            if(s[i] == 'b') last_b = i; 
            if(s[i] == 'c') last_c = i; 

            if(last_a != -1 && last_b != -1 && last_c != -1)
            {
                ans += min(last_a, min(last_c, last_b)) + 1; 
            }
        }
        return ans; 
    }
};