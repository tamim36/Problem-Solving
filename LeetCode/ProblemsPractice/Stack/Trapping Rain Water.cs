using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Stack
{
    // 42
    public class Trapping_Rain_Water
    {
        public int Trap(int[] height)
        {
            if (height == null || height.Length <= 0)
                return 0;

            int[] maxFromLeft = new int[height.Length];
            int max = -1, count = 0;

            for (int i=height.Length - 1; i >= 0; i--)
            {
                max = Math.Max(height[i], max);
                maxFromLeft[i] = max;
            }

            max = -1;
            for (int i = 0; i < height.Length; i++)
            {
                max = Math.Max(max, height[i]);
                count += (Math.Min(max, maxFromLeft[i]) - height[i]); 
            }

            return count;
        }
    }
}
