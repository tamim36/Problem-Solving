using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Count_Negative_Numbers
    {
        public int CountNegatives(int[][] grid)
        {
            int neg = 0;
            int row = grid.Length;
            int col = grid[0].Length;
            for (int i =0; i<row; i++) {
                for (int j = 0; j < col; j++)
                {
                    if (grid[i][j] < 0)
                    {
                        neg += ((row - i) * (col - j));
                        col -= (col - j);
                    }
                }
            }
            return neg;
        }
    }
}
