class Solution {
public:

    bool check(string s, int ind, int cnt)
    {
        if(cnt < 0) return false; 
        if(ind == s.size()) return cnt == 0; 

        if(s[ind] == '(') return check(s, ind+1, cnt+1);
        if(s[ind] == ')') return check(s, ind+1, cnt-1);
        
        bool left = check(s, ind+1, cnt+1); 
        bool right = check(s, ind+1, cnt-1); 
        bool empty = check(s, ind+1, cnt); 

        return left || right || empty; 
    }
    bool checkValidString(string s) 
    {
        // left -> cnt++
        // right -> cnt--
        // ast -> cnt++ // cnt-- // nothing

        // return check(s, 0, 0); 

        int maxi = 0, mini = 0; 

        int n = s.length(); 

        for(int i=0; i<n; i++)
        {
            if(s[i] == '(')
            {
                maxi += 1; 
                mini += 1;
            }
            else if(s[i] == ')')
            {
                maxi -= 1; 
                mini -= 1; 
            }
            else
            {
                maxi += 1; 
                mini -= 1;
            }

            if(mini < 0) mini = 0; 
            if(maxi < 0) return false;
        }

        return mini == 0; 




        
    }
};