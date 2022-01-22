using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Stack
{
    public class Max_Chunks_To_Make_Sorted
    {
        public int MaxChunksToSorted(int[] arr)
        {
            Stack<int> stk = new Stack<int>();

            foreach (int item in arr)
            {
                if (stk.Count > 0)
                {
                    if (item > stk.Peek())
                        stk.Push(item);

                    else
                    {
                        int max = -1, val = item;
                        while (stk.Count > 0 && item < stk.Peek())
                            max = Math.Max(max, stk.Pop());

                        stk.Push(max);
                    }
                }
                else
                    stk.Push(item);
            }

            return stk.Count;
        }
    }
}
