using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Design
{
    public class Range_Sum_Query_2D___Immutable
    {
        int[][] mat;
        public void NumMatrix(int[][] matrix)
        {
            mat = new int[matrix.Length][];
            for (int i = 0; i < matrix.Length; i++)
            {
                for (int j = 0; j < matrix[0].Length; j++)
                {
                    if (j == 0)
                        mat[i] = new int[mat[0].Length];

                    mat[i][j] = matrix[i][j]
                                + (j == 0 ? 0 : matrix[i][j - 1])
                                + (i == 0 ? 0 : matrix[i - 1][j])
                                - (i == 0 || j == 0 ? 0 : matrix[i - 1][j - 1]);
                }
            }
        }

        public int SumRegion(int row1, int col1, int row2, int col2)
        {
            return mat[row2][col2]
                            + (row1 > 0 && col1 > 0 ? mat[row1 - 1][col1 - 1] : 0)
                            - (row1 == 0 ? 0 : mat[row1 - 1][col2])
                            - (col1 == 0 ? 0 : mat[row2][col1 - 1]);
        }
    }
}
