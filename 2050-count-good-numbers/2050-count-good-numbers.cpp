class Solution {
public:
    const long long MOD = 1e9 + 7; 

    int power(long long n, long long x)
    {
        long long prod = 1; 
        n = n%MOD; 

        while(x>0)
        {
            if(x%2 != 0)
            {
                prod = (prod*n)%MOD;
            }

            n = (n*n)%MOD;
            x /= 2; 
        }
        return prod; 
    }

    int countGoodNumbers(long long n) {

        if(n%2 == 0) return (power(5, n/2)%MOD * power(4, n/2)%MOD) % MOD; 
        else return (power(5, (n/2)+1)%MOD * power(4, n/2)%MOD) % MOD;
        
    }
};