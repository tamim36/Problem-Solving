using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    public class Score_After_Flipping_Matrix
    {
        public int MatrixScore(int[][] grid)
        {
            int score = 0, colOneCount = 0;
            int[] rowMoves = new int[grid.Length];
            int[] colMoves = new int[grid[0].Length];

            for (int col = 0; col < grid[0].Length; col++)
            {
                for (int row = 0; row < grid.Length; row++)
                {
                    if (col == 0 && grid[row][col] == 0)
                        rowMoves[row]++;

                    else if (col > 0 && ((grid[row][col] ^ rowMoves[row]) == 1))
                        colOneCount++;
                }

                if (col > 0 && colOneCount < (int)Math.Ceiling((double)grid.Length / 2))
                    colMoves[col]++; 

                colOneCount = 0;
            }

            for (int row = 0; row < grid.Length; row++)
            {
                for (int col = 0; col < grid[0].Length; col++)
                {
                    if ((rowMoves[row] == 0 && colMoves[col] == 1) || (rowMoves[row] == 1 && colMoves[col] == 0))
                        grid[row][col] = 1 ^ grid[row][col];
                }
            }

            for (int row = 0; row < grid.Length; row++)
            {
                for (int col = grid[0].Length-1, decimalPlace = 0; col >= 0; col--, decimalPlace++)
                {
                    score += grid[row][col] * (int)Math.Pow(2, decimalPlace);
                }
            }

            return score;
        }
    }
}
