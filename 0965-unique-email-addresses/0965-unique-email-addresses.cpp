class Solution {
public:
    int numUniqueEmails(vector<string>& emails) 
    {
        // if we add periods in the local name then the  mail would be sent forward without the period 
        // if we add a + then all chars after it will be ignored in local nm 

        // return the number of different addresses received 
        // do the operations then put them in a set 
        // return size of the set 
        // how to do operation 

        // if it is a '.' before '@' then simply ignore it continue 
        // if it is a '+' before a '@' then ignore till '@' 

        // we need to know if '@' appeared or not 
        set<string>st; 

        int n = emails.size(); 

        for(int i=0; i<n; i++)
        {
            string s = emails[i]; 
            int len = s.length(); 

            string revstr = ""; 

            for(int i=len-1; i>=0; i--)
            {
                char c = s[i]; 
                if(c == '@') break; 
                revstr += c; 
            }

            reverse(revstr.begin(), revstr.end()); 

            string str = ""; 
            for(int i=0; i<len; i++)
            {
                char c = s[i]; 
                
                if(c == '@') break; 
                if(c == '.') continue; 
                if(c == '+') break; 

                str += c; 
            }

            string ans = ""; 
            ans = str + '@' + revstr; 

            st.insert(ans);
        }

        return st.size(); 
        
    }
};