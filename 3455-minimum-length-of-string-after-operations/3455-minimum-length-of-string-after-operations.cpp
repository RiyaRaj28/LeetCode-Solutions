class Solution {
public:
    int minimumLength(string s) 
    {
        // int n = s.length();
        // vector<int>deleted(n, 0);
        // int count = 0; 

        // for(int i=0; i<n; i++)
        // {
        //     int l = -1; 
        //     int r = -1; 
        //     if(deleted[i] == 0)
        //     {
        //         //checking on left 
        //         for(int j=i-1; j>=0; j--)
        //         {
        //             if(deleted[j] == 0 && s[j] == s[i])
        //             {
        //                 l = j; 
        //             }
        //         }

        //         for(int j=i+1; j<n; j++)
        //         {
        //             if(deleted[j] == 0 && s[j] == s[i])
        //             {
        //                 r = j; 
        //             }
        //         }
                
        //         if(l != -1 && r != -1)
        //         {
        //             deleted[l] = 1; 
        //             deleted[r] = 1;
        //         }
        //     }
        // }

        // for(int i=0; i<n; i++)
        // {
        //     if(deleted[i] == 0) count++; 
        // }
        
        // // for(int i=0; i<n; i++)
        // // {
        // //     cout << deleted[i] << " ";
        // // }

        // return count; 

                int n = s.length();
        unordered_map<char, int>mpp; 
        int count = 0; 
        
        // for(int i=0; i<n; i++)
        // {
        //     mpp[s[i]]++; 
        // }
        
        // for(auto it = mpp.begin(); it!= mpp.end(); it++)
        // {
        //     if(it->second % 2 == 0) count += 2;
        //     else count += 1; 
        // }
        
        // for(auto it = mpp.begin(); it!= mpp.end(); it++)
        // {
        //     cout << it->first << " -> " << it->second << "\n";
        // }

        vector<int>freq(26, 0); 
        for(int i=0; i<n; i++)
        {
            freq[s[i]-'a']++;
        }

        for(int i=0; i<26; i++)
        {
            if(freq[i] != 0)
            {
                if(freq[i]%2 == 0) count += 2;
                else count += 1;
            }
        }
        return count; 
    }
};