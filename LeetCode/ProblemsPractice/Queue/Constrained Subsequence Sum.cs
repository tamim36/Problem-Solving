using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Queue
{
    // 1425
    public class Constrained_Subsequence_Sum
    {
        public int ConstrainedSubsetSum(int[] nums, int k)
        {
            LinkedList<int> deque = new LinkedList<int>();
            int[] res = new int[nums.Length];
            int maxRes = nums[0];

            for (int i = 0; i < nums.Length; i++)
            {
                while (deque.Count > 0 && i - deque.First.Value > k)
                    deque.RemoveFirst();

                res[i] = deque.Count == 0 ? nums[i] : Math.Max(nums[i] + res[deque.First.Value], nums[i]);

                while (deque.Count > 0 && res[deque.Last.Value] < res[i])
                    deque.RemoveLast();
                deque.AddLast(i);
                maxRes = Math.Max(maxRes, res[i]);
            }

            return maxRes;
        }
    }
}
