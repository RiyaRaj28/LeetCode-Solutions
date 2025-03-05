class Solution {
public:
    long long coloredCells(int n) 
    {
        // long long count = 1; 
        // // unordered_map<pair<int, int>, int>mpp; 
        // set<pair<int, int>>st; 
        // queue<pair<pair<int, int>, int>>q; 

        // q.push({{0, 0}, 1}); 
        // st.insert({0, 0});

        // vector<int> frow = {-1, 0, 1, 0}; 
        // vector<int> fcol = {0, 1, 0, -1}; 

        // while(!q.empty())
        // {
        //     int x = q.front().first.first; 
        //     int y = q.front().first.second; 

        //     int time = q.front().second; 
        //     q.pop(); 

        //     if(time == n) return count;
        //     // count++;  

        //     for(int k=0; k<4; k++)
        //     {
        //         int nrow = x + frow[k]; 
        //         int ncol = y + fcol[k]; 

        //         if(st.find({nrow, ncol}) == st.end())
        //         {
        //             count++;
        //             q.push({{nrow, ncol}, time+1}); 
        //             st.insert({nrow, ncol}); 
        //         }
        //     }
        // }

        // return -1; 

        return 1 + (long long)2*n*(n-1); 
        
    }
};