class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size(); 
        vector<int>temp; 
        sort(nums1.begin(), nums1.end()); 
        sort(nums2.begin(), nums2.end()); 

        // for(int i=0; i<n1; i++)
        // {
        //     for(int j=0; j<n2; j++)
        //     {
        //         if(nums1[i] == nums2[j])
        //         {
        //             if(temp.empty() || nums1[i] != temp.back())
        //             {
        //                 temp.push_back(nums1[i]); 
        //             }
        //         }
        //         else if(nums2[j] > nums1[i])
        //         {
        //             break; 
        //         }
        //     }
        // }

        int i=0, j=0; 
        while(i<n1 & j<n2)
        {
            if(nums1[i] < nums2[j]) i++;
            else if(nums1[i] > nums2[j]) j++; 
            else
            {
                if(temp.empty() || nums1[i] != temp.back())
                {
                    temp.push_back(nums1[i]);
                }
                 i++;
                    j++;
            }
        }

        return temp; 
        
    }
};