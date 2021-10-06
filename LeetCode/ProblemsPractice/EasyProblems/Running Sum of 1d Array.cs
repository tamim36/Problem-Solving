using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Running_Sum_of_1d_Array
    {
        public int[] RunningSum(int[] nums)
        {
            var newList = new List<int>();

            int sum = 0;

            for (int i = 0; i < nums.Length; i++)
            {
                sum += nums[i];
                newList.Add(sum);
            }

            return newList.ToArray();
        }
    }
}
