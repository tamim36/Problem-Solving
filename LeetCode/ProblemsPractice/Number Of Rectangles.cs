using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Number_Of_Rectangles
    {
        public int CountGoodRectangles(int[][] rectangles)
        {
            int maxNum = Int32.MinValue;
            int count = 0;

            foreach (var rectangle in rectangles)
            {
                int minLength = rectangle[0] < rectangle[1] ? rectangle[0] : rectangle[1];
                if (maxNum == minLength)
                {
                    count++;
                }
                else if (maxNum < minLength)
                {
                    maxNum = minLength;
                    count = 1;
                }
            }

            return count;
        }
    }
}
