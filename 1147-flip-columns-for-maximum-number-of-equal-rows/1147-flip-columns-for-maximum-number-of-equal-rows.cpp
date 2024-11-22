class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) 
    {
        int n = matrix.size(); //rows
        int m = matrix[0].size(); //cols

          int maxcount = 0;   
          for(auto &vec: matrix)  //O(n)
          {
            vector<int>inverted(m, 0);  //O(m)
            for(int i=0; i<m; i++)
            {
                inverted[i] = vec[i] == 0 ? 1 : 0;
            }

            int count = 0; 
            for(auto &row : matrix)    //O(n)
            {
                if(row == vec || row == inverted)
                count++;
            }

                maxcount = max(count, maxcount);
          }

          return maxcount; 

        
    }
};