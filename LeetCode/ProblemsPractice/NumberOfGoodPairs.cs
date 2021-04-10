using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class NumberOfGoodPairs
    {
        public int NumIdenticalPairs(int[] nums)
        {
            int count = 0;
            for (int i = 0; i < nums.Length - 1; i++)
            {
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (nums[i] == nums[j] && j > i)
                        count++;
                }
            }
            return count;
        }
    }
}
