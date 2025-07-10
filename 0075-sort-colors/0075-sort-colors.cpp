class Solution {
public:

    // void merge(vector<int>&nums, int low, int mid, int high)
    // {
    //     if(low >= high) return; 
    //     vector<int>temp; 

    //     int left = low, right = mid+1; 
    //     while(left<=mid && right<=high)
    //     {
    //         if(nums[left] <= nums[right])
    //         {
    //             temp.push_back(nums[left]); 
    //             left++; 
    //         }
    //         else
    //         {
    //             temp.push_back(nums[right]);
    //             right++; 
    //         }
    //     }

    //     while(left <= mid)
    //     {
    //         temp.push_back(nums[left]);
    //     }

    //     while(right<=high)
    //     {
    //         temp.push_back(nums[right]); 
    //     }

    //     for(int i=low; i<=high; i++)
    //     {
    //         nums[i] = temp[i-low]; 
    //     }
    // }

    // void mergeSort(vector<int>&nums, int low, int high)
    // {
    //     if(low >= high) return; 
    //     int mid = low + (high-low)/2; 

    //     mergeSort(nums, low, mid); 
    //     mergeSort(nums, mid+1, high); 
    //     merge(nums, low, mid, high); 
    // }

    // void sortColors(vector<int>& nums) 
    // {
    //    int n = nums.size(); 

    //    mergeSort(nums, 0, n-1); 
    // //    return nums; 
    // }





    void sortColors(vector<int>& nums) 
    {
       int n = nums.size(); 
       int mid = 0; 
       int low = 0, high = n-1; 

       while(mid<=high)
       {
            if(nums[mid] == 0)
            {
                swap(nums[mid], nums[low]); 
                mid++;
                low++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }

       }
   
    }
};