using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Stack
{
    public class Next_Greater_Element_II
    {
        public int[] nextGreaterElements(int[] nums)
        {
            Stack<int> maxNums = new Stack<int>();
            int[] res = new int[nums.Length];

            for (int i = 0; i < nums.Length; i++)
                res[i] = -1;

            for (int i = 0; i < nums.Length; i++)
            {
                while (maxNums.Count > 0 && nums[maxNums.Peek()] < nums[i])
                    res[maxNums.Pop()] = nums[i];
                
                maxNums.Push(i);
            }

            for (int i = 0; i < nums.Length; i++)
            {
                while (maxNums.Count > 0 && nums[maxNums.Peek()] < nums[i])
                    res[maxNums.Pop()] = nums[i];

                if (maxNums.Count == 0)
                    break;

                maxNums.Push(i);
            }

            return res;
        }
    }
}
