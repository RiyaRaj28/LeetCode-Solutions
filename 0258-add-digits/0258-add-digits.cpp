class Solution {
public:
    int addDigits(int num) 
    {
        // need to add the digits till one digit is left 

        while(num > 9)
        {
            int sum = 0; 
            int temp = num; 
            while(temp > 0)
            {
                int dig = temp%10; 
                sum += dig; 
                temp /= 10; 
            }
            num = sum; 
        }

        return num; 
        
    }
};