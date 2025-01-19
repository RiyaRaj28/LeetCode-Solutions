class Solution {
public:
    // bool check(int ind, string s, int cnt)
    // {
    //     if(cnt < 0) return false; 
    //     if(ind == s.size()) return cnt == 0; 
    //     if(s[ind] == '(') return check(ind+1, s, cnt+1);
    //     else if(s[ind] == ')') return check(ind+1, s, cnt-1);
    //     else 
    //     {
    //         bool left = check(ind+1, s, cnt+1);
    //         bool right = check(ind+1, s, cnt-1);
    //         bool empty = check(ind+1, s, cnt);
    //         return left | right | empty;
    //     }
    // }

    // bool checkValidString(string s) 
    // {
    //     return check(0, s, 0);
    // }

    bool checkValidString(string s) 
    {
        int min=0, max=0; 
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(')
            {
                min += 1; 
                max += 1; 
            }
            else if(s[i] == ')')
            {
                min -= 1; 
                max -= 1; 
            }
            else 
            {
                min -= 1; 
                max += 1; 
            }

            if(min<0) min = 0; 
            if(max<0) return false; 
        }
        return min == 0; 
    }
};