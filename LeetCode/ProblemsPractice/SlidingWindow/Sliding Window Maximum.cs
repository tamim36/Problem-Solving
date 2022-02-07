using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.SlidingWindow
{
    // 239
    public class Sliding_Window_Maximum
    {
        public int[] MaxSlidingWindow(int[] nums, int k)
        {
            if (nums.Length == 1 || k == 1)
                return nums;

            List<int> result = new List<int>();
            LinkedList<int> deque = new LinkedList<int>();
            deque.AddFirst(0); // adding initial item index

            for (int i = 1; i < k; i++)
            {
                while (deque.Count > 0 && nums[deque.Last.Value] < nums[i])
                    deque.RemoveLast();

                deque.AddLast(i);
            }

            result.Add(nums[deque.First.Value]);

            for (int i = k; i < nums.Length; i++)
            {
                while (deque.Count > 0 && nums[deque.Last.Value] < nums[i])
                    deque.RemoveLast();

                deque.AddLast(i);

                while (deque.First.Value <= i - k)
                    deque.RemoveFirst();

                result.Add(nums[deque.First.Value]);
            }

            return result.ToArray();
        }
    }
}
