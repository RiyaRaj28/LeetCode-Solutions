class Solution {
public:
    string minWindow(string s, string t) 
    {
    //    int slen = s.length();
    //    int tlen = t.length(); 
    //    int minlen = INT_MAX;
    //    int sind = 0; 

    //    for(int i=0; i<slen; i++)
    //    {
    //        vector<int>hash(256); 
    //        int cnt = 0; 
    //        for(int i=0; i<tlen; i++) hash[t[i]]++;

    //        for(int j=i; j<slen; j++)
    //        {
    //            if(hash[s[j]] > 0) cnt += 1; 
    //            hash[s[j]]--;

    //            if(cnt == tlen)
    //            {
    //                 int len = j-i+1; 
    //                 if(len<minlen)
    //                 {
    //                     sind = i; 
    //                     minlen = len; 
    //                     break; 
    //                 }
    //            }
    //        }
    //    }


    //    return minlen == INT_MAX ? "" : s.substr(sind, minlen); 

       int slen = s.length();
       int tlen = t.length(); 
       int minlen = INT_MAX;
       int sind = 0; 
       int l = 0, r = 0; 

        vector<int>hash(256, 0); 
        int cnt = 0; 
        for(int i=0; i<tlen; i++) hash[t[i]]++;

       while(r<slen)
       {
           if(hash[s[r]]>0) cnt++; 
           hash[s[r]]--;

           while(cnt == tlen)
           {
              if(r-l+1 < minlen)
              {
                 minlen = r-l+1; 
                 sind = l; 
              }
                hash[s[l]]++;  // Restore the left character
                if (hash[s[l]] > 0) cnt--;  // Reduce match count if necessary
                l++;  // Move left pointer
               
           }
            
           r += 1;
       }

       return minlen == INT_MAX ? "" : s.substr(sind, minlen); 
    }
};