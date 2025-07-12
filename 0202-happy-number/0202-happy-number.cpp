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

    bool isHappy(int n) 
    {
        set<int>st; 
        

        // while(st.find(num) != st.end() || st.find(1) != st.end())
        // {
        //     int sqdig = sq(num);

        //     if(sqdig == 1) return true;
        //     else
        //     {
        //         num = 
        //     }

        // }
        int num = n;

        while(true)
        {
            int sqdig = sq(num);
            if(sqdig == 1) return true; 

            if(st.find(sqdig) != st.end())
            {
                return false;
            }
            else 
            {
                num = sqdig;
                st.insert(sqdig); 
            }
        }

        return false;

        
    }
};