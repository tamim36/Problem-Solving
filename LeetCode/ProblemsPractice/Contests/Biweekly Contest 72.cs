using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Contests
{
    public class Biweekly_Contest_72
    {
        public int CountPairs(int[] nums, int k)
        {
            int res = 0;
            for (int i = 0; i < nums.Length-1; i++)
            {
                for (int j = i+1; j < nums.Length; j++)
                {
                    if (nums[i] == nums[j] && (i*j)%k == 0)
                        res++;
                }
            }

            return res;
        }

        public long[] SumOfThree(long num)
        {
            if (num % 3 != 0)
                return new long[0];

            long middleNum = num / 3;

            return new long[] {middleNum-1, middleNum, middleNum+1};
        }
    }
}
