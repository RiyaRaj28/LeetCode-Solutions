class Solution {
public:
    string removeOccurrences(string s, string part) 
    {
        // we just need to remove all occurences of this string 
        // int ind = 0; 

        // while(ind != s.length() && s.length() >= part.length())
        // {
        //     int ind2 = 0; 
        //     for(int j=ind; j<part.length(); j++)
        //     {
        //         if(s[j] == part[ind2]) 
        //         {
        //             ind2++; 
        //         }
        //         else 
        //         {
        //             break; 
        //         }
        //     }

        //     if(ind2 == part.length())
        //     {
        //         string temp = ""; 

        //         int i = 0; 
        //         while(i < s.length())
        //         {
        //             if(ind <= i < ind+part.length()) continue; 
        //             else temp += s[i];

        //             i++; 
        //         }
        //         s = temp; 
        //         continue; 
        //     }
        //     ind += 1; 
        // }

        // return s;   

        string res = ""; 
        int n = s.length(); 
        int m = part.length(); 

        for(int i=0; i<n; i++)
        {
            res += s[i]; 

            if(res.length() >= part.length())
            {
                if(s[i] == part[m-1])
                {
                    string temp = res.substr(res.length() - m);

                    if(temp == part) res.erase(res.length() - m);  
                }
            }
        }

        return res; 














        }
};