class Solution {
public:
    double myPow(double x, int n) {

        double ans = 1.0;
        long long ctr = n; 

        if(n<0)
        {
            x = 1/x;
            ctr = -ctr;
        } 

        while(ctr>0)
        {
            if(ctr%2==1) ans = ans*x;
            x = x*x;
            ctr = ctr/2;
        }

        return ans; 
        
    }
};