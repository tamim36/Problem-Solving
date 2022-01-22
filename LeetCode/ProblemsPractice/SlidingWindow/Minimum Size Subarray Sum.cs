using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.SlidingWindow
{
    public class Minimum_Size_Subarray_Sum
    {
        public int MinSubArrayLenOn(int target, int[] nums)
        {
            int minLen = int.MaxValue;
            int curSum = 0;

            for (int i = 0, j = 0; j < nums.Length; )
            {
                if (i < nums.Length && curSum < target) curSum += nums[i++];

                if (curSum >= target)
                {
                    minLen = Math.Min(minLen, i - j);
                    curSum -= nums[j++];
                }

                else if (i == nums.Length) break;
            }

            if (minLen < 0)
                minLen = 0;

            return minLen ;
        }

        public int minSubArrayLen(int s, int[] nums)
        {
            int sum = 0, min = int.MaxValue;

            int[] sums = new int[nums.Length];
            for (int i = 0; i < nums.Length; i++)
                sums[i] = nums[i] + (i == 0 ? 0 : sums[i - 1]);

            for (int i = 0; i < nums.Length; i++)
            {
                int j = findWindowEnd(i, sums, s);
                if (j == nums.Length) break;
                min = Math.Min(j - i + 1, min);
            }

            return min == int.MaxValue ? 0 : min;
        }

        // nums : 2,3,1,2, 4, 3
        // sums : 2,5,6,8,12,15
        private int findWindowEnd(int start, int[] sums, int s)
        {
            int i = start, j = sums.Length - 1, offset = start == 0 ? 0 : sums[start - 1];
            while (i <= j)
            {
                int m = (i + j) / 2;
                int sum = sums[m] - offset;
                if (sum >= s) j = m - 1;
                else i = m + 1;
            }
            return i;
        }
    }
}
