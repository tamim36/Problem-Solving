using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace ProblemsPractice.Contests
{
    public class Biweekly_Contest_67
    {
        public int[] MaxSubsequence(int[] nums, int k)
        {
            int[] sorted = new int[nums.Length];

            sorted = nums.OrderByDescending(x => x).ToArray();

            Dictionary<int, int> isvalid = new Dictionary<int, int>();

            for (int i = 0; i < k; i++)
            {
                if (isvalid.ContainsKey(sorted[i]))
                    isvalid[sorted[i]]++;
                else
                    isvalid.Add(sorted[i], 1);
            }

            int[] ans = new int[k];
            int idx = 0;

            for (int i = 0; i < nums.Length; i++)
            {
                if (isvalid.ContainsKey(nums[i]) && isvalid[nums[i]] > 0)
                {
                    ans[idx++] = nums[i];
                    isvalid[nums[i]]--;
                }
                    
            }

            return ans;
        }
    }
}
