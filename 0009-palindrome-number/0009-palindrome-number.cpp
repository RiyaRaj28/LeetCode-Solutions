class Solution {
public:
    bool isPalindrome(int x) 
    {
        long long org = x; 
        long long num = 0; 
        while(x > 0)
        {
            long long r = x % 10; 
            num = num * 10 + r; 
            x = x/10; 
        }

        if(org == num) return true; 
        return false; 
        
    }
};