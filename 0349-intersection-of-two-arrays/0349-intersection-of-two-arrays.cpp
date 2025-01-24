class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>temp; 
        int n1 = nums1.size(); 
        int n2 = nums2.size(); 
        sort(nums1.begin(), nums1.end()); 
        sort(nums2.begin(), nums2.end()); 

        for(int i=0; i<n1; i++)
        {
            for(int j=0; j<n2; j++)
            {
                if(nums1[i] == nums2[j])
                {
                    if(temp.empty() || nums2[j] != temp.back())
                    temp.push_back(nums1[i]);
                    break; 
                }

                if(nums2[j] > nums1[i]) break; 
            }
        }
        return temp; 
    }
};