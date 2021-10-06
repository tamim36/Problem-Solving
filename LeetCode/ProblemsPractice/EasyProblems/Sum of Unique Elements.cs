using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Sum_of_Unique_Elements
    {
        public int SumOfUnique(int[] nums)
        {
            int[] freq = new int[101];
            int sum = 0;

            foreach (var num in nums)
            {
                freq[num]++;
            }

            foreach (var num in nums)
            {
                if (freq[num] == 1)
                    sum += num;
            }

            return sum;
        }
    }
}
