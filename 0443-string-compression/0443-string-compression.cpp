class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int n = chars.size(); 

        int i=0, k=0;
        
        while(i<n)
        {
            int j = i+1;
            while(j<n && chars[j] == chars[i]) j++; 
            int len = j-i;

            chars[k] = chars[i]; 
            k += 1;

            if(len > 1)
            {
                //only then append 
                string s = to_string(len);

                for(char c : s) chars[k++] = c;
                
            }
            // j += 1;
            i = j;

        }
        return k;
        
         
        
    }
};