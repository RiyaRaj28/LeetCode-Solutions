class Solution {

    // bool checkValidParenthesis(string s, int i, int count)
    // {
        
    //     if(count<0) return false;
    //     if(i == s.size()){  //size of string is never reduced 
    //         return (count == 0); 
    //     }

    //     if(s[i] == '(') {
    //         return checkValidParenthesis(s, i+1, count+1);
    //     }
    //     else if(s[i] == ')') {
    //         return checkValidParenthesis(s, i+1, count-1);
    //     }
    //     else {
    //         return (checkValidParenthesis(s, i+1, count+1) || checkValidParenthesis(s, i+1, count-1) || 
    //                  checkValidParenthesis(s, i+1, count));
    //     }


    
public:
    bool checkValidString(string s) {
        //app1 : recursively 
        // int index = 0, count = 0; 

        // return checkValidParenthesis(s, index, count); 

        //greedy approach 
        int min = 0, max = 0; 

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

        return (min==0); 
    }
};