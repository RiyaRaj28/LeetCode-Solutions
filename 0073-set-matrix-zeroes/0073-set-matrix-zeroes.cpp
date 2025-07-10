class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(); 
        int n = matrix[0].size(); 

        vector<int>markrow(m, 0); 
        vector<int>markcol(n, 0); 

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    markrow[i] = 1; 
                    markcol[j] = 1; 
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(markrow[i] || markcol[j])
                {
                    matrix[i][j] = 0; 
                }
            }
        }
        
    }
};