class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // {
    //     // vector<int>temp; 
    //     // int n1 = nums1.size(); 
    //     // int n2 = nums2.size(); 
    //     // sort(nums1.begin(), nums1.end()); 
    //     // sort(nums2.begin(), nums2.end()); 

    //     // for(int i=0; i<n1; i++)
    //     // {
    //     //     for(int j=0; j<n2; j++)
    //     //     {
    //     //         if(nums1[i] == nums2[j])
    //     //         {
    //     //             if(temp.empty() || nums2[j] != temp.back())
    //     //             temp.push_back(nums1[i]);
    //     //             break; 
    //     //         }

    //     //         if(nums2[j] > nums1[i]) break; 
    //     //     }
    //     // }
    //     // return temp; 








    //     vector<int>temp; 
    //     int n1 = nums1.size(); 
    //     int n2 = nums2.size(); 
    //     sort(nums1.begin(), nums1.end()); 
    //     sort(nums2.begin(), nums2.end()); 

    //     int i = 0, j = 0; 
    //     while(i < n1 && j < n2)
    //     {
    //         if(nums1[i] < nums2[j]) i++; 
    //         else if(nums1[i] > nums2[j]) j++; 
    //         else 
    //         {
    //             if(temp.empty() || temp.back() != nums1[i])
    //             {
    //                 temp.push_back(nums1[i]); 
    //             }
    //             i++; 
    //             j++;
    //         }
    //     }
    //     return temp; 
    // }




    vector<int>temp; 
    int n = nums1.size(); 
    int m = nums2.size(); 

    sort(nums1.begin(), nums1.end()); 
    sort(nums2.begin(), nums2.end()); 

    int i=0, j=0; 
    while(i<n && j<m)
    {
        if(nums1[i] < nums2[j]) i++;
        else if(nums1[i] > nums2[j]) j++;
        else
        {
            //both equal 
            if (temp.empty() || nums1[i] != temp.back()) 
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