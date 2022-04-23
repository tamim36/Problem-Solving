using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    public class Append_K_Integers_With_Minimal_Sum
    {
        public long MinimalKSum(int[] nums, int k)
        {
            Array.Sort(nums);

            long sumKnum = 0, ansSum = 0;
            int limit = k;
            long tmax = long.MaxValue;
            for (int i = 0; i < nums.Length && nums[i] <= limit; i++)
            {
                if (i > 0 && nums[i] == nums[i - 1])
                    continue;

                sumKnum += nums[i];
                limit++;
            }

            ansSum = ((long)limit * ((long)limit + 1)) / 2;
            return ansSum - sumKnum;
        }
    }
}
