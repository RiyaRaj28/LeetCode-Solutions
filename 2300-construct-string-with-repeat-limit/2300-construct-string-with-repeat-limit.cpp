class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) 
    {
        int hash[26] = {0}; 
        for(int i : hash)
        {
            cout << i; 
        }

        for(char c : s)
        {
            hash[c - 'a']++; 
        }

        for(int i : hash)
        {
            cout << i; 
        }

        //start traversing from end of array and filling 
        string temp = "";
        int i = 25;
        while(i >= 0)
        {
            // while(i>=0 && hash[i] == 0) i--; 
            if(hash[i] == 0)
            {
                i--;
                continue; 
            }

            char c = i + 'a'; 
            int freq = hash[i]; 
            // int count = 0; 
            int limit = min(freq, repeatLimit);

            for(int j=0; j<limit; j++)
            {
                temp += c;
                hash[i]--; 
            }

            if(hash[i]>0)
            {
                int j = i-1; 
                while(j>=0 && hash[j] == 0) j--; 
                if(j < 0) break; 

                char c = j + 'a';
                temp += c; 
                hash[j]--; 
            }
        }

        return temp; 

    }
};