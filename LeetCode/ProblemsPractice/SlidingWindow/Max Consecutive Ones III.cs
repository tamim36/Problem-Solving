using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.SlidingWindow
{
    public class Max_Consecutive_Ones_III
    {
        public int LongestOnes(int[] nums, int k)
        {
            int lenSub = 0;

            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] == 0) k--;
                if (k < 0 && i >= lenSub && nums[i - lenSub] == 0) k++;
                else if (k >= 0) lenSub++;
            }

            return lenSub;
        }

        public int numberOfSubstrings(String s)
        {
            int[] arr = new int[3];
            int result = 0;
            int l = 0;
            for (int r = 0; r < s.Length; ++r)
            {
                arr[s[r] - 'a']++;
                while (arr[0] > 0 && arr[1] > 0 && arr[2] > 0)
                {
                    arr[s[l] - 'a']--;
                    l++;
                }
                result += l;
            }
            return result;
        }
    }
}
