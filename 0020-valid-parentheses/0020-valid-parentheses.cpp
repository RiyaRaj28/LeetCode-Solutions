class Solution {
public:
    bool isValid(string s) 
    {
        stack<char>st;
        int n = s.length(); 

        int i=0; 
        while(i<n)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]); 
            }
            else 
            {
                if(st.empty()) return false;

                if(s[i] == ')')
                {
                    char b = st.top(); 
                    if(b == '(') st.pop(); 
                    else return false;
                }

                if(s[i] == '}')
                {
                    char b = st.top(); 
                    if(b == '{') st.pop(); 
                    else return false;
                }

                if(s[i] == ']')
                {
                    char b = st.top(); 
                    if(b == '[') st.pop(); 
                    else return false;
                }
                 
            }
            i++;
        }

        if(st.empty()) return true;
        return false; 
        
    }
};