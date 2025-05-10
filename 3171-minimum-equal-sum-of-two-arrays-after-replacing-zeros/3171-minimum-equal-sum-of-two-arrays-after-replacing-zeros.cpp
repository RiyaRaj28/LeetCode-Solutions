class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) 
    {
        long long s1=0, s2=0; 
        int n1 = nums1.size(); 
        int n2 = nums2.size();
        int z1 = 0, z2 = 0; 


        for(int i=0; i<n1; i++) 
        {
            s1 += nums1[i]; 
            if(nums1[i] == 0) z1++; 
        }

        for(int i=0; i<n2; i++) 
        {
            s2 += nums2[i]; 
            if(nums2[i] == 0) z2++; 
        } 

        cout << s1 << endl; 
        cout << s2 << endl; 
        int maxsum = max(s1, s2); 

        if(z1 > 0 && z2 > 0)
        {
            // if(s1 > s2) return s1 + z1;
            // else if(s2>s1) return s2 + z2; 
            // else return max(s1+z1, s2+z2); 
            return max(s1+z1, s2+z2); 
        }
        else if(z1 == 0 && z2 == 0)
        {
            return s1==s2 ? s1 : -1;
        }
        else
        {
            if(z2==0)
            {
                //relace all 0s in nums1 with 1
                s1 = s1 + z1;
                if(s1>s2) return -1;
                else if(s1<s2) return s2; 
                else if(s1==s2) return s2;
            }
            if(z1==0)
            {
                //relace all 0s in nums1 with 1
                s2 = s2 + z2;
                if(s2>s1) return -1;
                else if(s2<s1) return s1; 
                else if(s1==s2) return s2;
            }
        }      
        return -1; 
    }
};