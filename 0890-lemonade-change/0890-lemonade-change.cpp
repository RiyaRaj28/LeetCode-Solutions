class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int i = 0; 
        int n = bills.size();
        int fives = 0, tens = 0, twnties = 0; 
        for(int i=0; i<n; i++)
        {
            if(bills[i] == 5) fives++;

            if(bills[i] == 10) 
            {
                if(fives > 0) 
                {
                    fives--;
                }
                else return false; 

                tens++; 
            }

            if(bills[i] == 20)
            {
                if(tens >= 1 && fives>= 1)
                {
                    tens -= 1; 
                    fives -= 1;
                }
                else if(fives>=3)
                {
                    fives -= 3;
                }
                else return false; 
                twnties++; 
            }
        }

        return true; 


        
    }
};