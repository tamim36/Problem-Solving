using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Contests
{
    public class Biweekly_Contest_62
    {
        public int[][] Construct2DArray(int[] original, int m, int n)
        {
            int[][] twoDarray = new int[m][];
            if (m * n != original.Length)
            {
                return new int[0][];
            }
                

            int row = 0, col = 0;
            for (int i=0; i<original.Length; i++)
            {
                row = i / n;
                col = i % n;

                if (col == 0)
                    twoDarray[row] = new int[n];

                twoDarray[row][col] = original[i];
            }

            return twoDarray;
        }

        public int NumOfPairs(string[] nums, string target)
        {
            var lenNum = 4;
            return lenNum;
        }
    }
}
