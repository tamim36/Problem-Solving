using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.TwoPointer
{
    public class Two_Sum_II
    {
        public int[] TwoSum(int[] numbers, int target)
        {
            for (int i=0, j=numbers.Length-1; i<j;)
            {
                if (numbers[i] + numbers[j] < target)
                    i++;
                else if (numbers[i] + numbers[j] > target)
                    j--;
                else
                    return new int[] { ++i, ++j };
            }
            return new int[] { 0 };
        }
    }
}
