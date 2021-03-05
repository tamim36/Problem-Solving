using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class SolTwoSum
    {
        public int[] TwoSum(int[] nums, int target)
        {
            int ind, jnd;
            for (int i = 0; i < nums.Length; i++)
            {
                int res = (target - nums[i]);
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (nums[j] == res)
                    {
                        return new int[] { i, j };
                    }
                }
            }
            return null;
        }
    }
}
