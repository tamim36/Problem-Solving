using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.SlidingWindow
{
    public class Number_of_Sub_arrays_of_Size_K_and_Average
    {
        public int NumOfSubarrays(int[] arr, int k, int threshold)
        {
            int sumAvg = k * threshold;
            int sum = 0, count = 0;


            for (int i = 0; i < k && i < arr.Length; i++)
                sum += arr[i];

            if (sum >= sumAvg)
                count++;

            for (int i = k; i < arr.Length; i++)
            {
                sum += arr[i] - arr[i - k];

                if (sum >= sumAvg)
                    count++;
            }

            return count;
        }
    }
}
