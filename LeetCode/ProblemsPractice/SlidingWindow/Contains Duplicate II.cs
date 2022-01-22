using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.SlidingWindow
{
    public class Contains_Duplicate_II
    {
        public bool ContainsNearbyDuplicate(int[] nums, int k)
        {
            HashSet<int> kNums = new HashSet<int>();

            for (int i = 0; i <= k && i < nums.Length; i++)
            {
                if (kNums.Contains(nums[i]))
                    return true;
                kNums.Add(nums[i]);
            }

            for (int i = k + 1; i < nums.Length; i++)
            {
                kNums.Remove(nums[i - k - 1]);
                if (kNums.Contains(nums[i]))
                    return true;
                kNums.Add(nums[i]);
            }

            return false;
        }
    }
}
