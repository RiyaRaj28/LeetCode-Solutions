class Solution {
public:
    int cnt(int num)
    {
        int cnt = 0; 
        while(num>0)
        {
            int d = num%10; 
            cnt += 1; 
            num /= 10; 
        }
        return cnt; 
    }

    bool check(int num, int len)
    {
        int first = 0; 
        int f = len/2; 
        while(f > 0)
        {
            int d = num%10; 
            first += d; 
            num /= 10; 

            f--; 
        }

        int second = 0; 
        int s = len/2; 
        while(s>0)
        {
            int d = num%10; 
            second += d; 
            num /= 10; 

            s--; 
        }

        if(first == second) return true;
        return false;  
    }

    int countSymmetricIntegers(int low, int high) 
    {
        int ans = 0; 
        for(int num = low; num<=high; num++)
        {
            int len = cnt(num); 
            if(len % 2 != 0) continue; 


            if(check(num, len)) ans += 1; 
        }

        return ans; 
    }
};