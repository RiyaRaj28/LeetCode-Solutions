class Solution {
public:

    bool check(int num, int sum, int ind)
    {
         if(sum == num) return true; 
        if(pow(3, ind) > num) return false; 
       

        bool pick = check(num, sum+pow(3,ind), ind+1); 
        bool nonpick = check(num, sum, ind+1); 

        return pick | nonpick; 
    }

    bool checkPowersOfThree(int n) 
    {
        return check(n, 0, 0); 
        
    }
};