using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Stack
{
    public class Daily_Temperatures
    {
        public int[] DailyTemperatures(int[] temperatures)
        {
            int[] res = new int[temperatures.Length];
            Stack<int> indxCount = new Stack<int>();

            for (int i = 0; i < temperatures.Length; i++)
            {
                while (indxCount.Count > 0 && temperatures[indxCount.Peek()] < temperatures[i])
                    res[indxCount.Peek()] = i - indxCount.Pop();

                indxCount.Push(i);
            }

            return res;
        }
    }
}
