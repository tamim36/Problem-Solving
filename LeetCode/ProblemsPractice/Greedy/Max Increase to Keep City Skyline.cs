using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    public class Max_Increase_to_Keep_City_Skyline
    {
        public int MaxIncreaseKeepingSkyline(int[][] grid)
        {
            int length = grid.Length;
            int[] rowMax = new int[length];
            int[] colMax = new int[length];
            int maxIncrement = 0;

            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < length; j++)
                {
                    if (grid[i][j] > rowMax[i])
                    {
                        rowMax[i] = grid[i][j];
                    }
                }
            }

            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < length; j++)
                {
                    if (grid[j][i] > colMax[i])
                    {
                        colMax[i] = grid[j][i];
                    }
                }
            }

            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < length; j++)
                {
                    int min = Math.Min(rowMax[i], colMax[j]);
                    maxIncrement += (min - grid[i][j]);
                }
            }

            /*for (int i = 0; i < rowMax.Length; i++)
            {
                Console.Write(rowMax[i] + "  ");
            }

            Console.WriteLine();

            for (int i = 0; i < colMax.Length; i++)
            {
                Console.Write(colMax[i] + "  ");
            }
            Console.WriteLine();*/

            return maxIncrement;
        }
    }
}
