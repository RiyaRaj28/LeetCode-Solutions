class Solution {
public:
    int climbStairs(int n) 
    {
        //tabulation approach with space optimisation 

        int n1 = 1; 
        int n2 = 1; 

        for(int i=2; i<=n; i++)
        {
            int curr = n1 + n2; 
            n1 = n2; 
            n2 = curr; 
        }

        return n2; 
    }
};