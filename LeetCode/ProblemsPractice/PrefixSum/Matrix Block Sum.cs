using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.PrefixSum
{
    public class Matrix_Block_Sum
    {
        public int[][] MatrixBlockSum(int[][] mat, int k)
        {
            for (int i = 0; i < mat.Length; i++)
            {
                for (int j = 0; j < mat[0].Length; j++)
                {
                    mat[i][j] += (j == 0 ? 0 : mat[i][j - 1])
                                + (i == 0 ? 0 : mat[i - 1][j])
                                - (i == 0 || j == 0 ? 0 : mat[i - 1][j - 1]);
                }
            }

            int[][] ans = new int[mat.Length][];
            int r1 = 0, r2 = 0, c1 = 0, c2 = 0;

            for (int i = 0; i < mat.Length; i++)
            {
                for (int j = 0; j < mat[0].Length; j++)
                {
                    if (j == 0)
                        ans[i] = new int[mat[0].Length];
                    r1 = i - k <= 0 ? 0 : i - k;
                    c1 = j - k <= 0 ? 0 : j - k;
                    r2 = i + k >= mat.Length ? mat.Length - 1 : i + k;
                    c2 = j + k >= mat[0].Length ? mat[0].Length - 1 : j + k;

                    ans[i][j] = mat[r2][c2]
                                    + (r1 > 0 && c1 > 0 ? mat[r1 - 1][c1 - 1] : 0)
                                    - (r1 == 0 ? 0 : mat[r1 - 1][c2])
                                    - (c1 == 0 ? 0 : mat[r2][c1 - 1]);
                    
                }
            }

            return ans;
        }
    }
}
