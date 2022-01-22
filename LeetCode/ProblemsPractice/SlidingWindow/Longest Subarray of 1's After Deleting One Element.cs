using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.SlidingWindow
{
    public class Longest_Subarray_of_1_s_After_Deleting_One_Element
    {
        public int LongestSubarray(int[] nums)
        {
            int i = 0, j = 0, len = int.MinValue;
            bool delZero = false;

            while (i < nums.Length)
            {
                if (nums[i] == 0 && delZero)
                {
                    while (delZero)
                    {
                        if (nums[j] == 0)
                            delZero = false;
                        j++;
                    }
                }

                if (nums[i] == 0)
                    delZero = true;

                i++;
                len = Math.Max(len, i-j-1);
            }

            return len;
        }
    }
}
