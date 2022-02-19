using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Stack
{
    // 496
    public class Next_Greater_Element_I
    {
        public int[] NextGreaterElement(int[] nums1, int[] nums2)
        {
            Dictionary<int, int> dict = new Dictionary<int, int>();
            int[] res = new int[nums1.Length];
            Stack<int> stack = new Stack<int>();

            for (int i = 0; i < nums2.Length; i++)
            {
                while (stack.Count > 0 && nums2[stack.Peek()] < nums2[i])
                    dict.Add(nums2[stack.Pop()], nums2[i]);

                stack.Push(i);
            }

            for (int i=0; i < nums1.Length; i++)
            {
                if (dict.ContainsKey(nums1[i]))
                    res[i] = dict[nums1[i]];
                else
                    res[i] = -1;
            }

            return res;
        }
    }
}
