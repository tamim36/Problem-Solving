using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Sum_of_All_Odd_Length_Subarrays_Optimized
    {
        public int SumOddLengthSubarrays(int[] arr)
        {
            int sum = 0;
            int len = arr.Length;
            for (int i = 0; i < len; i++)
            {
                int startSubArray = len - i;
                int endSubArray = i + 1;

                int total = startSubArray * endSubArray;
                int oddTotal = (int)Math.Ceiling((double)total / 2);
                sum += arr[i] * oddTotal ;
            }

            return sum;
        }
    }
}
