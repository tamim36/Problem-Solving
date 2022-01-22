using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.PrefixSum
{
    public class Sum_of_Absolute_Differences_in_a_Sorted_Array
    {
        public int[] GetSumAbsoluteDifferences(int[] nums)
        {
            int len = nums.Length;
            int[] prefixSums = new int[len];
            int[] ans = new int[len];

            for (int i = 0; i < nums.Length; i++)
            {
                prefixSums[i] = nums[i] + (i == 0 ? 0 : prefixSums[i - 1]);
            }

            int pre = 0, post = 0, postRangeSum = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                pre = i == 0 ? 0 : Math.Abs((i * nums[i]) - prefixSums[i - 1]);
                postRangeSum = i == 0 ? prefixSums[len - 1] : prefixSums[len-1] - prefixSums[i - 1];
                post = Math.Abs(((len - i) * nums[i]) - postRangeSum);
                ans[i] = pre + post;
            }

            return ans;
        }
    }
}
