class Solution {
public:

    // vector<int>NLL(vector<int>&arr)
    // {
    //     int n = arr.size();
    //     vector<int>nll(n);
    //     stack<int>st; 

    //     for(int i=0; i<n; i++)
    //     {
    //         if(st.empty())  
    //     }
    // }

    int trap(vector<int>& height) 
    {
        int n = height.size();
        int left = 0, right = n-1; 

        int maxleft = 0, maxright = 0, sum = 0; 
        while(left <= right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] > maxleft) maxleft = height[left];
                else sum += maxleft - height[left];

                left++; 
            }
            else
            {
                if(height[right] > maxright) maxright = height[right];
                else sum += maxright - height[right];

                right--; 
            }
        }
        return sum; 
    }
};