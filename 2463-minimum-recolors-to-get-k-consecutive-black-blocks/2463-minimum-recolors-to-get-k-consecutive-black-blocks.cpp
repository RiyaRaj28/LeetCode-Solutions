class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        
        map<char, int>mpp; 

        int n = blocks.size(); 
        
        
        for(int i=0; i<k; i++) mpp[blocks[i]]++; 

        int l = 0, r = k-1, cnt = mpp['W']; 
        while(r<n)
        {
            mpp[blocks[l]]--; 
            l++;
            r++; 

            if(r == n) break; 

            mpp[blocks[r]]++;

            if(mpp['W'] < cnt) cnt = mpp['W']; 
        }

        return cnt; 
        
    }
};