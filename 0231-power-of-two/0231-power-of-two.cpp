class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        // if( (n & (n-1)) == 0) return true; 
        // else return false;   

        return n>0 && (n & (n-1)) == 0;       
    }
};