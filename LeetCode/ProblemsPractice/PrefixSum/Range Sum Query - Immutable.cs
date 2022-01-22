using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.PrefixSum
{
    public class Range_Sum_Query___Immutable
    {
        int[] prefixSums;
        public void NumArray(int[] nums)
        {
            prefixSums = new int[nums.Length];
            prefixSums[0] = nums[0];
            for (int i = 1; i < nums.Length; i++)
            {
                prefixSums[i] = nums[i] + prefixSums[i - 1];
            }
        }

        public int SumRange(int left, int right)
        {
            return left > 0 ? prefixSums[right] - prefixSums[left - 1] : prefixSums[right];
        }
    }
}
