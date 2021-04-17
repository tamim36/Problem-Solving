using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Sum_of_All_Odd_Length_Subarrays
    {
        public int SumOddLengthSubarrays(int[] arr)
        {
            int sum = 0;
            for (int i = 1; i <= arr.Length; i+=2)
            {
                for (int j = 0; j < arr.Length-i+1; j++)
                {
                    for (int k = j; k < i+j; k++)
                    {
                        sum += arr[k];
                    }
                }
            }

            return sum;
        }
    }
}
