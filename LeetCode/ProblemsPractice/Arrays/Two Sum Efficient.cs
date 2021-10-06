using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Arrays
{
    public class Two_Sum_Efficient
    {
        public int[] TwoSum(int[] nums, int target)
        {
            IDictionary<long, long> valIndx = new Dictionary<long, long>();
            IList<long> resList = new List<long>();
            int ansOne = 0, ansTwo = 0;

            for (int i=0; i<nums.Length; i++)
            {
                long residual = target - nums[i];
                if (resList.Contains(nums[i]))
                {
                    ansOne = i;
                    ansTwo = (int)valIndx[residual];
                }
                else
                {
                    resList.Add(residual);
                    valIndx[nums[i]] = i; 
                }
            }

            return new int[] { ansTwo, ansOne };
        }
    }
}
