class Solution {
public:

    //BRUTE : MARK AS -1 ALL ROW AND COL HAVING 0, THEN MARK 0
    //     void markRow(vector<vector<int>>& matrix, int row, int col)
    //     {
    //         for(int i=0; i<col; i++)
    //         {
    //             if(matrix[row][i] != 0)
    //                 matrix[row][i] = -1; 
    //         }
    //     }

    //     void markCol(vector<vector<int>>& matrix, int col, int row)
    //     {
    //         for(int i=0; i<row; i++)
    //         {
    //             if(matrix[i][col] != 0)
    //                 matrix[i][col] = -1; 
    //         }
    //     }

    // void setZeroes(vector<vector<int>>& matrix) 
    // {
    //     int n = matrix.size();
    //     int m = matrix[0].size(); 
    //     for (int i=0; i<n; i++)
    //     {
    //         for(int j=0; j<m; j++)
    //         {
    //             if(matrix[i][j] == 0)
    //             {
    //                 markRow(matrix, i, m);
    //                 markCol(matrix, j, n);
    //             }
    //         }
    //     }

    //     for(int i=0; i<n; i++)
    //     {
    //         for(int j=0; j<m; j++)
    //         {
    //             if(matrix[i][j] == -1)
    //             {
    //                 matrix[i][j] = 0; 
    //             }
    //         }
    //     }
  
    // }

//BETTER : zero_row and zero_col extra arrays 
// void setZeroes(vector<vector<int>>& matrix) 
// {
//     int n = matrix.size();
//     int m = matrix[0].size();
//         vector<int> zero_row(n, 0);
//         vector<int> zero_col(m, 0);

//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<m; j++)
//         {
//             if(matrix[i][j] == 0)
//             {
//                 zero_row[i] = 1;
//                 zero_col[j] = 1; 
//             }
//         }
//     }

//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<m; j++)
//         {
//             if(zero_row[i] == 1 || zero_col[j] == 1)
//             {
//                 matrix[i][j] = 0; 
//             }
//         }
//     }
// }

// void setZeroes(vector<vector<int>>& matrix) 
// {
//     int col0 = 1;
//     int n = matrix.size();
//     int m = matrix[0].size();

//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<m; j++)
//         {
//             if(matrix[i][j] == 0)
//             {
//                 matrix[i][0] = 0;

//                 if(j!= 0)
//                     matrix[0][j] = 0;
//                 else 
//                     col0 = 0; 
//             }
//         }
//     }

//     for(int i=1; i<n; i++)
//     {
//         for(int j=1; j<m; j++)
//         {
//             if(matrix[i][j] != 0)
//             {
//                 if(matrix[i][0] == 0 || matrix[0][j] == 0)
//                 {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }

//     //marking 0th row 
//     if(matrix[0][0] == 0)
//     {
//         for(int j=0; j<m; j++)
//         {
//             matrix[0][j] = 0; 
//         }
//      }   

//     if(col0 == 0)
//     {
//         for(int i=0; i<n; i++)
//         {
//             matrix[i][0] = 0;
//         }
//     }


// mark -1 again attempt but failing as test case has a -1 originally given 
// void setRowColMinusOne(vector<vector<int>>&matrix, int row, int col)
// {
//     int m = matrix.size(); 
//     int n = matrix[0].size();

//     for(int i=0; i<n; i++)
//     {
//         matrix[row][i] = matrix[row][i] != 0 ? -1 : 0; 
//     }
    
//     for(int i=0; i<m; i++)
//     {
//         matrix[i][col] = matrix[i][col] != 0 ? -1 : 0; 
//     }
//     matrix[row][col] = -1; 

// }

// void setZeroes(vector<vector<int>>& matrix) 
// {
//     int m = matrix.size(); 
//     int n = matrix[0].size(); 
//     for(int i=0; i<m; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             if(matrix[i][j] == 0)
//             {
//                 setRowColMinusOne(matrix, i, j); 
//             }
//         }
//     }

//     for(int i=0; i<m; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             if(matrix[i][j] == -1) matrix[i][j] = 0;
//         }
//     }

//     // return matrix; 
// }



// mark row mark col attempt again 

// void setZeroes(vector<vector<int>>& matrix) 
// {
//     int m = matrix.size(); 
//     int n = matrix[0].size(); 

//     vector<int>rows(m, 0); 
//     vector<int>cols(n, 0); 

//     for(int i=0; i<m; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             if(matrix[i][j] == 0)
//             {
//                 rows[i] = 1; 
//                 cols[j] = 1; 
//             }
//         }
//     }

//     for(int i=0; i<m; i++)
//     {
//         if(rows[i] == 1)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 matrix[i][j] = 0; 
//             }
//         }
//     }

//     for(int j=0; j<n; j++)
//     {
//         if(cols[j] == 1)
//         {
//             for(int i=0; i<m; i++)
//             {
//                 matrix[i][j] = 0; 
//             }
//         }
//     }
// }



// col0 attempt again 

void setZeroes(vector<vector<int>>&matrix)
{
	int col0 = 0; 
	int m = matrix.size(); 
	int n = matrix[0].size(); 

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				if(j!=0)
				{	
					matrix[0][j] = 0; 
				}
                else col0 = 1; 
			}
		}
	}

	
	for(int i=1; i<m; i++)
	{
		if(matrix[i][0] == 0)
			for(int j=0; j<n; j++)
			{
				matrix[i][j] = 0; 
			}
	}

	for(int j=1; j<n; j++)
	{
		if(matrix[0][j] == 0)
			for(int i=0; i<m; i++)
				matrix[i][j] = 0; 
	}

	if(matrix[0][0] == 0) 
	{
		for(int i=0; i<n; i++)
			matrix[0][i] = 0; 
	} 

            
	if(col0 == 1) 
	{
		for(int j=0; j<m; j++)
		{
			matrix[j][0] = 0; 
		}
	}
}





























};