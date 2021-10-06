using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Minimum_Operations_to_Make_the_Array_Increasing
    {
        public int MinOperations(int[] nums)
        {
            int count = 0;
            int current = 0;
            foreach (var num in nums)
            {
                if (num <= current)
                {
                    count += ++current - num; 
                }
                else
                {
                    current = num;
                }
            }
            return count;
        }
    }
}
