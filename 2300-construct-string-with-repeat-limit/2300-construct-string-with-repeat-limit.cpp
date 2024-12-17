class Solution {
public:
    // string repeatLimitedString(string s, int repeatLimit) 
    // {
    //     int hash[26] = {0}; 

    //     for(char c : s)
    //     {
    //         hash[c - 'a']++; 
    //     }

    //     //start traversing from end of array and filling 
    //     string temp = "";
    //     int i = 25;
    //     while(i >= 0)
    //     {
    //         // while(i>=0 && hash[i] == 0) i--; 
    //         if(hash[i] == 0)
    //         {
    //             i--;
    //             continue; 
    //         }

    //         char c = i + 'a'; 
    //         int freq = hash[i]; 
    //         // int count = 0; 
    //         int limit = min(freq, repeatLimit);

    //         for(int j=0; j<limit; j++)
    //         {
    //             temp += c;
    //             hash[i]--; 
    //         }

    //         if(hash[i]>0)
    //         {
    //             int j = i-1; 
    //             while(j>=0 && hash[j] == 0) j--; 
    //             if(j < 0) break; 

    //             char c = j + 'a';
    //             temp += c; 
    //             hash[j]--; 
    //         }
    //     }

    //     return temp; 

    // }

    string repeatLimitedString(string s, int repeatLimit) 
    {
        int hash[26] = {0}; 

        for(char c : s)
        {
            hash[c - 'a']++; 
        }

        //start traversing from end of array and filling 
        string temp = "";
        // int i = 25;
       
        priority_queue<char>pq; 
        for(int i = 0; i<26; i++)
        {
            if( hash[i] != 0) pq.push(i + 'a'); 
        }
        // for(char c : pq) cout << c; 

        //pop top element from pq and put in the heap 
        while(!pq.empty())
        {
        char c = pq.top();
        pq.pop(); 
        int freq = hash[c - 'a'];

        int limit = min(freq, repeatLimit);
        for(int j=0; j<limit; j++)
        {
            temp += c; 
            hash[c - 'a']--; 
        }

        //if still value of hash is greter 
        if(hash[c - 'a'] > 0 && !pq.empty())
        {
            char nextchar = pq.top(); 
            pq.pop(); 
            temp += nextchar; 
            hash[nextchar - 'a']--; 

            if(hash[nextchar - 'a'] > 0) pq.push(nextchar);
            pq.push(c);
        }

        

        }


        return temp; 

    }
};