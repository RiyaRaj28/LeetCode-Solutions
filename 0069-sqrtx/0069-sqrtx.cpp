class Solution {
public:
    int mySqrt(int x) 
    {
        if(x == 0) return 0; 
        if(x == 1) return 1; 

        int s = 1, e = x; 
        while(s<=e)
        {
            int mid = s + (e-s)/2; 
            long mid_sq = (long)(mid) * mid;

            if(mid_sq == x) return mid; 
            else if(mid_sq > x) e = mid-1; 
            else s = mid+1;   
        }

        // return static_cast<int>(std::round(end)); 
        return e;
        
    }
};