using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    // 11
    public class Container_With_Most_Water
    {
        public int MaxArea(int[] height)
        {
            int maxArea = int.MinValue;
            for (int i = 0, j = height.Length-1; i < j;)
            {
                maxArea = Math.Max(maxArea, Math.Min(height[i], height[j]) * (j - i));
                if (height[i] < height[j])
                    i++;
                else
                    j--;
            }

            return maxArea;
        }
    }
}
