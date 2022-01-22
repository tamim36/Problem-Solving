using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace ProblemsPractice.Contests
{
    public class Weekly_Contest_271
    {
        // 5953
        public long SubArrayRanges(int[] nums)
        {
            int window = 1, len = nums.Length;
            long sum = 0;
            

            for (int i = 0; i < len-window; i++)
            {
                int minV = nums.Skip(i).Take(window+1).Min();
                int maxV = nums.Skip(i).Take(window+1).Max();
                int val = i + window;
                Console.WriteLine(val + "  " + i + " max " + maxV + "  minv " + minV);
                sum += (long)(maxV - minV);
                if (window < len-1 && i >= len-window-1)
                {
                    window++;
                    i = -1;
                }
            }
            return sum;
        }

        // 5952
        public int CountPoints(string rings)
        {
            int[,] rods = new int[10, 3];

            for (int i = 0; i < rings.Length; i+=2)
            {
                char color = rings[i];
                int rodno = rings[i + 1] - '0';

                if (color == 'R')
                    rods[rodno, 0]++;
                else if (color == 'G')
                    rods[rodno, 1]++;
                else
                    rods[rodno, 2]++;
            }

            int count = 0;
            for (int i=0; i<10; i++)
            {
                if (rods[i, 1] > 0 && rods[i, 0] > 0 && rods[i, 2] > 0)
                    count++;
            }

            return count;
        }
    }
}
