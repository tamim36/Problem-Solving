using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.PrefixSum
{
    public class Largest_Magic_Square
    {
        int[][] pfx;

        /*      new int[] { 7, 1, 4, 5, 6},
                new int[] { 2, 5, 1, 6, 4 },
                new int[] { 1, 5, 4, 3, 2 },
                new int[] { 1, 2, 7, 3, 4 }*/

        public int rangeVal(int stX, int stY, int enX, int enY)
        {
            int res = 0;
            res = pfx[enX][enY]
                - (stX >= 1 ? pfx[stX - 1][enY] : 0)
                - (stY >= 1 ? pfx[enX][stY - 1] : 0)
                + (stX >= 1 && stY >= 1 ? pfx[stX - 1][stY - 1] : 0);

             return res;
        }

        public int LargestMagicSquare(int[][] grid)
        {
            int len = grid.Length;
            pfx = new int[len][];

            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < grid[0].Length; j++)
                {
                    if (j == 0)
                        pfx[i] = new int[grid[i].Length];

                    pfx[i][j] =
                          (i == 0 ? 0 : pfx[i - 1][j])
                          + (j == 0 ? 0 : pfx[i][j - 1])
                          - (i == 0 || j == 0 ? 0 : pfx[i - 1][j - 1])
                          + grid[i][j];
                }
            }

            for (int i = 0; i < grid.Length; i++)
            {
                for (int j = 0; j < grid[0].Length; j++)
                {
                    Console.Write(grid[i][j] + " ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
            for (int i = 0; i < grid.Length; i++)
            {
                for (int j = 0; j < grid[0].Length; j++)
                {
                    Console.Write(pfx[i][j] + " ");
                }
                Console.WriteLine();
            }

            int stX, stY, enX, enY, row = grid.Length, col = grid[0].Length;

            for (int kLen = grid.Length - 1; kLen > 0; kLen--)
            {
                for (int i = 0; i < row - kLen; i++)
                {
                    for (int j = 0; j < col - kLen; j++)
                    {
                        stX = i; stY = j; enX = i + kLen; enY = j + kLen;
                        Console.WriteLine(stX + "," + stY + "  " + enX + "," + enY);
                        if (checkIfThisValidOrNot(stX, stY, enX, enY, grid, kLen))
                            return kLen+1;
                    }
                }
            }


            return 1;
        }

        private bool checkIfThisValidOrNot(int stX, int stY, int enX, int enY, int[][] grid, int kLen)
        {
            int rowSum = 0, colSum = 0;
            /*
            for (int i=stX; i <= stX + kLen; i++)
            {
                if (colSum > 0 && colSum != rangeVal(i, stY, i, enY))
                    return false;
                else
                    colSum = rangeVal(i, stY, i, enY);
            }

            
            for (int i = stY; i <= stY + kLen; i++)
            {
                if (rowSum > 0 && rowSum != rangeVal(stX, i, enX, i))
                    return false;
                else
                    rowSum = rangeVal(stX, i, enX, i);
            }
            */
            int diag1 = 0, diag2 = 0;
            for (int i = stX, x1 = stX, y1 = stY, x2 = stX, y2 = enY; i <= enX; i++, x1++, y1++, x2++, y2--)
            {
                diag1 += grid[x1][y1];
                diag2 += grid[x2][y2];
            }

            if (diag1 != diag2)
                return false;

            return true;
        }
    }
}
