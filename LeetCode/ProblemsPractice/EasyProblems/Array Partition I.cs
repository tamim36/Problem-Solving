using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.EasyProblems
{
    public class Array_Partition_I
    {
        public int ArrayPairSum(int[] nums)
        {
            Array.Sort(nums);
            int maxSum = 0;

            for (int i=0; i < nums.Length; i=i+2)
            {
                maxSum += nums[i];
            }

            return maxSum;
        }
    }
}
