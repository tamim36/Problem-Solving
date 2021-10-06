using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice.Contests
{
    public class WeeklyContest260
    {
        public int MaximumDifference(int[] nums)
        {
            int maxDifference = -1;
            for (int i = nums.Length-1, j=1; i > 0; i--, j++)
            {
                int min = nums.Take(nums.Length - j).Min();
                int diff = nums[i] - min;
                if (maxDifference < diff)
                    maxDifference = diff;
            }

            if (maxDifference == 0)
                maxDifference = -1;
            return maxDifference;
        }
    }
}
