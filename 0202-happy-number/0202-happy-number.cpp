class Solution {
public:

    int sq(int n)
    {
        int ans = 0; 

        while(n>0)
        {
            int dig = n%10; 
            ans += dig*dig; 

            n/=10; 
        }

        return ans; 
    }

    // bool isHappy(int n) 
    // {
    //     set<int>st; 
        
    //     int num = n;

    //     while(true)
    //     {
    //         int sqdig = sq(num);
    //         if(sqdig == 1) return true; 

    //         if(st.find(sqdig) != st.end())
    //         {
    //             return false;
    //         }
    //         else 
    //         {
    //             num = sqdig;
    //             st.insert(sqdig); 
    //         }
    //     }

    //     return false;

        
    // }

    bool isHappy(int n) 
    {
        int slow = n; 
        int fast = n; 

        do
        {
            slow = sq(slow);
            fast = sq(sq(fast)); 
        }while(slow != fast);

        return slow==1;
    }













};