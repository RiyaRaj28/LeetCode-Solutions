class Solution {
public:
    bool areAlmostEqual(string s1, string s2) 
    {
        int diff = 0; 
        if(s1 == s2) return true; 
        int n1 = s1.length(), n2 = s2.length(); 

        int i1 = 0, i2 = 0; 
        int ind1 = -1, ind2 = -1; 
        vector<int>hash(n1, 1); 

        while(i1<n1 && i2<n2)
        {
            if(s1[i1] == s2[i2])
            {
                i1++, i2++; 
            }
            else if(s1[i1] != s2[i2])
            {
                //  hash[i1] = 0; 
                diff += 1; 
                if(diff>2) return false; 

                if(ind1 == -1) ind1 = i1; 
                else ind2 = i1; 
                i1++, i2++;
               
            }
            // if(diff>2) return false; 
        }


        // if(diff == 2)
        // {
        //     for(int i=0; i<n1; i++)
        //     {
        //         if(hash[i] == 0)
        //         {
        //             if(ind1 == -1) ind1 = i; 
        //             else ind2 = i; 
        //         }
        //     }
        // }

        if(diff == 2)
            if(s1[ind1] == s2[ind2] && s1[ind2] == s2[ind1]) return true; 
        // swap(s1[ind1], s2[ind2]); 
        return false;
    }
};