class Solution {
public:
    string rle(string &s, int n, int cnt)
    {
        if(cnt == n) return s;

        int len = s.length(); 
        int i = 0, j = 0; 
        int count = 0; 
        string str = ""; 
        while(j<len)
        {
            if(s[j] != s[i])
            {
                str += to_string(count); 
                str += s[i]; 
                i = j; 
                count = 0; 
            }
            count += 1; 
            j += 1; 
        }

    if (count > 0) {
        str += to_string(count);
        str += s[i];
    }

        return rle(str, n, cnt+1); 
    }

    string countAndSay(int n) {
        string s = "1";

        return rle(s, n, 1); 
    }
};