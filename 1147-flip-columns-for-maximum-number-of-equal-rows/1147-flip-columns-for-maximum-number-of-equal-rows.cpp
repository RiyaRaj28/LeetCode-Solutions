class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) 
    {
        // int n = matrix.size(); //rows
        // int m = matrix[0].size(); //cols

        //   int maxcount = 0;   
        //   for(auto &vec: matrix)  //O(n)
        //   {
        //     vector<int>inverted(m, 0);  //O(m)
        //     for(int i=0; i<m; i++)
        //     {
        //         inverted[i] = vec[i] == 0 ? 1 : 0;
        //     }

        //     int count = 0; 
        //     for(auto &row : matrix)    //O(n)
        //     {
        //         if(row == vec || row == inverted)
        //         count++;
        //     }

        //         maxcount = max(count, maxcount);
        //   }

        //   return maxcount; 

        // we create an unordered map 
        // for each row of the matrix
        // find the nature of first = row[0]
        // find nature of row = ""
        // for the rest elems of the row 
        // if their nature is same as that of first then add s in the nature of row string else d 
        // mpp[natureofrow]++
        // iterate through map and find the max value of second element and return that 

        unordered_map<string, int>mpp; 
        int n = matrix.size(); 
        int m = matrix[0].size();

        for(auto &vec: matrix)
        {
            string nature = "";
            int firstval = vec[0];
            for(int i=1; i<m; i++)
            {
                if(vec[i] == firstval) 
                {
                    nature += 's';
                }
                else nature += 'd';
            }

            mpp[nature]++;
        }

        int maxcount = 0;
        for(auto &it: mpp)
        {
            if(it.second > maxcount)
            {
                maxcount = it.second; 
            }
        } 

        return maxcount;
    }
};