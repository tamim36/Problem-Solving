using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Greedy
{
    public class Minimize_Maximum_Pair_Sum_in_Array
    {
        public int MinPairSum(int[] nums)
        {
            Array.Sort(nums);
            int maxVal = 0;

            for (int i=0, j=nums.Length-1; i<j; i++, j--)
            {
                if (nums[i] + nums[j] > maxVal)
                {
                    maxVal = nums[i] + nums[j];
                }
            }

            return maxVal;
        }
    }
}
