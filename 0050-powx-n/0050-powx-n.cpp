class Solution {
public:
    double myPow(double x, int n) 
    {
        // if(x == 1 || n == 0) return 1; 

        // //when it is a neg power 



        // double factor = x; 
        // while(n>1)
        // {
        //     x *= factor; 
        //     n--; 
        // }
        // return x; 
        double result = 1.0; 
        long long counter = n;

        if(n < 0)
        {
            x = 1/x;
            counter = -counter; 
        }

        while(counter > 0)
        {
            if(counter % 2 == 1)
            {
                result *= x; 
            }

            x *= x; 
            counter /= 2; 
        }

        return result;
    }
};