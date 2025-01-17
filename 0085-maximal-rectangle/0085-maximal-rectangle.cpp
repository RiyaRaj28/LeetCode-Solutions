class Solution {
public:

    vector<int>NSR(vector<int>arr)
    {
        int n = arr.size();
        vector<int>ans(n); 
        stack<int>st; 
        for(int i=n-1; i>=0; i--)
        {
            if(st.empty()) ans[i] = n;
            else
            {
                while(!st.empty() && arr[i] < arr[st.top()]) st.pop();
                ans[i] = st.empty() ? n : st.top();
            }

            st.push(i);
        }

        return ans; 
    }

    vector<int>NSL(vector<int>arr)
    {
        int n = arr.size();
        vector<int>ans(n); 
        stack<int>st; 
        for(int i=0; i<arr.size(); i++)
        {
            if(st.empty()) ans[i] = -1;
            else
            {
                while(!st.empty() && arr[i] <= arr[st.top()]) st.pop();
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return ans; 
    }

    int MAH(vector<int>height)
    {
        vector<int>nsr = NSR(height);
        vector<int>nsl = NSL(height);

        int maxarea = 0; 
        int n = height.size();
        for(int i=0; i<n; i++)
        {
            int ht = height[i];
            int width = nsr[i] - nsl[i] - 1;
            
            int area = ht*width; 
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>height(n, 0);
        int maxarea = 0; 

        for(int i=0; i<n; i++)
        {
            height[i] = matrix[0][i] == '0' ? 0 : 1; 
        }
        
        maxarea = max(maxarea, MAH(height));

        for(int i=1; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == '0') height[j] = 0;
                else height[j] += 1;
            }
            maxarea = max(maxarea, MAH(height));
        }
        return maxarea; 
    }
};