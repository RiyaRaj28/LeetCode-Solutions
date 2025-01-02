class Solution {
public:

    void dfs(vector<vector<char>>&board, vector<vector<int>>&mat, int x, int y)
    {
        mat[x][y] = -1; 
        int m = board.size();
        int n = board[0].size();

        int frow[4] = {-1, 0, 1, 0};
        int fcol[4] = {0, 1, 0, -1};

        for(int p=0; p<4; p++)
        {
            int nrow = x + frow[p];
            int ncol = y + fcol[p]; 

             if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol] == 'O' && mat[nrow][ncol]!=-1)  {
                    dfs(board, mat, nrow, ncol); 
                }
    }
    }
    void solve(vector<vector<char>>& board) 
    {
        //dont have to return anything just change the O to X 
        // we convert all the O's connected to the boundary to nonconvertible
        // then we traverse again, and if it is a X and is non nonconvertible, then we convert it in this iteration 

        // what do we have to do here 
        // we can either do a dfs or a bfs 
        // we use bfs only 
        // we will push in queue if its connected to it 4 dirs 
        int m = board.size(); 
        int n = board[0].size(); 

        vector<vector<int>>mat(m, vector<int>(n, 0)); 

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 || i==m-1 || j== 0 || j==n-1)
                {
                    if(board[i][j] == 'O')
                    {
                        dfs(board, mat, i, j);
                    }
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == 'O' && mat[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};