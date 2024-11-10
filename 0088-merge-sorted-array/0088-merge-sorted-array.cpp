class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = 0; 
        if(m>0) l = m - 1; 
        int r = 0; 

        while(l>=0 && r<n)
        {
            if(nums1[l] > nums2[r]) 
            {
                swap(nums1[l], nums2[r]);
                cout << nums1[1] << " " << nums2[r] << " ";
                l--; r++;
            }
            else
                break; 
        }

        sort(nums1.begin(), nums1.begin()+m);
        // for(int i=0; i<m; i++) cout<<nums1[i] << " ";

        sort(nums2.begin(), nums2.begin()+n);
        // for(int i=0; i<n; i++) cout<<nums2[i] << " ";

        int j = 0; 
        for(int i=m; i<m+n; i++)
        {
            nums1[i] = nums2[j];
            j++; 
        }
        // for(int i=0; i<n+m; i++) cout<<nums1[i] << " ";
    }
};