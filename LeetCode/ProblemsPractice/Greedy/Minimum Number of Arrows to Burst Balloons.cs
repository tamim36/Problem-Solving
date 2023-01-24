using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    public class Minimum_Number_of_Arrows_to_Burst_Balloons
    {
        public int FindMinArrowShots(int[][] points)
        {
            Array.Sort(points, (x, y) => x[0].CompareTo(y[0]));
            int[] cur = new int[2];
            int count = 0;
            cur[0] = int.MinValue;
            cur[1] = int.MaxValue;

            foreach (var item in points)
            {
                int start = item[0];
                int end = item[1];

                if ((cur[0] != int.MinValue && cur[1] != int.MaxValue) && (cur[0] <= start && start <= cur[1]))
                {
                    cur[0] = Math.Max(cur[0], start);
                    cur[1] = Math.Min(end, cur[1]);
                }
                else
                {
                    cur[0] = start;
                    cur[1] = end;
                    count++;
                }
            }
            Console.WriteLine(0);
            return count;
        }
    }
}
