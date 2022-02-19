using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Queue
{
    // 1438
    public class Longest_Continuous_Subarray_With_Absolute_Diff
    {
        public int LongestSubarray(int[] nums, int limit)
        {
            if (nums.Length < 1)
                return nums.Length;
            int maxLength = 1, lastIndx = -1;
            LinkedList<int> DDeque = new LinkedList<int>(); // Decreasing Monotonic Deque
            LinkedList<int> IDeque = new LinkedList<int>(); // Increasing Monotonic Deque

            for (int i = 0; i < nums.Length; i++)
            {
                while (DDeque.Count > 0 && nums[DDeque.Last.Value] < nums[i])
                    DDeque.RemoveLast();
                DDeque.AddLast(i);

                while (IDeque.Count > 0 && nums[IDeque.Last.Value] > nums[i])
                    IDeque.RemoveLast();
                IDeque.AddLast(i);

                while (DDeque.Count > 0 
                        && IDeque.Count > 0 
                        && (Math.Abs(nums[DDeque.First.Value] - nums[IDeque.First.Value]) > limit))
                {
                    if (IDeque.First.Value != i)
                    {
                        lastIndx = IDeque.First.Value;
                        IDeque.RemoveFirst();
                    }
                    else
                    {
                        lastIndx = DDeque.First.Value;
                        DDeque.RemoveFirst();
                    }
                }

                maxLength = Math.Max(maxLength, i - lastIndx);
            }

            return maxLength;
        }
    }
}

// need a deque to maintain next integer such 5........13 74 case
// most probably mono decreasing deque solve the problem
// 0  1  2 3  4  5  6  7  8  9  10 11
// 5,49,26,45,13,27,74,87,56,76,25,64 lim = 63
// 5 next integer 13 but in solution 49 assigned
//
// 5 13 27
//
// 87, 74, 27, 13, 45, 26, 49, 5, 56, 76
//
//
//
//