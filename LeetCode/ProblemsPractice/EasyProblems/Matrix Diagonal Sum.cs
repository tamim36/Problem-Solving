using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Matrix_Diagonal_Sum
    {
        public int DiagonalSum(int[][] mat)
        {
            int sum = 0;
            int wide = mat.Length;
            int pri_a = 0, pri_b = 0, sec_a = 0, sec_b = wide-1;

            for (int i=0; i<wide; i++)
            {
                if ((pri_a == sec_a) && (pri_b == sec_b))
                    sum += mat[pri_a][pri_b];
                else
                    sum += mat[pri_a][pri_b] + mat[sec_a][sec_b];

                pri_a++;
                pri_b++;
                sec_a++;
                sec_b--;
            }

            return sum;
        }
    }
}
