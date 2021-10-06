using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    public class Reshape_the_Matrix
    {
        public int[][] MatrixReshape(int[][] mat, int r, int c)
        {
            Queue<int> allVal = new Queue<int>();
            
            if ((mat.Length * mat[0].Length) != r * c)
            {
                return mat;
            }
                

            foreach (var nums in mat)
            {
                foreach (var num in nums)
                {
                    allVal.Enqueue(num);
                }
            }

            int[][] ansAra = new int[r][];

            for (int i=0; i<r; i++)
            {
                ansAra[i] = new int[c];
                for (int j = 0; j < c; j++)
                {
                    ansAra[i][j] = allVal.Dequeue();
                }
            }

            return ansAra;
        }
    }
}
