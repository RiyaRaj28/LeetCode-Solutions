class Solution {
public:
    string clearDigits(string s) 
    {
        // int ind = 0; 

        // int i=0; 

        // int len = s.length(); 

        // for(auto i=s.begin(); i!=s.end(); i++)
        // {
        //     int ind1 = -1; 
        //     int ind2 = -1; 
        //     //first digit 
        //     if(isdigit(s[*i]))
        //     {
        //         ind1 = *i; 
        //         for(int j=*i; j>=0; j--)
        //         {
        //             if(isalpha(s[j])) 
        //             {
        //                 ind2 = j; 
        //                 break; 
        //             }
        //         }
        //     }

        //     if(ind1 != -1 && ind2 != -1) s.erase(ind1, 1); 
        //     if(ind2 != -1 && ind2 != -1) s.erase(ind2, 1); 
        // }

        // return s; 










        int n = s.length(); 
        stack<char>st; 
        string ans = ""; 
        for(int i=0; i<n; i++)
        {
            if(isalpha(s[i])) st.push(s[i]);            
            else if(isdigit(s[i]))
            {
                if(st.empty())
                {
                    ans += s[i];
                }
                else
                {
                    st.pop();
                }
            }
        }

        while(!st.empty())
        {
            ans += st.top(); 
            st.pop(); 
        }

        reverse(ans.begin(), ans.end());
        
        return ans; 














        
        
    }
};