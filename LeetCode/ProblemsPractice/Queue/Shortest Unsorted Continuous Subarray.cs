using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Queue
{
    // 581
    public class Shortest_Unsorted_Continuous_Subarray
    {
        public int FindUnsortedSubarray(int[] nums)
        {
            int minIndx = int.MaxValue;
            int maxIndx = int.MinValue;
            int IndxOfMinVal = int.MaxValue;
            Stack<int> stk = new Stack<int>();

            for (int i = nums.Length-1; i >= 0; i--)
            {
                if (stk.Count > 0 && nums[stk.Peek()] < nums[i])
                {
                    IndxOfMinVal = stk.Peek();
                    while (stk.Count > 0 && nums[stk.Peek()] < nums[i])
                    {
                        maxIndx = Math.Max(maxIndx, stk.Pop());
                        minIndx = Math.Min(minIndx, i);
                    }
                    stk.Push(i);
                    stk.Push(IndxOfMinVal);
                }
                
                else
                    stk.Push(i);
            }

            Console.WriteLine($"maxIndex = {maxIndx} and minIndex = {minIndx}");
            return (maxIndx == int.MinValue || minIndx == int.MaxValue) ? 0 : maxIndx - minIndx + 1;
        }
    }
}
