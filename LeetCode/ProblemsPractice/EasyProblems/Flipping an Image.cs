using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Flipping_an_Image
    {
        public int[][] FlipAndInvertImage(int[][] image)
        {
            var row = image.Length;
            var col = image[0].Length;
            var flippedImage = new int[row][];


            for (int i = 0; i < row; i++)
            {
                int k = 0;
                flippedImage[i] = new int[col];
                for (int j = col-1; j >= 0; j--, k++)
                {
                    flippedImage[i][k] = image[i][j] == 0 ? 1 : 0;
                }
            }

            return flippedImage;
        }
    }
}
