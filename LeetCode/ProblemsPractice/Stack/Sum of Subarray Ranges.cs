using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Stack
{
    public class Sum_of_Subarray_Ranges
    {
        public long SubArrayRanges(int[] A)
        {
            int n = A.Length, j, k;
            long res = 0;

            Stack<int> s = new Stack<int>();
            for (int i = 0; i <= n; i++)
            {
                while (s.Count > 0 && A[s.Peek()] > (i == n ? int.MinValue : A[i]))
                {
                    j = s.Pop();
                    k = s.Count == 0 ? -1 : s.Peek();
                    res -= (long)A[j] * (i - j) * (j - k);

                }
                s.Push(i);
            }

            s.Clear();
            for (int i = 0; i <= n; i++)
            {
                while (s.Count > 0 && A[s.Peek()] < (i == n ? int.MaxValue : A[i]))
                {
                    j = s.Pop();
                    k = s.Count == 0 ? -1 : s.Peek();
                    res += (long)A[j] * (i - j) * (j - k);

                }
                s.Push(i);
            }
            return res;
        }
    }
}
