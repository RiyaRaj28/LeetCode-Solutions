class Solution {
public:

    int countSetBits(int num)
    {
        int count = 0; 
        while(num != 0)
        {
            num = (num & (num-1));
            count++;
        }

        return count;
    }

    int minBitFlips(int start, int goal) 
    {
        int num = start ^ goal; 
        return countSetBits(num); 
        
    }
};