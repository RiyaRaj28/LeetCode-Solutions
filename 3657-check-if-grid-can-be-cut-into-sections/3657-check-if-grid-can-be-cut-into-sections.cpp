// class Solution {
// public:

//     static bool comp1(vector<int>r1, vector<int>r2)
//     {
//         return r1[0] < r2[0]; 
//     }

//     static bool comp2(vector<int>r1, vector<int>r2)
//     {
//         return r1[1] < r2[1]; 
//     }

//     bool isPoss(vector<vector<int>>r, int axis)
//     {
//         if(!axis) sort(r.begin(), r.end(), comp1); 
//         else sort(r.begin(), r.end(), comp2);

//         int prev_end = -1; 
//         int cnt = 0; 
//         for(int i=0; i<r.size(); i++)
//         {
//             int start = r[i][axis]; 
//             int end = r[i][axis+2]; 

//             if(start >= prev_end)
//             {
//                 cnt += 1; 
//                 if(cnt >= 3) return true; 
//                 prev_end = end; 
//             }
//             else
//             {
//                 prev_end = max(prev_end, end); 
//             }

//         }

//         return false; 

//     }
//     bool checkValidCuts(int n, vector<vector<int>>& r) 
//     {
//         return isPoss(r, 0) || isPoss(r, 1); 

//     }
// };  


class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return isValidCut(rectangles, 0, 0, 2) || isValidCut(rectangles, 1, 1, 3);
    }

private:
    bool isValidCut(vector<vector<int>>& rectangles, int sortIndex, int start, int end) {
        sort(rectangles.begin(), rectangles.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[sortIndex] < b[sortIndex];
        });

        // int currentStart = rectangles[0][start];
        int currentEnd = rectangles[0][end];
        int intervals = 0;

        for (const auto& rect : rectangles) {
            if (rect[start] < currentEnd) {
                currentEnd = max(rect[end], currentEnd);
            } else {
                intervals++;
                // currentStart = rect[start];
                currentEnd = rect[end];
            }
        }
        intervals++;

        return intervals > 2;
    }
};