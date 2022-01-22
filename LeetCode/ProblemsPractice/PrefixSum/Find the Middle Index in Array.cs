using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.PrefixSum
{
    public class Find_the_Middle_Index_in_Array
    {
        public int FindMiddleIndex(int[] nums)
        {
            int[] leftSum = new int[nums.Length], rightSum = new int[nums.Length];

            leftSum[0] = nums[0];
            rightSum[nums.Length - 1] = nums[nums.Length - 1];
            for (int i = 1, j=nums.Length-2; i < nums.Length; i++, j--)
            {
                leftSum[i] = nums[i] + leftSum[i - 1];
                rightSum[j] = nums[j] + rightSum[j + 1];
            }

            for (int i = 0; i < nums.Length; i++)
            {
                if ((i == 0 ? 0 : leftSum[i - 1]) == (i == nums.Length - 1 ? 0 : rightSum[i + 1]))
                    return i;
            }

            return -1;
        }
    }
}
