class Solution {
public:
    bool canChange(string s1, string s2) 
    {
        int i = 0, j = 0; 
        int n1 = s1.length(), n2 = s2.length(); 

        while(i < n1 || j < n2)
        {
            while(s1[i] == '_' && i<n1)  {i++;}
            while(s2[j] == '_' && j<n2)  {j++;}

            if(i == n1 || j == n2)
            {
                return i == n1 && j == n2; 
            } 

            if(s1[i] != s2[j]) return false; 

            if(s1[i] == 'L' && i<j) return false; 
            if(s1[i] == 'R' && i>j) return false; 

            // if((s1[i] == 'L' && s2[j] == 'R') 
            //    || s1[i] == 'R' && s2[j] == 'L')
            //    {
            //     return false; 
            //    }

            // if(s1[i] == 'L' && s2[j] == 'L') 
            // {
            //     if(j>i) return false; 
            //     // else 
            //     // {
            //     //     i++; 
            //     //     j++; 
            //     // }
            // }
            
            
            // if(s1[i] == 'R' && s2[j] == 'R') 
            // {
            //     if(i>j) return false; 
            //     // else 
            //     // {
            //     //     i++; 
            //     //     j++; 
            //     // }
            // }   
            // if(s1[i] == ' ') i++; 
            // if(s2[j] == ' ') j++;   
   

            i++; 
            j++; 
        }
        
       
        return true; 
        
    }
};