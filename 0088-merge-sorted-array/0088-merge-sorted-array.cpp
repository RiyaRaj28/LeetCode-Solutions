class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int l = m-1, r = n-1, ptr = m+n-1; 

        while(r >= 0 ) //check
        {
            if(l>=0 && nums1[l] >= nums2[r]) 
            {
                nums1[ptr--] = nums1[l--]; 
            }
            else 
            {
                nums1[ptr--] =nums2[r--]; 
            }
        }

        for(int i=0; i<m+n; i++)
        {
            cout << nums1[i] << " "; 
        }
        
        // return nums1;
    }
};