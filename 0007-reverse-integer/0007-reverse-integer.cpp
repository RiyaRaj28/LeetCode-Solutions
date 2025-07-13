class Solution {
public:
    int reverse(int x) 
    {
        // bool neg = false; 
        // if(x < 0)
        // {
        //     neg = true; 
        //     x = -x;
        // }

        // long long prev_rev_num = 0, rev_num = 0;
        // while(x>0)
        // {
        //     int dig = x%10; 

        //     rev_num = rev_num*10 + dig; 

        //     if((rev_num-dig)/10 != prev_rev_num) return 0; 

        //     prev_rev_num = rev_num; 
        //     x = x/10;
        // }

        // if(neg)
        // {
        //     return -rev_num; 
        // }

        int rev_num = 0; 

        while(x!=0)
        {
            int dig = x%10; 

            if((rev_num > INT_MAX/10) || (rev_num < INT_MIN/10)) return 0;

            rev_num = rev_num*10 + dig; 

            x = x/10;
        }

        return rev_num;


        
    }
};