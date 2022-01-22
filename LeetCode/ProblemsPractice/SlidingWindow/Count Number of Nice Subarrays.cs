using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.SlidingWindow
{
    public class Count_Number_of_Nice_Subarrays
    {
        public int NumberOfSubarrays(int[] nums, int k)
        {
            int i = 0, j = 0, prev = 0;


            while (i < nums.Length && nums[i] % 2 != 1) i++;

            if (i == nums.Length)
                return 0;

            if (nums[i]%2 == 1)
            {
                k--;
                j = i + 1;
            }
            while (j < nums.Length && k > 0)
            {
                if (nums[j] % 2 == 1) k--;
                if (j == nums.Length - 1) break;
                
                j++;
            }

            if (nums[j] % 2 == 1) --j;

            int prevTotal = (i - prev) + 1;
            int afterCnt = 0;
            int total = 0;

            while (j < nums.Length && nums[j] % 2 == 0)
            {
                afterCnt++;
                j++;
            }
            if (nums[j] % 2 == 1) --j;

            total += prevTotal * (afterCnt + 1);
            prev = 0;
            while (j < nums.Length)
            {
                prevTotal = 0;
                j++;
                i++;
                while (i < nums.Length && nums[i] % 2 != 1) i++;
                prevTotal = (i - prev);
                if (prevTotal == 0) ++prevTotal;
                afterCnt = 0;
                if (j == nums.Length || i == nums.Length) return total;
                while (j< nums.Length && nums[j] % 2 != 1)
                {
                    afterCnt++;
                    j++;
                }
                total += prevTotal * (afterCnt + 1);
            }

            return total;
        }
    }
}
