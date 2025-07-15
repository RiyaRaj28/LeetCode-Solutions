class Solution {
public:

    // do a dfs and mark all the os connected to the boundary as 
    // non convertible then 
    // mark all the rest Os as Xx

    void dfs(int row, int col, vector<vector<char>>&board, vector<vector<int>>&marked)
    {
        int m = board.size();
        int n = board[0].size();

        marked[row][col] = -1;
        vector<int>frow = {-1, 0, 1, 0};
        vector<int>fcol = {0, 1, 0, -1};

        for(int i=0; i<4; i++)
        {
            int arow = row + frow[i];
            int acol = col + fcol[i];

            if(arow>=0 && arow<m && acol>=0 && acol<n && board[arow][acol] == 'O' && marked[arow][acol] == 0)
            {
                dfs(arow, acol, board, marked);
            }
        }
    }

    void solve(vector<vector<char>>& board) 
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>marked(m, vector<int>(n, 0));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 || i==m-1 || j==0 || j==n-1)
                {
                    if(board[i][j] == 'O')
                        dfs(i, j, board, marked);
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == 'O' && marked[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};