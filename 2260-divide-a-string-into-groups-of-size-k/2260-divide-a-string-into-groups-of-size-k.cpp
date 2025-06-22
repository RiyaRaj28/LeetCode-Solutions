class Solution {
public:
    vector<string> divideString(string s, int k, char fill) 
    {
        int n = s.length(); 

        int toadd = (k - (n%k)) % k; 

        for(int i=0; i<toadd; i++)
        {
            s += fill;
        }

        vector<string> vec; 

        int i=0; 
        while(i<n)
        {
            string temp = ""; 
            int j = i; 
            for(j=i; j<i+k; j++)
            {
                temp += s[j]; 
            }

            vec.push_back(temp);
            i = j; 
        }

        return vec; 
        
    }
};