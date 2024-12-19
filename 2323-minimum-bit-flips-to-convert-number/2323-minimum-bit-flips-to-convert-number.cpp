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
        int cnt = 0; 
        for(int i=0; i<32; i++)
        {
            if(num & (1 << i)) cnt++; 
        }


        // return countSetBits(num); 
        return cnt; 
        
    }
};