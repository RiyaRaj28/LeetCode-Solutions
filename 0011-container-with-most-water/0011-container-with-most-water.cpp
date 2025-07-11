class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size(); 
        int l = 1, r = n-2;
        int left = 0, right = n-1; 
        int ans = 0; 

        while(left<right)
        {
            // mxleft = max(height[mxleft], height[l]); 
            // mxright = max(height[mxright], height[r]); 

            ans = max(ans, min(height[left], height[right]) * (right-left)); 

            if(height[left] <= height[right]) left++;
            else right--; 
        }
        return ans; 

        
    }
};