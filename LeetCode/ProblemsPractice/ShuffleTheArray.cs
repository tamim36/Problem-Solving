using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice
{
    public class ShuffleTheArray
    {
        public int[] Shuffle(int[] nums, int n)
        {
            IList<int> ans = new List<int>();

            for (int i = 0; i < n; i++)
            {
                ans.Add(nums[i]);
                ans.Add(nums[i + n]);
            }
            return ans.ToArray();
        }
    }
}
